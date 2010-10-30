// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/keyword.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/equal_sequence.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("keyword");

  typedef boost::mpl::list_c<
    char,
    'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'
  > str_hello_world;
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'x'> str_hellx;
  typedef boost::mpl::list_c<char, 'h', 'x', 'l', 'l', 'o'> str_hxllo;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::keyword<str_hello, char_l>,
        str_hello
      >::type::first,
      char_l
    >
    TestResultType;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<mpllibs::metaparse::keyword<str_hello>, str_>::type,
      mpllibs::metaparse::nothing
    >
    TestEmptyInput;

  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::metaparse::keyword<str_hello>,
        str_hello
      >::type::second,
      str_
    >
    TestItself;

  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::metaparse::keyword<str_hello>,
        str_hello_world
      >::type::second,
      boost::mpl::list_c<char, ' ', 'w', 'o', 'r', 'l', 'd'>
    >
    TestMoreThanItself;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::keyword<str_hello>,
        str_hellx
      >::type,
      mpllibs::metaparse::nothing
    >
    TestNonMatchAtEnd;

  typedef
    boost::mpl::equal_to<
      boost::mpl::apply<
        mpllibs::metaparse::keyword<str_hello>,
        str_hxllo
      >::type,
      mpllibs::metaparse::nothing
    >
    TestNonMatchInTheMiddle;
}

MPLLIBS_ADD_TEST(suite, TestResultType)
MPLLIBS_ADD_TEST(suite, TestEmptyInput)
MPLLIBS_ADD_TEST(suite, TestItself)
MPLLIBS_ADD_TEST(suite, TestMoreThanItself)
MPLLIBS_ADD_TEST(suite, TestNonMatchAtEnd)
MPLLIBS_ADD_TEST(suite, TestNonMatchInTheMiddle)


