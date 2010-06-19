// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/except.h>
#include <mpllibs/parser/one_char.h>
#include <mpllibs/parser/fail.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/list_c.hpp>

namespace
{
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;
  typedef boost::mpl::int_<13> val;
      
  struct TestWithGood :
    mpllibs::test::test_equal<
      mpllibs::parser::except<
        mpllibs::parser::one_char,
        val
      >::apply<helloString>::type,
      mpllibs::parser::nothing
    >
  {};    

  struct TestWithBad :
    mpllibs::test::test_equal<
      mpllibs::parser::except<
        mpllibs::parser::fail,
        val
      >::apply<helloString>::type::first,
      val
    >
  {};    
}


