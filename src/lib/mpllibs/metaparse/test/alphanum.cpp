// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/alphanum.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("alphanum");

  typedef boost::mpl::list_c<char, '.', '.', ','> otherString;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::alphanum,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestWithText;
   
  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::digit,
          str_1983,
          mpllibs::metaparse::start
        >
      >::type,
      char_1
    >
    TestWithNumber;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::digit,
        otherString,
        mpllibs::metaparse::start
      >
    >
    TestWithNonAlphanum;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::digit,
        str_,
        mpllibs::metaparse::start
      >
    >
    TestWithEmptyString;
}

MPLLIBS_ADD_TEST(suite, TestWithText)
MPLLIBS_ADD_TEST(suite, TestWithNumber)
MPLLIBS_ADD_TEST(suite, TestWithNonAlphanum)
MPLLIBS_ADD_TEST(suite, TestWithEmptyString)


