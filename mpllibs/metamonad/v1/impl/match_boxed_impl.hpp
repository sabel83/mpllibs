#ifndef MPLLIBS_METAMONAD_V1_IMPL_MATCH_BOXED_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_MATCH_BOXED_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/lazy_match_c_impl.hpp>
#include <mpllibs/metamonad/v1/impl/merge_map.hpp>
#include <mpllibs/metamonad/v1/is_exception.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>
#include <mpllibs/metamonad/v1/unbox.hpp>
#include <mpllibs/metamonad/v1/lambda_c.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>

#include <boost/mpl/map.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/zip_view.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        // Elements of Ps and Vs are boxed because Ps or Vs may contain mpl::na
        // in which case Ps and Vs have different sizes and zip_view can not
        // handle that.
        MPLLIBS_V1_METAFUNCTION(match_boxed_impl, (Ps)(Vs))
        ((
          boost::mpl::fold<
            boost::mpl::zip_view<boost::mpl::vector<Ps, Vs> >,
            boost::mpl::map<>,
            lambda_c<s, p,
              if_<
                is_exception<s>,
                s,
                merge_map<
                  s,
                  impl::lazy_match_c_impl<
                    unbox<boost::mpl::front<p> >,
                    unbox<boost::mpl::back<p> >
                  >
                >
              >
            >
          >
        ));
      }
    }
  }
}

#endif

