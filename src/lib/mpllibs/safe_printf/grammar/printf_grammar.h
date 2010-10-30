#ifndef MPLLIBS_PRINTF_PRINTF_GRAMMAR_H
#define MPLLIBS_PRINTF_PRINTF_GRAMMAR_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/expect.h>

#include <mpllibs/metaparse/always.h>
#include <mpllibs/metaparse/any.h>
#include <mpllibs/metaparse/any1.h>
#include <mpllibs/metaparse/digit.h>
#include <mpllibs/metaparse/except.h>
#include <mpllibs/metaparse/first_of.h>
#include <mpllibs/metaparse/second_of.h>
#include <mpllibs/metaparse/lit_c.h>
#include <mpllibs/metaparse/one_char.h>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace grammar
    {
      struct NormalChars :
        mpllibs::metaparse::any<
          mpllibs::metaparse::second_of<
            mpllibs::metaparse::except<
              mpllibs::metaparse::lit_c<'%'>, int>,
              mpllibs::metaparse::one_char
          >
        >
      {};

      struct Flag :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::lit_c<'-'>,
          mpllibs::metaparse::lit_c<'+'>,
          mpllibs::metaparse::lit_c<' '>,
          mpllibs::metaparse::lit_c<'#'>,
          mpllibs::metaparse::lit_c<'0'>
        >
      {};

      struct Integer : mpllibs::metaparse::any1<mpllibs::metaparse::digit> {};
    
      // Returns true_ or false_
      struct Width :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::always<Integer, boost::mpl::false_>,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'*'>,
            boost::mpl::true_
          >,
          mpllibs::metaparse::return_<boost::mpl::false_>
        >
      {};

      // Returns true_ or false_
      struct Precision :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::second_of<mpllibs::metaparse::lit_c<'.'>, Width>,
          mpllibs::metaparse::return_<boost::mpl::false_>
        >
      {};

      struct Format_NoFlag :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'c'>,
            ExpectCharacter
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'d'>,
            ExpectSignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'i'>,
            ExpectSignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'e'>,
            ExpectDouble
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'E'>,
            ExpectDouble
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'f'>,
            ExpectDouble
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'g'>,
            ExpectDouble
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'G'>,
            ExpectDouble
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'o'>,
            ExpectSignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'s'>,
            ExpectString
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'u'>,
            ExpectUnsignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'x'>,
            ExpectUnsignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'X'>,
            ExpectUnsignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'p'>,
            ExpectPointer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'n'>,
            ExpectSignedIntPointer
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'%'>,
            ExpectNothing
          >
        >
      {};

      struct Format_hFlag :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'d'>,
            ExpectShortSignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'i'>,
            ExpectShortSignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'o'>,
            ExpectShortSignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'u'>,
            ExpectShortUnsignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'x'>,
            ExpectShortUnsignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'X'>,
            ExpectShortUnsignedInteger
          >
        >
      {};

      struct Format_lFlag :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'c'>,
            ExpectWideCharacter
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'d'>,
            ExpectLongSignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'i'>,
            ExpectLongSignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'o'>,
            ExpectLongSignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'s'>,
            ExpectWideCharacterString
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'u'>,
            ExpectLongUnsignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'x'>,
            ExpectLongUnsignedInteger
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'X'>,
            ExpectLongUnsignedInteger
          >
        >
      {};

      struct Format_LFlag :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'e'>,
            ExpectLongDouble
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'E'>,
            ExpectLongDouble
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'f'>,
            ExpectLongDouble
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'g'>,
            ExpectLongDouble
          >,
          mpllibs::metaparse::always<
            mpllibs::metaparse::lit_c<'G'>,
            ExpectLongDouble
          >
        >
      {};

      struct Format :
        mpllibs::metaparse::one_of<
          mpllibs::metaparse::second_of<
            mpllibs::metaparse::lit_c<'h'>,
            Format_hFlag
          >,
          mpllibs::metaparse::second_of<
            mpllibs::metaparse::lit_c<'l'>,
            Format_lFlag
          >,
          mpllibs::metaparse::second_of<
            mpllibs::metaparse::lit_c<'L'>,
            Format_LFlag
          >,
          Format_NoFlag
        >
      {};

      // returns pair<defined extra int, pair<defined extra int, format> >
      struct Parameter :
        mpllibs::metaparse::second_of<
          mpllibs::metaparse::lit_c<'%'>,
          mpllibs::metaparse::second_of<
            mpllibs::metaparse::any<Flag>,
            mpllibs::metaparse::sequence<
              Width,
              mpllibs::metaparse::sequence<Precision, Format>
            >
          >
        >
      {};

      struct S :
        mpllibs::metaparse::second_of<
          NormalChars,
          mpllibs::metaparse::any<
            mpllibs::metaparse::first_of<Parameter, NormalChars>
          >
        >
      {};
    }
  }
}

#endif

