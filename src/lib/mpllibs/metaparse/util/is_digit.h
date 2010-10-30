#ifndef MPLLIBS_UTIL_IS_DIGIT_H
#define MPLLIBS_UTIL_IS_DIGIT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/in_range.h>

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      typedef
        mpllibs::metaparse::util::in_range<
          boost::mpl::integral_c<char, '0'>,
          boost::mpl::integral_c<char, '9'>
        >
        is_digit;
    }
  }
}

#endif

