#ifndef MPLLIBS_PRINTF_VERIFY_ARGUMENT_IMPL_H
#define MPLLIBS_PRINTF_VERIFY_ARGUMENT_IMPL_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/expect.h>
#include <mpllibs/safe_printf/Accept.h>

namespace mpllibs
{
  namespace safe_printf
  {
    template <class Expected, class Actual>
    struct VerifyArgumentImpl : boost::mpl::identity<boost::mpl::false_> {};

    template <>
    struct VerifyArgumentImpl<ExpectCharacter, char> :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<
      ExpectUnsignedCharacter,
      unsigned char
    > :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<ExpectString, char*> :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<ExpectString, const char*> :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<ExpectSignedInteger, int> :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<
      ExpectUnsignedInteger,
      unsigned int
    > :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<ExpectShortSignedInteger, short> :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<
      ExpectShortUnsignedInteger,
      unsigned short
    > :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<ExpectLongSignedInteger, long> :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<
      ExpectLongUnsignedInteger,
      unsigned long
    > :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<ExpectFloat, float> :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<ExpectDouble, double> :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<ExpectLongDouble, long double> :
      Accept
    {};

    template <class T>
    struct VerifyArgumentImpl<ExpectPointer, T*> :
      Accept
    {};

    template <class T>
    struct VerifyArgumentImpl<ExpectPointer, const T*> :
      Accept
    {};

    template <>
    struct VerifyArgumentImpl<ExpectSignedIntPointer, int*> :
      Accept
    {};
  }
}

#endif


