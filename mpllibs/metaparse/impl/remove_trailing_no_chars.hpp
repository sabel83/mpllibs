#ifndef MPLLIBS_METAPARSE_IMPL_REMOVE_TRAILING_NO_CHARS_HPP
#define MPLLIBS_METAPARSE_IMPL_REMOVE_TRAILING_NO_CHARS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/impl/string.hpp>
#include <mpllibs/metaparse/impl/push_front_c.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace impl
    {
      template <class S>
      struct remove_trailing_no_chars : S {};

#ifdef MPLLIBS_VARIADIC_STRING
      // this code assumes that MPLLIBS_NO_CHARs are at the end of the string
      template <char... Cs>
      struct remove_trailing_no_chars<string<MPLLIBS_NO_CHAR, Cs...>> :
        string<>
      {};

      template <char C, char... Cs>
      struct remove_trailing_no_chars<string<C, Cs...>> :
        push_front_c<typename remove_trailing_no_chars<string<Cs...>>::type, C>
      {};

#ifdef _MSC_VER
      /*
       * These specialisations are needed to avoid an internal compiler error
       * in Visual C++ 12
       */
      template <char C>
      struct remove_trailing_no_chars<string<C>> : string<C> {};

      template <>
      struct remove_trailing_no_chars<string<MPLLIBS_NO_CHAR>> : string<> {};

      template <>
      struct remove_trailing_no_chars<string<>> : string<> {};
#endif
#endif
    }
  }
}

#endif

