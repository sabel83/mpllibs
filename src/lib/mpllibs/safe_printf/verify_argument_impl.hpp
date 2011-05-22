#ifndef MPLLIBS_PRINTF_VERIFY_ARGUMENT_IMPL_H
#define MPLLIBS_PRINTF_VERIFY_ARGUMENT_IMPL_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/expect.hpp>

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    template <class Expected, class Actual>
    struct verify_argument_impl : boost::mpl::false_ {};

    template <>
    struct verify_argument_impl<expect_character, char> : boost::mpl::true_ {};

    template <>
    struct verify_argument_impl<expect_unsigned_character, unsigned char> :
      boost::mpl::true_
    {};

    template <>
    struct verify_argument_impl<expect_string, char*> : boost::mpl::true_ {};

    template <>
    struct verify_argument_impl<expect_string, const char*> :
      boost::mpl::true_
    {};

    template <>
    struct verify_argument_impl<expect_signed_integer, int> :
      boost::mpl::true_
    {};

    template <>
    struct verify_argument_impl<expect_unsigned_integer, unsigned int> :
      boost::mpl::true_
    {};

    template <>
    struct verify_argument_impl<expect_short_signed_integer, short> :
      boost::mpl::true_
    {};

    template <>
    struct verify_argument_impl<expect_short_unsigned_integer, unsigned short> :
      boost::mpl::true_
    {};

    template <>
    struct verify_argument_impl<expect_long_signed_integer, long> :
      boost::mpl::true_
    {};

    template <>
    struct verify_argument_impl<expect_long_unsigned_integer, unsigned long> :
      boost::mpl::true_
    {};

    template <>
    struct verify_argument_impl<expect_float, float> : boost::mpl::true_ {};

    template <>
    struct verify_argument_impl<expect_double, double> : boost::mpl::true_ {};

    template <>
    struct verify_argument_impl<expect_long_double, long double> :
      boost::mpl::true_
    {};

    template <class T>
    struct verify_argument_impl<expect_pointer, T*> : boost::mpl::true_ {};

    template <class T>
    struct verify_argument_impl<expect_pointer, const T*> :
      boost::mpl::true_
    {};

    template <>
    struct verify_argument_impl<expect_signed_int_pointer, int*> :
      boost::mpl::true_
    {};
  }
}

#endif


