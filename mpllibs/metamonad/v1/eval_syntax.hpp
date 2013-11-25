#ifndef MPLLIBS_METAMONAD_V1_EVAL_SYNTAX_HPP
#define MPLLIBS_METAMONAD_V1_EVAL_SYNTAX_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/eval_syntax.hpp>
#include <mpllibs/metamonad/v1/impl/eval_syntax_impl.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      // MPLLIBS_V1_METAFUNCTION depends on it
      template <class E>
      struct eval_syntax : impl::eval_syntax_impl<typename E::type> {};
    }
  }
}

#endif

