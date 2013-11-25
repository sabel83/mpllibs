#ifndef MPLLIBS_METAMONAD_V1_IMPL_MERGE_MAP_VALUE_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_MERGE_MAP_VALUE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/exception.hpp>
#include <mpllibs/metamonad/v1/impl/map_insert.hpp>
#include <mpllibs/metamonad/v1/is_exception.hpp>
#include <mpllibs/metamonad/v1/lazy.hpp>
#include <mpllibs/metamonad/v1/already_lazy.hpp>
#include <mpllibs/metamonad/v1/lazy_protect_args.hpp>
#include <mpllibs/metamonad/v1/lambda_c.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/first.hpp>
#include <mpllibs/metamonad/v1/second.hpp>
#include <mpllibs/metamonad/v1/is_same.hpp>
#include <mpllibs/metamonad/v1/bad_match.hpp>

#include <boost/mpl/has_key.hpp>
#include <boost/mpl/at.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        typedef
          lambda_c<s, p,
            if_<
              is_exception<s>,
              s,
              if_<
                lazy<
                  boost::mpl::has_key<
                    already_lazy<s>,
                    lazy_protect_args<first<p> >
                  >
                >,
                if_<
                  is_same<
                    lazy<
                      boost::mpl::at<
                        already_lazy<s>,
                        lazy_protect_args<first<p> >
                      >
                    >,
                    second<p>
                  >,
                  s,
                  exception<bad_match<first<p>, second<p> > >
                >,
                map_insert<s, p>
              >
            >
          >
          merge_map_value;
      }
    }
  }
}

#endif

