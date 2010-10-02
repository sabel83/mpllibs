#ifndef MPLLIBS_PRINTF_PRINTF_GRAMMAR_H
#define MPLLIBS_PRINTF_PRINTF_GRAMMAR_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/printf/expect.h>

#include <mpllibs/parser/always.h>
#include <mpllibs/parser/any.h>
#include <mpllibs/parser/any1.h>
#include <mpllibs/parser/digit.h>
#include <mpllibs/parser/except.h>
#include <mpllibs/parser/first_of.h>
#include <mpllibs/parser/second_of.h>
#include <mpllibs/parser/lit_c.h>
#include <mpllibs/parser/one_char.h>

namespace mpllibs
{
  namespace printf
  {
    namespace grammar
    {
      struct NormalChars :
        mpllibs::parser::any<
          mpllibs::parser::second_of<
            mpllibs::parser::except<
              mpllibs::parser::lit_c<'%'>, int>,
              mpllibs::parser::one_char
          >
        >
      {};

      struct Flag :
        mpllibs::parser::one_of<
          mpllibs::parser::lit_c<'-'>,
          mpllibs::parser::lit_c<'+'>,
          mpllibs::parser::lit_c<' '>,
          mpllibs::parser::lit_c<'#'>,
          mpllibs::parser::lit_c<'0'>
        >
      {};

      struct Integer : mpllibs::parser::any1<mpllibs::parser::digit> {};
    
      // Returns true_ or false_
      struct Width :
        mpllibs::parser::one_of<
          mpllibs::parser::always<Integer, boost::mpl::false_>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'*'>, boost::mpl::true_>,
          mpllibs::parser::return_<boost::mpl::false_>
        >
      {};

      // Returns true_ or false_
      struct Precision :
        mpllibs::parser::one_of<
          mpllibs::parser::second_of<mpllibs::parser::lit_c<'.'>, Width>,
          mpllibs::parser::return_<boost::mpl::false_>
        >
      {};

      struct Format_NoFlag :
        mpllibs::parser::one_of<
          mpllibs::parser::always<mpllibs::parser::lit_c<'c'>, ExpectCharacter>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'d'>, ExpectSignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'i'>, ExpectSignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'e'>, ExpectDouble>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'E'>, ExpectDouble>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'f'>, ExpectDouble>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'g'>, ExpectDouble>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'G'>, ExpectDouble>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'o'>, ExpectSignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'s'>, ExpectString>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'u'>, ExpectUnsignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'x'>, ExpectUnsignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'X'>, ExpectUnsignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'p'>, ExpectPointer>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'n'>, ExpectSignedIntPointer>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'%'>, ExpectNothing>
        >
      {};

      struct Format_hFlag :
        mpllibs::parser::one_of<
          mpllibs::parser::always<mpllibs::parser::lit_c<'d'>, ExpectShortSignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'i'>, ExpectShortSignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'o'>, ExpectShortSignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'u'>, ExpectShortUnsignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'x'>, ExpectShortUnsignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'X'>, ExpectShortUnsignedInteger>
        >
      {};

      struct Format_lFlag :
        mpllibs::parser::one_of<
          mpllibs::parser::always<mpllibs::parser::lit_c<'c'>, ExpectWideCharacter>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'d'>, ExpectLongSignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'i'>, ExpectLongSignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'o'>, ExpectLongSignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'s'>, ExpectWideCharacterString>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'u'>, ExpectLongUnsignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'x'>, ExpectLongUnsignedInteger>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'X'>, ExpectLongUnsignedInteger>
        >
      {};

      struct Format_LFlag :
        mpllibs::parser::one_of<
          mpllibs::parser::always<mpllibs::parser::lit_c<'e'>, ExpectLongDouble>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'E'>, ExpectLongDouble>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'f'>, ExpectLongDouble>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'g'>, ExpectLongDouble>,
          mpllibs::parser::always<mpllibs::parser::lit_c<'G'>, ExpectLongDouble>
        >
      {};

      struct Format :
        mpllibs::parser::one_of<
          mpllibs::parser::second_of<mpllibs::parser::lit_c<'h'>, Format_hFlag>,
          mpllibs::parser::second_of<mpllibs::parser::lit_c<'l'>, Format_lFlag>,
          mpllibs::parser::second_of<mpllibs::parser::lit_c<'L'>, Format_LFlag>,
          Format_NoFlag
        >
      {};

      // returns pair<defined extra int, pair<defined extra int, format> >
      struct Parameter :
        mpllibs::parser::second_of<
          mpllibs::parser::lit_c<'%'>,
          mpllibs::parser::second_of<
            mpllibs::parser::any<Flag>,
            mpllibs::parser::sequence<
              Width,
              mpllibs::parser::sequence<Precision, Format>
            >
          >
        >
      {};

      struct S :
        mpllibs::parser::second_of<
          NormalChars,
          mpllibs::parser::any<
            mpllibs::parser::first_of<Parameter, NormalChars>
          >
        >
      {};
    }
  }
}

#endif

