// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/always.h>
#include <mpllibs/parser/nothing.h>
#include <mpllibs/parser/digit.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/int.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::list_c<char, '1'> oneString;
  typedef boost::mpl::list_c<char, 'a'> aString;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::always<
        mpllibs::parser::digit,
        boost::mpl::int_<13>
      >::apply<oneString>::type::first,
      boost::mpl::int_<13>
    >::type
    Always_TestResult;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::always<
        mpllibs::parser::digit,
        boost::mpl::int_<13>
      >::apply<aString>::type,
      mpllibs::parser::nothing
    >::type
    Always_TestFail;
}

MPLLIBS_ADD_TEST(Always_TestResult)
MPLLIBS_ADD_TEST(Always_TestFail)

