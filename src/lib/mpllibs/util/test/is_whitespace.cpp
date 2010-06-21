// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/util/is_whitespace.h>

#include <mpllibs/test/test.h>

namespace
{
  typedef
    mpllibs::util::is_whitespace::apply<boost::mpl::integral_c<char, ' '> >
    IsWhitespace_TestSpace;
  
  typedef
    mpllibs::util::is_whitespace::apply<boost::mpl::integral_c<char, '\t'> >
    IsWhitespace_TestTab;
  
  typedef
    mpllibs::util::is_whitespace::apply<boost::mpl::integral_c<char, 'a'> >
    IsWhitespace_TestNonWhitespace;
}

MPLLIBS_ADD_TEST(IsWhitespace_TestSpace)
MPLLIBS_ADD_TEST(IsWhitespace_TestTab)
MPLLIBS_ADD_TEST_TO_FAIL(IsWhitespace_TestNonWhitespace)


