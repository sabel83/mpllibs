// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/sequence.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/equal.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("sequence");

  typedef
    boost::mpl::equal<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::sequence<>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      boost::mpl::list<>
    >
    TestNoParser;

  typedef
    boost::mpl::equal<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::sequence<lit_h>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      boost::mpl::list<char_h>
    >
    TestOneParser;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::sequence<lit_e>,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    TestOneFailingParser;
  
  typedef
    boost::mpl::equal<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::sequence<lit_h, lit_e>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      boost::mpl::list<char_h, char_e>
    >
    TestTwoChars;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::sequence<lit_x, lit_e>,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    TestFirstFails;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::sequence<lit_h, lit_x>,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    TestSecondFails;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::sequence<lit_h, lit_e>,
        str_,
        mpllibs::metaparse::start
      >
    >
    TestEmptyInput;

  typedef
    boost::mpl::equal<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::sequence<lit_h, lit_e, lit_l>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      boost::mpl::list<char_h, char_e, char_l>
    >
    TestThreeChars;

  typedef
    boost::mpl::equal_to<
      boost::mpl::at_c<
        mpllibs::metaparse::get_result<
          boost::mpl::apply<
            mpllibs::metaparse::sequence<lit_h, lit_e, lit_l>,
            str_hello,
            mpllibs::metaparse::start
          >
        >::type,
        1
      >::type,
      char_e
    >
    TestIndexingInResult;
}

MPLLIBS_ADD_TEST(suite, TestNoParser)
MPLLIBS_ADD_TEST(suite, TestOneParser)
MPLLIBS_ADD_TEST(suite, TestOneFailingParser)
MPLLIBS_ADD_TEST(suite, TestTwoChars)
MPLLIBS_ADD_TEST(suite, TestFirstFails)
MPLLIBS_ADD_TEST(suite, TestSecondFails)
MPLLIBS_ADD_TEST(suite, TestEmptyInput)
MPLLIBS_ADD_TEST(suite, TestThreeChars)
MPLLIBS_ADD_TEST(suite, TestIndexingInResult)


