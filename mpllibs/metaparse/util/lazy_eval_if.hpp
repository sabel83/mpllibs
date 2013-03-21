#ifndef MPLLIBS_METAPARSE_UTIL_LAZY_EVAL_IF_HPP
#define MPLLIBS_METAPARSE_UTIL_LAZY_EVAL_IF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/eval_if.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      // Accepts nullary metafunction as condition
      template <class C, class T, class F>
      struct lazy_eval_if : boost::mpl::eval_if<typename C::type, T, F> {};
    }
  }
}

#endif

