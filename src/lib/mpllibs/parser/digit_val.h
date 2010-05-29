#ifndef MPLLIBS_PARSER_DIGIT_VAL_H
#define MPLLIBS_PARSER_DIGIT_VAL_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/digit.h>
#include <mpllibs/parser/transform.h>

#include <mpllibs/util/digit_to_int.h>

namespace mpllibs
{
  namespace parser
  {
    typedef
      mpllibs::parser::transform<
        mpllibs::parser::digit,
        mpllibs::util::digit_to_int
      >
      digit_val;
  }
}

/*
 * Test code
 */
#ifdef MPLLIBS_PARSER_SELF_TEST

#include <mpllibs/parser/nothing.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/int.hpp>

namespace mpllibs
{
  namespace parser_test_digit_val
  {
    namespace
    {
      typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
      typedef boost::mpl::list_c<char, '1', '9', '8', '3'> numberString;
      typedef boost::mpl::list_c<char> emptyString;
      
      struct TestWithText :
        mpllibs::test::test_equal<
          mpllibs::parser::digit_val::apply<helloString>::type,
          mpllibs::parser::nothing
        >
      {};

      struct TestWithNumber :
        mpllibs::test::test_equal<
          mpllibs::parser::digit_val::apply<numberString>::type::first,
          boost::mpl::int_<1>
        >
      {};

      struct TestWithEmptyString :
        mpllibs::test::test_equal<
          mpllibs::parser::digit_val::apply<emptyString>::type,
          mpllibs::parser::nothing
        >
      {};
    }
  }
}
#endif

#endif

