// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/if.h>
#include <mpllibs/parser/lit.h>
#include <mpllibs/parser/digit.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/list_c.hpp>

namespace
{
  typedef boost::mpl::list_c<char, 'a'> aString;
  typedef boost::mpl::list_c<char, '1'> oneString;

  struct TestTrue :
    mpllibs::test::test_equal<
      mpllibs::parser::if_<
        mpllibs::parser::digit,
        boost::mpl::int_<11>,
        boost::mpl::int_<13>
      >::apply<oneString>::type::first,
      boost::mpl::int_<11>
    >
  {};

  struct TestFalse :
    mpllibs::test::test_equal<
      mpllibs::parser::if_<
        mpllibs::parser::digit,
        boost::mpl::int_<11>,
        boost::mpl::int_<13>
      >::apply<aString>::type::first,
      boost::mpl::int_<13>
    >
  {};
}


