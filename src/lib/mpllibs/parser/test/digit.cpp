// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/digit.h>
#include <mpllibs/parser/nothing.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/list_c.hpp>

namespace
{
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef boost::mpl::list_c<char, '1', '9', '8', '3'> numberString;
  typedef boost::mpl::list_c<char> emptyString;
      
  struct TestWithText :
    mpllibs::test::test_equal<
      mpllibs::parser::digit::apply<helloString>::type,
      mpllibs::parser::nothing
    >
  {};    

  struct TestWithNumber :
    mpllibs::test::test_equal<
      mpllibs::parser::digit::apply<numberString>::type::first,
      boost::mpl::integral_c<char, '1'>
    >
  {};    

  struct TestWithEmptyString :
    mpllibs::test::test_equal<
      mpllibs::parser::digit::apply<emptyString>::type,
      mpllibs::parser::nothing
    >
  {};    
}



