#ifndef SAFE_PRINTF_EXPECT_HPP
#define SAFE_PRINTF_EXPECT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

namespace safe
{
  struct expectation_tag : mpllibs::metamonad::tmp_tag<expectation_tag> {};

  // Expected argument types
  struct expect_character :
    mpllibs::metamonad::tmp_value<expect_character, expectation_tag>
  {};

  struct expect_unsigned_character :
    mpllibs::metamonad::tmp_value<expect_unsigned_character, expectation_tag>
  {};

  struct expect_string :
    mpllibs::metamonad::tmp_value<expect_string, expectation_tag>
  {};

  struct expect_wide_character :
    mpllibs::metamonad::tmp_value<expect_wide_character, expectation_tag>
  {};

  struct expect_wide_character_string :
    mpllibs::metamonad::tmp_value<expect_wide_character_string, expectation_tag>
  {};

  struct expect_signed_integer :
    mpllibs::metamonad::tmp_value<expect_signed_integer, expectation_tag>
  {};

  struct expect_unsigned_integer :
    mpllibs::metamonad::tmp_value<expect_unsigned_integer, expectation_tag>
  {};

  struct expect_short_signed_integer :
    mpllibs::metamonad::tmp_value<expect_short_signed_integer, expectation_tag>
  {};

  struct expect_short_unsigned_integer :
    mpllibs::metamonad::tmp_value<expect_short_unsigned_integer,expectation_tag>
  {};

  struct expect_long_signed_integer :
    mpllibs::metamonad::tmp_value<expect_long_signed_integer, expectation_tag>
  {};

  struct expect_long_unsigned_integer :
    mpllibs::metamonad::tmp_value<expect_long_unsigned_integer, expectation_tag>
  {};

  struct expect_float :
    mpllibs::metamonad::tmp_value<expect_float, expectation_tag>
  {};

  struct expect_double :
    mpllibs::metamonad::tmp_value<expect_double, expectation_tag>
  {};

  struct expect_long_double :
    mpllibs::metamonad::tmp_value<expect_long_double, expectation_tag>
  {};

  struct expect_pointer :
    mpllibs::metamonad::tmp_value<expect_pointer, expectation_tag>
  {};

  struct expect_signed_int_pointer :
    mpllibs::metamonad::tmp_value<expect_signed_int_pointer, expectation_tag>
  {};

  // To handle %%
  struct expect_nothing :
    mpllibs::metamonad::tmp_value<expect_nothing, expectation_tag>
  {};
}

#endif

