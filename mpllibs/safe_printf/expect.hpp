#ifndef MPLLIBS_SAFE_PRINTF_EXPECT_HPP
#define MPLLIBS_SAFE_PRINTF_EXPECT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/meta_atom.hpp>
#include <mpllibs/metamonad/tag_tag.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    MPLLIBS_DEFINE_TAG(expectation_tag);
  
    // Expected argument types
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_character);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_unsigned_character);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_string);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_wide_character);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_wide_character_string);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_signed_integer);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_unsigned_integer);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_short_signed_integer);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_short_unsigned_integer);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_long_signed_integer);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_long_unsigned_integer);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_float);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_double);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_long_double);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_pointer);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_signed_int_pointer);
    MPLLIBS_DEFINE_META_ATOM(expectation_tag, expect_nothing); // To handle %%
  }
}

#endif

