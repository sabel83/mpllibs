#ifndef MPLLIBS_METAMONAD_IS_EXCEPTION_HPP
#define MPLLIBS_METAMONAD_IS_EXCEPTION_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/exception_core.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    // Exceptions are used in the implementation of pattern matching
    namespace impl
    {
      template <class T>
      struct strict_is_exception : boost::mpl::false_ {};

      template <class T>
      struct strict_is_exception<exception<T> > : boost::mpl::true_ {};
    }

    MPLLIBS_LAZY_METAFUNCTION(is_exception, (T))
    ((impl::strict_is_exception<T>));
  }
}

#endif

