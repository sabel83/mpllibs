// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/if.h>
#include <mpllibs/parser/lit.h>
#include <mpllibs/parser/digit.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::list_c<char, 'a'> aString;
  typedef boost::mpl::list_c<char, '1'> oneString;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::if_<
        mpllibs::parser::digit,
        boost::mpl::int_<11>,
        boost::mpl::int_<13>
      >::apply<oneString>::type::first,
      boost::mpl::int_<11>
    >
    If_TestTrue;
    
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::if_<
        mpllibs::parser::digit,
        boost::mpl::int_<11>,
        boost::mpl::int_<13>
      >::apply<aString>::type::first,
      boost::mpl::int_<13>
    >
    If_TestFalse;
}

MPLLIBS_ADD_TEST(If_TestTrue)
MPLLIBS_ADD_TEST(If_TestFalse)

