// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/transform.h>

#include "common.h"

#include <mpllibs/test/test.h>
#include <mpllibs/test/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::test::TestSuite suite("transform");

  typedef boost::mpl::always<char_x> transform;
    
  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::transform<lit_h, transform>,
        str_hello
      >::type::first,
      char_x
    >
    TestNormalCase;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::transform<lit_x, transform>,
        str_hello
      >::type,
      mpllibs::parser::nothing
    >
    TestParserFails;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::parser::transform<lit_h, transform>,
        str_
      >::type,
      mpllibs::parser::nothing
    >
    TestEmptyInput;
}

MPLLIBS_ADD_TEST(suite, TestNormalCase)
MPLLIBS_ADD_TEST(suite, TestParserFails)
MPLLIBS_ADD_TEST(suite, TestEmptyInput)


