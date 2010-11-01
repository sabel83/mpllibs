#ifndef MPLLIBS_UTIL_UNLESS_NOTHING_H
#define MPLLIBS_UTIL_UNLESS_NOTHING_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/is_nothing.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      template <class t, class not_nothing_case>
      struct unless_nothing :
        boost::mpl::eval_if<
          typename mpllibs::metaparse::util::is_nothing<t>::type,
          mpllibs::metaparse::nothing,
          not_nothing_case
        >
      {};
    }
  }
}

#endif

