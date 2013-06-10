#ifndef MPLLIBS_METAPARSE_IMPL_REMOVE_TRAILING_NO_CHARS_HPP
#define MPLLIBS_METAPARSE_IMPL_REMOVE_TRAILING_NO_CHARS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/string_fwd.hpp>
#include <mpllibs/metaparse/impl/push_front_c.hpp>

#include <boost/mpl/clear.hpp>

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
        boost::mpl::clear<string<MPLLIBS_NO_CHAR, Cs...>>
      {};

      template <char C, char... Cs>
      struct remove_trailing_no_chars<string<C, Cs...>> :
        push_front_c<typename remove_trailing_no_chars<string<Cs...>>::type, C>
      {};
#endif
    }
  }
}

#endif

