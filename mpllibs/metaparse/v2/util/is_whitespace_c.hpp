#ifndef MPLLIBS_METAPARSE_V2_UTIL_IS_WHITESPACE_C_HPP
#define MPLLIBS_METAPARSE_V2_UTIL_IS_WHITESPACE_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace util
      {
        template <char C>
        struct is_whitespace_c : boost::mpl::false_ {};

        template <> struct is_whitespace_c<' '> : boost::mpl::true_ {};
        template <> struct is_whitespace_c<'\r'> : boost::mpl::true_ {};
        template <> struct is_whitespace_c<'\n'> : boost::mpl::true_ {};
        template <> struct is_whitespace_c<'\t'> : boost::mpl::true_ {};
      }
    }
  }
}

#endif

