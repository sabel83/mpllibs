#ifndef MPLLIBS_SAFE_PRINTF_IMPL_VERIFY_ARGUMENT_IMPL_HPP
#define MPLLIBS_SAFE_PRINTF_IMPL_VERIFY_ARGUMENT_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/impl/any_type.hpp>

#include <boost/mpl/bool.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_cv.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace impl
    {
      template <class Expected, class Actual>
      struct verify_argument_impl :
        boost::is_same<
          typename boost::remove_cv<Expected>::type,
          typename boost::remove_cv<Actual>::type
        >
      {};

      template <class T>
      struct verify_argument_impl<any_type, T> : boost::mpl::true_ {};

      template <class T, class U>
      struct verify_argument_impl<T*, U*> : verify_argument_impl<T, U> {};
    }
  }
}

#endif


