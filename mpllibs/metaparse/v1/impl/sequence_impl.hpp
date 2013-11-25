#ifndef MPLLIBS_METAPARSE_V1_IMPL_SEQUENCE_IMPL_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_SEQUESEQUENCE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/impl/apply_parser.hpp>
#include <mpllibs/metaparse/v1/return_.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/fold.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        template <class Ps, class S, class Pos>
        struct sequence_impl :
          boost::mpl::fold<
            Ps,
            typename boost::mpl::apply_wrap2<
              return_<boost::mpl::deque<> >,
              S,
              Pos
            >::type,
            apply_parser
          >
        {};
      }
    }
  }
}

#endif

