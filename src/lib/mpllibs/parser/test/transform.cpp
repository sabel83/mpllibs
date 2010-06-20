// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/transform.h>
#include <mpllibs/parser/lit.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/equal_to.hpp>

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

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::transform<
        mpllibs::parser::lit<hCharacter>,
        transformation
      >::apply<helloString>::type::first,
      xCharacter
    >::type
    Transform_TestNormalCase;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::transform<
        mpllibs::parser::lit<xCharacter>,
        transformation
      >::apply<helloString>::type,
      mpllibs::parser::nothing
    >::type
    Transform_TestParserFails;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::transform<
        mpllibs::parser::lit<hCharacter>,
        transformation
      >::apply<emptyString>::type,
      mpllibs::parser::nothing
    >::type
    Transform_TestEmptyInput;
}

MPLLIBS_ADD_TEST(Transform_TestNormalCase)
MPLLIBS_ADD_TEST(Transform_TestParserFails)
MPLLIBS_ADD_TEST(Transform_TestEmptyInput)


