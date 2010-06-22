// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/alphanum.h>

#include "common.h"

#include <mpllibs/test/test.h>

#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::list_c<char, '.', '.', ','> otherString;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::alphanum::apply<str_hello>::type::first,
      char_h
    >
    Alphanum_TestWithText;
   
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit::apply<str_1983>::type::first,
      char_1
    >
    Alphanum_TestWithNumber;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit::apply<otherString>::type,
      mpllibs::parser::nothing
    >
    Alphanum_TestWithNonAlphanum;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::digit::apply<str_>::type,
      mpllibs::parser::nothing
    >
    Alphanum_TestWithEmptyString;
}

MPLLIBS_ADD_TEST(Alphanum_TestWithText)
MPLLIBS_ADD_TEST(Alphanum_TestWithNumber)
MPLLIBS_ADD_TEST(Alphanum_TestWithNonAlphanum)
MPLLIBS_ADD_TEST(Alphanum_TestWithEmptyString)


