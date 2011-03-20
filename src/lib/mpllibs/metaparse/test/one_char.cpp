// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_char.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/get_remaining.h>
#include <mpllibs/metaparse/get_position.h>
#include <mpllibs/metaparse/iterate_c.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

namespace
{
  const mpllibs::metatest::TestSuite suite("one_char");

  typedef boost::mpl::list_c<char, 'a','\n','b'> UnixMultiLineText;
  typedef boost::mpl::list_c<char, 'a','\r','\n','b'> DOSMultiLineText;
  typedef boost::mpl::list_c<char, 'a','\r','b'> MacMultiLineText;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_char,
          str_hello,
          mpllibs::metaparse::start
        >
      >::type,
      char_h
    >
    TestOnceCharForNonEmptyString;

  typedef
    boost::mpl::equal_to<
      mpllibs::metaparse::get_result<
        boost::mpl::apply<
          mpllibs::metaparse::one_char,
          mpllibs::metaparse::get_remaining<
            boost::mpl::apply<
              mpllibs::metaparse::one_char,
              str_hello,
              mpllibs::metaparse::start
            >
          >::type,
          mpllibs::metaparse::get_position<
            boost::mpl::apply<
              mpllibs::metaparse::one_char,
              str_hello,
              mpllibs::metaparse::start
            >
          >::type
        >
      >::type,
      char_e
    >
    TestOnceCharForNonEmptyStringSecond;

  typedef
    mpllibs::metaparse::is_error<
      boost::mpl::apply<
        mpllibs::metaparse::one_char,
        str_,
        mpllibs::metaparse::start
      >
    >
    TestOnceCharForEmptyString;
  
  typedef
    boost::mpl::equal_to<
      int2,
      mpllibs::metaparse::get_line<
        mpllibs::metaparse::get_position<
          boost::mpl::apply<
            mpllibs::metaparse::iterate_c<mpllibs::metaparse::one_char, 2>,
            UnixMultiLineText,
            mpllibs::metaparse::start
          >
        >
      >
    >
    TestUnixMultiLineText;

  typedef
    boost::mpl::equal_to<
      int2,
      mpllibs::metaparse::get_line<
        mpllibs::metaparse::get_position<
          boost::mpl::apply<
            mpllibs::metaparse::iterate_c<mpllibs::metaparse::one_char, 3>,
            DOSMultiLineText,
            mpllibs::metaparse::start
          >
        >
      >
    >
    TestDOSMultiLineText;

  typedef
    boost::mpl::equal_to<
      int2,
      mpllibs::metaparse::get_line<
        mpllibs::metaparse::get_position<
          boost::mpl::apply<
            mpllibs::metaparse::iterate_c<mpllibs::metaparse::one_char, 2>,
            MacMultiLineText,
            mpllibs::metaparse::start
          >
        >
      >
    >
    TestMacMultiLineText;
}

MPLLIBS_ADD_TEST(suite, TestOnceCharForNonEmptyString)
MPLLIBS_ADD_TEST(suite, TestOnceCharForNonEmptyStringSecond)
MPLLIBS_ADD_TEST(suite, TestOnceCharForEmptyString)

MPLLIBS_ADD_TEST(suite, TestUnixMultiLineText)
MPLLIBS_ADD_TEST(suite, TestDOSMultiLineText)
MPLLIBS_ADD_TEST(suite, TestMacMultiLineText)

