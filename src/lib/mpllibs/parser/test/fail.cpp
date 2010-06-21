// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/fail.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::fail::apply<helloString>::type,
      mpllibs::parser::nothing
    >
    Fail_TestFailForNonEmptyString;
}

MPLLIBS_ADD_TEST(Fail_TestFailForNonEmptyString)


