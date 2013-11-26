#ifndef MPLLIBS_METAPARSE_V1_IMPL_ITERATE_IMPL_UNCHECKED_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_ITERATE_IMPL_UNCHECKED_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/impl/fwd/iterate_impl.hpp>
#include <mpllibs/metaparse/v1/get_result.hpp>
#include <mpllibs/metaparse/v1/get_remaining.hpp>
#include <mpllibs/metaparse/v1/get_position.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/push_back.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        template <int N, class P, class Accum, class S, class Pos>
        struct iterate_impl_unchecked :
          boost::mpl::apply_wrap2<
            iterate_impl<
              N - 1,
              P,
              typename boost::mpl::push_back<
                Accum,
                typename get_result<boost::mpl::apply<P, S, Pos> >::type
              >::type
            >,
            typename get_remaining<boost::mpl::apply<P, S, Pos> >::type,
            typename get_position<boost::mpl::apply<P, S, Pos> >::type
          >
        {};
      }
    }
  }
}

#endif

