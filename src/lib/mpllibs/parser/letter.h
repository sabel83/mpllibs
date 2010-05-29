#ifndef MPLLIBS_PARSER_LETTER_H
#define MPLLIBS_PARSER_LETTER_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/accept_when.h>
#include <mpllibs/parser/one_char.h>

#include <mpllibs/util/is_letter.h>

namespace mpllibs
{
  namespace parser
  {
    typedef
      mpllibs::parser::accept_when<
        mpllibs::parser::one_char,
        mpllibs::util::is_letter
      >
      letter;
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace mpllibs_parser_test_letter
  {
    namespace
    {
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
      typedef boost::mpl::list_c<char, '1', '9', '8', '3'> numberString;
      typedef boost::mpl::list_c<char> emptyString;
      
      struct TestWithText :
        mpllibs::test::test_equal<
          mpllibs::parser::letter::apply<helloString>::type::first,
          boost::mpl::integral_c<char, 'h'>
        >
      {};    

      struct TestWithNumber :
        mpllibs::test::test_equal<
          mpllibs::parser::letter::apply<numberString>::type,
          mpllibs::parser::nothing
        >
      {};    

      struct TestWithEmptyString :
        mpllibs::test::test_equal<
          mpllibs::parser::letter::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};    
    }
  }
}
#endif

#endif

