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
    struct VerifyArgumentImpl<ExpectCharacter, char> : boost::mpl::true_ {};

    template <>
    struct VerifyArgumentImpl<ExpectUnsignedCharacter, unsigned char> :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<ExpectString, char*> : boost::mpl::true_ {};

    template <>
    struct VerifyArgumentImpl<ExpectString, const char*> : boost::mpl::true_ {};

    template <>
    struct VerifyArgumentImpl<ExpectSignedInteger, int> : boost::mpl::true_ {};

    template <>
    struct VerifyArgumentImpl<ExpectUnsignedInteger, unsigned int> :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<ExpectShortSignedInteger, short> :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<ExpectShortUnsignedInteger, unsigned short> :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<ExpectLongSignedInteger, long> : boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<ExpectLongUnsignedInteger, unsigned long> :
      boost::mpl::true_
    {};

    template <>
    struct VerifyArgumentImpl<ExpectFloat, float> : boost::mpl::true_ {};

    template <>
    struct VerifyArgumentImpl<ExpectDouble, double> : boost::mpl::true_ {};

    template <>
    struct VerifyArgumentImpl<ExpectLongDouble, long double> : boost::mpl::true_
    {};

    template <class T>
    struct VerifyArgumentImpl<ExpectPointer, T*> : boost::mpl::true_ {};

    template <class T>
    struct VerifyArgumentImpl<ExpectPointer, const T*> : boost::mpl::true_ {};

    template <>
    struct VerifyArgumentImpl<ExpectSignedIntPointer, int*> : boost::mpl::true_
    {};
  }
}

#endif


