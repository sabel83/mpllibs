#ifndef MPLLIBS_PRINTF_PRINTF_GRAMMAR_H
#define MPLLIBS_PRINTF_PRINTF_GRAMMAR_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/expect.hpp>

#include <mpllibs/metaparse/always.hpp>
#include <mpllibs/metaparse/any.hpp>
#include <mpllibs/metaparse/any1.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/except.hpp>
#include <mpllibs/metaparse/first_of.hpp>
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/one_of.hpp>

#include <mpllibs/metaparse/util/define_data.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace errors
    {
      MPLLIBS_METAPARSE_DEFINE_DATA(no_percentage_char_expected);
    }
  
    namespace grammar
    {
      struct normal_chars :
        mpllibs::metaparse::any<
          mpllibs::metaparse::last_of<
            mpllibs::metaparse::except<
              mpllibs::metaparse::lit_c<'%'>,
              boost::mpl::void_,
              mpllibs::safe_printf::errors::no_percentage_char_expected
            >,
            mpllibs::metaparse::one_char
          >
        >
      {};

      struct flag :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::lit_c<'-'>,
          mpllibs::metaparse::lit_c<'+'>,
          mpllibs::metaparse::lit_c<' '>,
          mpllibs::metaparse::lit_c<'#'>,
          mpllibs::metaparse::lit_c<'0'>
        >
      {};

      struct integer : mpllibs::metaparse::any1<mpllibs::metaparse::digit> {};
    
      // Returns true_ or false_
      struct width :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::always<integer, boost::mpl::false_>,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'*'>,
            boost::mpl::true_
          >,
          mpllibs::metaparse::return_<boost::mpl::false_>
        >
      {};

      // Returns true_ or false_
      struct precision :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::last_of<mpllibs::metaparse::lit_c<'.'>, width>,
          mpllibs::metaparse::return_<boost::mpl::false_>
        >
      {};

      struct format_no_flag :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'c'>,
            expect_character
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'d'>,
            expect_signed_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'i'>,
            expect_signed_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'e'>,
            expect_double
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'E'>,
            expect_double
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'f'>,
            expect_double
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'g'>,
            expect_double
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'G'>,
            expect_double
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'o'>,
            expect_signed_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'s'>,
            expect_string
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'u'>,
            expect_unsigned_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'x'>,
            expect_unsigned_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'X'>,
            expect_unsigned_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'p'>,
            expect_pointer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'n'>,
            expect_signed_int_pointer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'%'>,
            expect_nothing
          >
        >
      {};

      struct format_h_flag :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'d'>,
            expect_short_signed_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'i'>,
            expect_short_signed_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'o'>,
            expect_short_signed_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'u'>,
            expect_short_unsigned_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'x'>,
            expect_short_unsigned_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'X'>,
            expect_short_unsigned_integer
          >
        >
      {};

      struct format_l_flag :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'c'>,
            expect_wide_character
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'d'>,
            expect_long_signed_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'i'>,
            expect_long_signed_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'o'>,
            expect_long_signed_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'s'>,
            expect_wide_character_string
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'u'>,
            expect_long_unsigned_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'x'>,
            expect_long_unsigned_integer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'X'>,
            expect_long_unsigned_integer
          >
        >
      {};

      struct format_capital_l_flag :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'e'>,
            expect_long_double
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'E'>,
            expect_long_double
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'f'>,
            expect_long_double
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'g'>,
            expect_long_double
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'G'>,
            expect_long_double
          >
        >
      {};

      struct format :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::last_of<
            mpllibs::metaparse::lit_c<'h'>,
            format_h_flag
          >,
          mpllibs::metaparse::last_of<
            mpllibs::metaparse::lit_c<'l'>,
            format_l_flag
          >,
          mpllibs::metaparse::last_of<
            mpllibs::metaparse::lit_c<'L'>,
            format_capital_l_flag
          >,
          format_no_flag
        >
      {};

      // returns deque<defined extra int, defined extra int, format>
      struct parameter :
        mpllibs::metaparse::last_of<
          mpllibs::metaparse::lit_c<'%'>,
          mpllibs::metaparse::any<flag>,
          mpllibs::metaparse::sequence<width, precision, format>
        >
      {};

      struct S :
        mpllibs::metaparse::last_of<
          normal_chars,
          mpllibs::metaparse::any<
            mpllibs::metaparse::first_of<parameter, normal_chars>
          >
        >
      {};
    }
  }
}

#endif

