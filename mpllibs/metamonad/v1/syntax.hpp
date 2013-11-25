#ifndef MPLLIBS_METAMONAD_V1_SYNTAX_HPP
#define MPLLIBS_METAMONAD_V1_SYNTAX_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/syntax.hpp>
#include <mpllibs/metamonad/v1/fwd/lazy.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>
#include <mpllibs/metamonad/v1/syntax_tag.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      // MPLLIBS_V1_METAFUNCTION depends on it
      template <class T>
      struct syntax : tmp_value<syntax<T>, syntax_tag> {};

      template <class T>
      struct lazy<syntax<T> > : syntax<T> {};
    }
  }
}

#endif

