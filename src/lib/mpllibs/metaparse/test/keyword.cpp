// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/keyword.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/get_remaining.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal.hpp>

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
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::keyword<str_hello, char_l>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_l
    >
    TestResultType;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::keyword<str_hello>,
        str_,
        mpllibs::metaparse::start
      >
    >
    TestEmptyInput;

  typedef
    boost::mpl::equal<
      mpllibs::metaparse::get_remaining<
        boost::mpl::apply<
          mpllibs::metaparse::keyword<str_hello>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      str_
    >
    TestItself;

  typedef
    boost::mpl::equal<
      mpllibs::metaparse::get_remaining<
        boost::mpl::apply<
          mpllibs::metaparse::keyword<str_hello>,
          str_hello_world,
          mpllibs::metaparse::start
        >
      >::type,
      boost::mpl::list_c<char, ' ', 'w', 'o', 'r', 'l', 'd'>
    >
    TestMoreThanItself;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::keyword<str_hello>,
        str_hellx,
        mpllibs::metaparse::start
      >
    >
    TestNonMatchAtEnd;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::keyword<str_hello>,
        str_hxllo,
        mpllibs::metaparse::start
      >
    >
    TestNonMatchInTheMiddle;
}

MPLLIBS_ADD_TEST(suite, TestResultType)
MPLLIBS_ADD_TEST(suite, TestEmptyInput)
MPLLIBS_ADD_TEST(suite, TestItself)
MPLLIBS_ADD_TEST(suite, TestMoreThanItself)
MPLLIBS_ADD_TEST(suite, TestNonMatchAtEnd)
MPLLIBS_ADD_TEST(suite, TestNonMatchInTheMiddle)


