#ifndef MPLLIBS_METAMONAD_V1_IMPL_STRICT_IS_EXCEPTION_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_STRICT_IS_EXCEPTION_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/exception.hpp>

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      // Exceptions are used in the implementation of pattern matching
      namespace impl
      {
        template <class T>
        struct strict_is_exception : boost::mpl::false_ {};

        template <class T>
        struct strict_is_exception<exception<T> > : boost::mpl::true_ {};
      }
    }
  }
}

#endif

