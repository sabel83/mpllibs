// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/iterate_c.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("iterate_c");

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::iterate_c<mpllibs::metaparse::one_char, 13>,
        str_,
        mpllibs::metaparse::start
      >
    >
    TestEmptyInput;

  typedef
    boost::mpl::equal<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::iterate_c<mpllibs::metaparse::one_char, 0>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      boost::mpl::list<>
    >
    Test0;

  typedef
    boost::mpl::equal<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::iterate_c<mpllibs::metaparse::one_char, 1>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      boost::mpl::list<char_h>
    >
    Test1;

  typedef
    boost::mpl::equal<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::iterate_c<mpllibs::metaparse::one_char, 2>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      boost::mpl::list<char_h, char_e>
    >
    Test2;

  typedef
    boost::mpl::equal<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::iterate_c<mpllibs::metaparse::one_char, 3>,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      boost::mpl::list<char_h, char_e, char_l>
    >
    Test3;
}

MPLLIBS_ADD_TEST(suite, TestEmptyInput)
MPLLIBS_ADD_TEST(suite, Test0)
MPLLIBS_ADD_TEST(suite, Test1)
MPLLIBS_ADD_TEST(suite, Test2)
MPLLIBS_ADD_TEST(suite, Test3)

