#ifndef MPLLIBS_METAMONAD_EVAL_SYNTAX_HPP
#define MPLLIBS_METAMONAD_EVAL_SYNTAX_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      template <class E>
      struct eval_syntax_impl;

      template <class E>
      struct eval_syntax_impl<syntax<E> > : E {};
    }

    // MPLLIBS_METAFUNCTION depends on it
    template <class E>
    struct eval_syntax : impl::eval_syntax_impl<typename E::type> {};
  }
}

#endif

