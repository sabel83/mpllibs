// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/except.h>
#include <mpllibs/parser/one_char.h>
#include <mpllibs/parser/fail.h>

#include <mpllibs/test/test.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef boost::mpl::int_<13> val;

  typedef
    boost::mpl::equal_to<
      mpllibs::parser::except<
        mpllibs::parser::one_char,
        val
      >::apply<helloString>::type,
      mpllibs::parser::nothing
    >
    Except_TestWithGood;
  
  typedef
    boost::mpl::equal_to<
      mpllibs::parser::except<
        mpllibs::parser::fail,
        val
      >::apply<helloString>::type::first,
      val
    >
    Except_TestWithBad;
}

MPLLIBS_ADD_TEST(Except_TestWithGood)
MPLLIBS_ADD_TEST(Except_TestWithBad)


