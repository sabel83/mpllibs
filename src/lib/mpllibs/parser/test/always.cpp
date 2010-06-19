// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/always.h>
#include <mpllibs/parser/nothing.h>
#include <mpllibs/parser/digit.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/list_c.hpp>

namespace
{
  typedef boost::mpl::list_c<char, '1'> oneString;
  typedef boost::mpl::list_c<char, 'a'> aString;

  struct TestResult :
    mpllibs::test::test_equal<
      mpllibs::parser::always<
        mpllibs::parser::digit,
        boost::mpl::int_<13>
      >::apply<oneString>::type::first,
      boost::mpl::int_<13>
    >
  {};

  struct TestFail :
    mpllibs::test::test_equal<
      mpllibs::parser::always<
        mpllibs::parser::digit,
        boost::mpl::int_<13>
      >::apply<aString>::type,
      mpllibs::parser::nothing
    >
  {};
}

