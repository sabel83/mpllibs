// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/iterate.h>
#include <mpllibs/metaparse/util/is_nothing.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/equal_sequence.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("iterate");

  typedef
    mpllibs::metaparse::util::is_nothing<
      boost::mpl::apply<
        mpllibs::metaparse::iterate<mpllibs::metaparse::one_char, int13>,
        str_
      >
    >
    TestEmptyInput;

  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::metaparse::iterate<mpllibs::metaparse::one_char, int0>,
        str_hello
      >::type::first,
      boost::mpl::list<>
    >
    Test0;

  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::metaparse::iterate<mpllibs::metaparse::one_char, int1>,
        str_hello
      >::type::first,
      boost::mpl::list<char_h>
    >
    Test1;

  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::metaparse::iterate<mpllibs::metaparse::one_char, int2>,
        str_hello
      >::type::first,
      boost::mpl::list<char_h, char_e>
    >
    Test2;

  typedef
    mpllibs::metatest::equal_sequence<
      boost::mpl::apply<
        mpllibs::metaparse::iterate<mpllibs::metaparse::one_char, int3>,
        str_hello
      >::type::first,
      boost::mpl::list<char_h, char_e, char_l>
    >
    Test3;
}

MPLLIBS_ADD_TEST(suite, TestEmptyInput)
MPLLIBS_ADD_TEST(suite, Test0)
MPLLIBS_ADD_TEST(suite, Test1)
MPLLIBS_ADD_TEST(suite, Test2)
MPLLIBS_ADD_TEST(suite, Test3)

