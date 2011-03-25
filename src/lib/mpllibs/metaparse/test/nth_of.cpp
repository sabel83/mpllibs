// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nth_of.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/source_position.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/int.hpp>

namespace mpl = boost::mpl;
namespace mp = mpllibs::metaparse;

namespace
{
  const mpllibs::metatest::TestSuite suite("nth_of");
  
  typedef
    mpl::equal_to<
      mp::get_result<
        mpl::apply<mp::nth_of_c<0, lit_h>, str_hello, mp::start>
      >::type,
      char_h
    >
    TestFirstOfOne;

  typedef
    mpl::equal_to<
      mp::get_result<
        mpl::apply<mp::nth_of_c<0, lit_h, lit_e>, str_hello, mp::start>
      >::type,
      char_h
    >
    TestFirstOfTwo;

  typedef
    mpl::equal_to<
      mp::get_result<
        mpl::apply<mp::nth_of<mpl::int_<1>, lit_h, lit_e>, str_hello, mp::start>
      >::type,
      char_e
    >
    TestSecondOfTwo;

  typedef
    mp::is_error<
      mpl::apply<mp::nth_of_c<1, lit_x, lit_e>, str_hello, mp::start>
    >
    TestNothing;
  
  typedef
    mp::is_error<
      mpl::apply<mp::nth_of_c<0>, str_hello, mp::start>
    >
    TestFirstOfNone;

  typedef
    mp::is_error<
      mpl::apply<mp::nth_of_c<-1, lit_h, lit_e>, str_hello, mp::start>
    >
    TestNIsLessThanZero;

  typedef
    mp::is_error<
      mpl::apply<mp::nth_of_c<2, lit_h, lit_e>, str_hello, mp::start>
    >
    TestNIsGreaterThanTheNumberOfParsers;

  typedef
    mp::is_error<
      mpl::apply<mp::nth_of_c<1, lit_x, lit_e, lit_l>, str_hello, mp::start>
    >
    TestErrorBeforeTheNth;

  typedef
    mp::is_error<
      mpl::apply<mp::nth_of_c<1, lit_h, lit_x, lit_l>, str_hello, mp::start>
    >
    TestErrorAtTheNth;

  typedef
    mp::is_error<
      mpl::apply<mp::nth_of_c<1, lit_h, lit_e, lit_x>, str_hello, mp::start>
    >
    TestErrorAfterTheNth;
}

MPLLIBS_ADD_TEST(suite, TestFirstOfOne)
MPLLIBS_ADD_TEST(suite, TestFirstOfTwo)
MPLLIBS_ADD_TEST(suite, TestSecondOfTwo)
MPLLIBS_ADD_TEST(suite, TestNothing)

MPLLIBS_ADD_TEST(suite, TestFirstOfNone)
MPLLIBS_ADD_TEST(suite, TestNIsLessThanZero)
MPLLIBS_ADD_TEST(suite, TestNIsGreaterThanTheNumberOfParsers)
MPLLIBS_ADD_TEST(suite, TestErrorBeforeTheNth)
MPLLIBS_ADD_TEST(suite, TestErrorAtTheNth)
MPLLIBS_ADD_TEST(suite, TestErrorAfterTheNth)


