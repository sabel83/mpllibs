#ifndef MPLLIBS_PARSER_SPACE_H
#define MPLLIBS_PARSER_SPACE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/accept_when.h>
#include <mpllibs/parser/one_char.h>

#include <mpllibs/util/is_whitespace.h>

namespace mpllibs
{
  namespace parser
  {
    typedef
      mpllibs::parser::accept_when<
        mpllibs::parser::one_char,
        mpllibs::util::is_whitespace
      >
      space;
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace mpllibs_parser_test_space
  {
    namespace
    {
      typedef boost::mpl::list_c<char, ' ', 'e', 'l', 'l', 'o'> spaceString;
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
      typedef boost::mpl::list_c<char> emptyString;
      
      struct TestWithText :
        mpllibs::test::test_equal<
          mpllibs::parser::space::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};    

      struct TestWithSpace :
        mpllibs::test::test_equal<
          mpllibs::parser::space::apply<spaceString>::type::first,
          boost::mpl::integral_c<char, ' '>
        >
      {};    

      struct TestWithEmptyString :
        mpllibs::test::test_equal<
          mpllibs::parser::space::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};    
    }
  }
}
#endif

#endif

