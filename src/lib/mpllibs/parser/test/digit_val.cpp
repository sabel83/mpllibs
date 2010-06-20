// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/digit_val.h>
#include <mpllibs/parser/nothing.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef boost::mpl::list_c<char, '1', '9', '8', '3'> numberString;
  typedef boost::mpl::list_c<char> emptyString;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit_val::apply<helloString>::type,
      mpllibs::parser::nothing
    >::type
    DigitVal_TestWithText;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit_val::apply<numberString>::type::first,
      boost::mpl::int_<1>
    >::type
    DigitVal_TestWithNumber;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit_val::apply<emptyString>::type,
      mpllibs::parser::nothing
    >::type
    DigitVal_TestWithEmptyString;
}

MPLLIBS_ADD_TEST(DigitVal_TestWithText)
MPLLIBS_ADD_TEST(DigitVal_TestWithNumber)
MPLLIBS_ADD_TEST(DigitVal_TestWithEmptyString)




