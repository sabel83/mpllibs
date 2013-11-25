#ifndef MPLLIBS_METAMONAD_V1_IMPL_EVAL_SYNTAX_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_EVAL_SYNTAX_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class E>
        struct eval_syntax_impl;

        template <class E>
        struct eval_syntax_impl<syntax<E> > : E {};
      }
    }
  }
}

#endif

