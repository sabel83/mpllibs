#ifndef MPLLIBS_METAPARSE_UTIL_IS_LCASE_LETTER_HPP
#define MPLLIBS_METAPARSE_UTIL_IS_LCASE_LETTER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/in_range.hpp>

#include <boost/mpl/char.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      typedef
        in_range<boost::mpl::char_<'a'>, boost::mpl::char_<'z'> >
        is_lcase_letter;
    }
  }
}

#endif

