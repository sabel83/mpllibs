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

namespace
{
  const mpllibs::metatest::TestSuite suite("nth_of");

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::nth_of_c<0, lit_h>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestFirstOfOne;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::nth_of_c<0, lit_h, lit_e>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestFirstOfTwo;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::nth_of<boost::mpl::int_<1>, lit_h, lit_e>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_e
    >
    TestSecondOfTwo;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::nth_of_c<1, lit_x, lit_e>,
        str_hello,
        mpllibs::metaparse::start
      >
    >
    TestNothing;
}

MPLLIBS_ADD_TEST(suite, TestFirstOfOne)
MPLLIBS_ADD_TEST(suite, TestFirstOfTwo)
MPLLIBS_ADD_TEST(suite, TestSecondOfTwo)
MPLLIBS_ADD_TEST(suite, TestNothing)


