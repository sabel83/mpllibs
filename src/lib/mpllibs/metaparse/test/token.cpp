// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/token.h>
#include <mpllibs/metaparse/keyword.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/equal_sequence.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("token");

  typedef
    boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o', ' ', '\t'>
    str_hello_t;
      
  typedef mpllibs::metaparse::keyword<str_hello, int13> testParser;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::token<testParser>,
        str_hello
      >::type::first,
      boost::mpl::apply<testParser, str_hello>::type::first
    >
    TestNoSpace;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::token<testParser>,
        str_hello_t
      >::type::first,
      boost::mpl::apply<testParser, str_hello>::type::first
    >
    TestSpaces;

  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::metaparse::token<testParser>,
        str_hello_t
      >::type::second,
      str_
    >
    TestSpacesConsumed;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::metaparse::token<testParser>, str_>::type,
      mpllibs::metaparse::nothing
    >
    TestFail;
}

MPLLIBS_ADD_TEST(suite, TestNoSpace)
MPLLIBS_ADD_TEST(suite, TestSpaces)
MPLLIBS_ADD_TEST(suite, TestSpacesConsumed)
MPLLIBS_ADD_TEST(suite, TestFail)


