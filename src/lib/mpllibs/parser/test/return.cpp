// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/return.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/integral_c.hpp>

namespace
{
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef boost::mpl::list_c<char> emptyString;

  struct TestForNonEmptyString :
    mpllibs::test::test_equal<
      mpllibs::parser::return_<
        boost::mpl::integral_c<char, 'x'>
      >::apply<helloString>::type::first,
      boost::mpl::integral_c<char, 'x'>
    >
  {};
   
  struct TestForEmptyString :
    mpllibs::test::test_equal<
      mpllibs::parser::return_<
        boost::mpl::integral_c<char, 'x'>
      >::apply<emptyString>::type::first,
      boost::mpl::integral_c<char, 'x'>
    >
  {};
}


