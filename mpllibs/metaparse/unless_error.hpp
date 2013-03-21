#ifndef MPLLIBS_METAPARSE_UTIL_UNLESS_ERROR_HPP
#define MPLLIBS_METAPARSE_UTIL_UNLESS_ERROR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <class T, class NotErrorCase>
    struct unless_error :
      boost::mpl::eval_if<
        typename mpllibs::metaparse::is_error<T>::type,
        T,
        NotErrorCase
      >
    {};
  }
}

#endif

