// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/keep_first.h>
#include <mpllibs/parser/lit.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::integral_c<char, 'h'> hCharacter;
  typedef boost::mpl::integral_c<char, 'e'> eCharacter;
  typedef boost::mpl::integral_c<char, 'x'> xCharacter;
      
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef boost::mpl::list_c<char> emptyString;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_first<
        mpllibs::parser::lit<hCharacter>,
        mpllibs::parser::lit<eCharacter>
      >::apply<helloString>::type::first,
      hCharacter
    >::type
    KeepFirst_TestTwoChars;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_first<
        mpllibs::parser::lit<xCharacter>,
        mpllibs::parser::lit<eCharacter>
      >::apply<helloString>::type,
      mpllibs::parser::nothing
    >::type
    KeepFirst_TestFirstFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_first<
        mpllibs::parser::lit<hCharacter>,
        mpllibs::parser::lit<xCharacter>
      >::apply<helloString>::type,
      mpllibs::parser::nothing
    >::type
    KeepFirst_TestSecondFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::keep_first<
        mpllibs::parser::lit<hCharacter>,
        mpllibs::parser::lit<eCharacter>
      >::apply<emptyString>::type,
      mpllibs::parser::nothing
    >::type
    KeepFirst_TestEmptyInput;
}

MPLLIBS_ADD_TEST(KeepFirst_TestTwoChars)
MPLLIBS_ADD_TEST(KeepFirst_TestFirstFails)
MPLLIBS_ADD_TEST(KeepFirst_TestSecondFails)
MPLLIBS_ADD_TEST(KeepFirst_TestEmptyInput)

