#ifndef MPLLIBS_UTIL_IS_LETTER_H
#define MPLLIBS_UTIL_IS_LETTER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_ucase_letter.h>
#include <mpllibs/util/is_lcase_letter.h>

#include <boost/mpl/or.hpp>

namespace mpllibs
{
  namespace util
  {
    struct is_letter
    {
      template <class S>
      struct apply :
        boost::mpl::or_<
          mpllibs::util::is_lcase_letter::apply<S>,
          mpllibs::util::is_ucase_letter::apply<S>
        >
      {};
    };
  }
}

#endif

