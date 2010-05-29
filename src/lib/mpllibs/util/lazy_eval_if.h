#ifndef MPLLIBS_UTIL_LAZY_EVAL_IF
#define MPLLIBS_UTIL_LAZY_EVAL_IF

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace util
  {
    // Accepts nullary metafunction as condition
    template <class c, class t, class f>
    struct lazy_eval_if : boost::mpl::eval_if<typename c::type, t, f> {};
  }
}

#endif

