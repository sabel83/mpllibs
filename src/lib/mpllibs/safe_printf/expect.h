#ifndef MPLLIBS_PRINTF_EXPECT_H
#define MPLLIBS_PRINTF_EXPECT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mpllibs
{
  namespace safe_printf
  {
    // Expected argument types
    struct ExpectCharacter;
    struct ExpectUnsignedCharacter;
    struct ExpectString;
    struct ExpectWideCharacter;
    struct ExpectWideCharacterString;
    struct ExpectSignedInteger;
    struct ExpectUnsignedInteger;
    struct ExpectShortSignedInteger;
    struct ExpectShortUnsignedInteger;
    struct ExpectLongSignedInteger;
    struct ExpectLongUnsignedInteger;
    struct ExpectFloat;
    struct ExpectDouble;
    struct ExpectLongDouble;
    struct ExpectPointer;
    struct ExpectSignedIntPointer;
    struct ExpectNothing; // To handle %%
  }
}

#endif

