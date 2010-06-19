#ifndef MPLLIBS_UTIL_IS_UCASE_LETTER_H
#define MPLLIBS_UTIL_IS_UCASE_LETTER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/in_range.h>

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace util
  {
    typedef
      mpllibs::util::in_range<
        boost::mpl::integral_c<char, 'A'>,
        boost::mpl::integral_c<char, 'Z'>
      >
      is_ucase_letter;
  }
}

#endif

