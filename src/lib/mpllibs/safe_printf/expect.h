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
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_character);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_unsigned_character);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_string);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_wide_character);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_wide_character_string);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_signed_integer);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_unsigned_integer);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_short_signed_integer);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_short_unsigned_integer);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_long_signed_integer);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_long_unsigned_integer);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_float);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_double);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_long_double);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_pointer);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_signed_int_pointer);
    MPLLIBS_METAPARSE_DEFINE_DATA(expect_nothing); // To handle %%
  }
}

#endif

