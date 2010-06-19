// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/one_char.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/integral_c.hpp>

namespace
{
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef boost::mpl::list_c<char> emptyString;

  struct TestOnceCharForNonEmptyString :
    mpllibs::test::test_equal<
      mpllibs::parser::one_char::apply<helloString>::type::first,
      boost::mpl::integral_c<char, 'h'>
    >
  {};
   
  struct TestOnceCharForNonEmptyStringSecond :
    mpllibs::test::test_equal<
      mpllibs::parser::one_char::apply<
        mpllibs::parser::one_char::apply<helloString>::type::second
      >::type::first,
      boost::mpl::integral_c<char, 'e'>
    >
  {};

  struct TestOnceCharForEmptyString :
    mpllibs::test::test_equal<
      mpllibs::parser::one_char::apply<emptyString>::type,
      mpllibs::parser::nothing
    >
  {};
}


