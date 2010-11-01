#ifndef MPLLIBS_PRINTF_VERIFY_ARGUMENT_IMPL_H
#define MPLLIBS_PRINTF_VERIFY_ARGUMENT_IMPL_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/expect.h>

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    template <class Expected, class Actual>
    struct VerifyArgumentImpl : boost::mpl::false_ {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectCharacter,
      char
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectUnsignedCharacter,
      unsigned char
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectString,
      char*
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectString,
      const char*
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectSignedInteger,
      int
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectUnsignedInteger,
      unsigned int
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectShortSignedInteger,
      short
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectShortUnsignedInteger,
      unsigned short
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectLongSignedInteger,
      long
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectLongUnsignedInteger,
      unsigned long
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectFloat,
      float
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectDouble,
      double
    > :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectLongDouble,
      long double
    > :
      boost::mpl::true_
    {};

    template <class T>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectPointer,
      T*
    > :
      boost::mpl::true_
    {};

    template <class T>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectPointer,
      const T*
    > :
      boost::mpl::true_ {};

    template <>
    struct VerifyArgumentImpl<
      mpllibs::safe_printf::ExpectSignedIntPointer,
      int*
    > :
      boost::mpl::true_
    {};
  }
}

#endif


