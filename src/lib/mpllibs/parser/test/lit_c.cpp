// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/lit_c.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::integral_c<char, 'h'> hCharacter;
  typedef boost::mpl::integral_c<char, 'e'> eCharacter;
    
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef boost::mpl::list_c<char, 'b', 'e', 'l', 'l', 'o'> otherString;
  typedef boost::mpl::list_c<char> emptyString;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::lit_c<'h'>::apply<helloString>::type::first,
      hCharacter
    >
    LitC_TestAccept;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::lit_c<'h'>::apply<otherString>::type,
      mpllibs::parser::nothing
    >
    LitC_TestReject;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::lit_c<'h'>::apply<emptyString>::type,
      mpllibs::parser::nothing
    >
    LitC_TestWithEmptyString;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::lit_c<'e'>::apply<
        mpllibs::parser::lit_c<'h'>::apply<helloString>::type::second
      >::type::first,
      eCharacter
    >
    LitC_TestRemainingString;
}

MPLLIBS_ADD_TEST(LitC_TestAccept)
MPLLIBS_ADD_TEST(LitC_TestReject)
MPLLIBS_ADD_TEST(LitC_TestWithEmptyString)
MPLLIBS_ADD_TEST(LitC_TestRemainingString)

