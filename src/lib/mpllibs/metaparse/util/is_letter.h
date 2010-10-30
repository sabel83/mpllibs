#ifndef MPLLIBS_UTIL_IS_LETTER_H
#define MPLLIBS_UTIL_IS_LETTER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_ucase_letter.h>
#include <mpllibs/metaparse/util/is_lcase_letter.h>

#include <boost/mpl/or.hpp>
#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      struct is_letter
      {
        template <class S>
        struct apply :
          boost::mpl::or_<
            boost::mpl::apply<mpllibs::metaparse::util::is_lcase_letter, S>,
            boost::mpl::apply<mpllibs::metaparse::util::is_ucase_letter, S>
          >
        {};
      };
    }
  }
}

#endif

