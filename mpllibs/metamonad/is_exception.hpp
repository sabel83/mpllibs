#ifndef MPLLIBS_METAMONAD_IS_EXCEPTION_HPP
#define MPLLIBS_METAMONAD_IS_EXCEPTION_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/exception_core.hpp>

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    // Exceptions are used in the implementation of pattern matching
    template <class T>
    struct is_exception : boost::mpl::false_ {};

    template <class T>
    struct is_exception<exception<T> > : boost::mpl::true_ {};
  }
}

#endif

