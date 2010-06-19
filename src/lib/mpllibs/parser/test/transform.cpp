// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/transform.h>
#include <mpllibs/parser/lit.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/list_c.hpp>

namespace
{
  struct transformation
  {
    template <class t>
    struct apply
    {
      typedef boost::mpl::integral_c<char, 'x'> type;
    };
  };
    
  typedef boost::mpl::integral_c<char, 'h'> hCharacter;
  typedef boost::mpl::integral_c<char, 'e'> eCharacter;
  typedef boost::mpl::integral_c<char, 'x'> xCharacter;
      
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef boost::mpl::list_c<char> emptyString;

  struct TestNormalCase :
    mpllibs::test::test_equal<
      mpllibs::parser::transform<
        mpllibs::parser::lit<hCharacter>,
        transformation
      >::apply<helloString>::type::first,
      xCharacter
    >
  {};

  struct TestParserFails :
    mpllibs::test::test_equal<
      mpllibs::parser::transform<
        mpllibs::parser::lit<xCharacter>,
        transformation
      >::apply<helloString>::type,
      mpllibs::parser::nothing
    >
  {};

  struct TestEmptyInput :
    mpllibs::test::test_equal<
      mpllibs::parser::transform<
        mpllibs::parser::lit<hCharacter>,
        transformation
      >::apply<emptyString>::type,
      mpllibs::parser::nothing
    >
  {};
}

