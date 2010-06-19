// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/space.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/list_c.hpp>

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

