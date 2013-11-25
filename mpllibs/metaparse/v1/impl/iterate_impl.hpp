#ifndef MPLLIBS_METAPARSE_V1_IMPL_ITERATE_IMPL_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_ITERATE_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/impl/iterate_impl_unchecked.hpp>
#include <mpllibs/metaparse/v1/return_.hpp>
#include <mpllibs/metaparse/v1/is_error.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        template <int N, class P, class Accum>
        struct iterate_impl
        {
          typedef iterate_impl type;
          
          template <class S, class Pos>
          struct apply :
            boost::mpl::eval_if<
              typename is_error<boost::mpl::apply<P, S, Pos> >::type,
              boost::mpl::apply<P, S, Pos>,
              iterate_impl_unchecked<N, P, Accum, S, Pos>
            >
          {};
        };
        
        template <class P, class Accum>
        struct iterate_impl<0, P, Accum> : return_<Accum> {};
      }
    }
  }
}

#endif

