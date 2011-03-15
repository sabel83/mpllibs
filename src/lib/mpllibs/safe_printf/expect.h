#ifndef MPLLIBS_PRINTF_EXPECT_H
#define MPLLIBS_PRINTF_EXPECT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/define_data.h>

namespace mpllibs
{
  namespace safe_printf
  {
    // Expected argument types
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectCharacter);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectUnsignedCharacter);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectString);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectWideCharacter);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectWideCharacterString);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectSignedInteger);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectUnsignedInteger);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectShortSignedInteger);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectShortUnsignedInteger);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectLongSignedInteger);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectLongUnsignedInteger);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectFloat);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectDouble);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectLongDouble);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectPointer);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectSignedIntPointer);
    MPLLIBS_METAPARSE_DEFINE_DATA(ExpectNothing); // To handle %%
  }
}

#endif

