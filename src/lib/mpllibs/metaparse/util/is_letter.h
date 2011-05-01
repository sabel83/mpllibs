#ifndef MPLLIBS_UTIL_IS_LETTER_H
#define MPLLIBS_UTIL_IS_LETTER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_ucase_letter.h>
#include <mpllibs/metaparse/util/is_lcase_letter.h>

#include <mpllibs/metatest/to_stream.h>

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
            boost::mpl::apply<is_lcase_letter, S>,
            boost::mpl::apply<is_ucase_letter, S>
          >
        {};
      };
    }
  }
}

DEFINE_TO_STREAM_FOR_TYPE(mpllibs::metaparse::util::is_letter, "is_letter")

#endif

