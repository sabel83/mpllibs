// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/one_of.h>
#include <mpllibs/parser/one_char.h>
#include <mpllibs/parser/fail.h>

#include <mpllibs/test/test_equal.h>

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/list_c.hpp>

namespace
{
  typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> helloString;

  struct Test0 :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of_0< >::apply<helloString>::type,
      mpllibs::parser::nothing
    >
  {};    

  struct Test1WithGood :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of_1<
        mpllibs::parser::one_char
      >::apply<helloString>::type::first,
      boost::mpl::integral_c<char, 'h'>
    >
  {};    

  struct Test1WithBad :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of_1<
        mpllibs::parser::fail
      >::apply<helloString>::type,
      mpllibs::parser::nothing
    >
  {};    

  struct Test2WithTwoGood :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of_2<
        mpllibs::parser::one_char,
        mpllibs::parser::one_char
      >::apply<helloString>::type::first,
      boost::mpl::integral_c<char, 'h'>
    >
  {};    

  struct Test2WithFirstGood :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of_2<
        mpllibs::parser::one_char,
        mpllibs::parser::fail
      >::apply<helloString>::type::first,
      boost::mpl::integral_c<char, 'h'>
    >
  {};    

  struct Test2WithSecondGood :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of_2<
        mpllibs::parser::fail,
        mpllibs::parser::one_char
      >::apply<helloString>::type::first,
      boost::mpl::integral_c<char, 'h'>
    >
  {};    
      
  struct Test2WithTwoBad :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of_2<
        mpllibs::parser::fail,
        mpllibs::parser::fail
      >::apply<helloString>::type,
      mpllibs::parser::nothing
    >
  {};    

      


  struct Test :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of< >::apply<helloString>::type,
      mpllibs::parser::nothing
    >
  {};    

  struct TestWithGood :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of<
        mpllibs::parser::one_char
      >::apply<helloString>::type::first,
      boost::mpl::integral_c<char, 'h'>
    >
  {};    

  struct TestWithBad :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of<
        mpllibs::parser::fail
      >::apply<helloString>::type,
      mpllibs::parser::nothing
    >
  {};    

  struct TestWithTwoGood :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of<
        mpllibs::parser::one_char,
        mpllibs::parser::one_char
      >::apply<helloString>::type::first,
      boost::mpl::integral_c<char, 'h'>
    >
  {};    

  struct TestWithFirstGood :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of<
        mpllibs::parser::one_char,
        mpllibs::parser::fail
      >::apply<helloString>::type::first,
      boost::mpl::integral_c<char, 'h'>
    >
  {};    

  struct TestWithSecondGood :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of<
        mpllibs::parser::fail,
        mpllibs::parser::one_char
      >::apply<helloString>::type::first,
      boost::mpl::integral_c<char, 'h'>
    >
  {};    
      
  struct TestWithTwoBad :
    mpllibs::test::test_equal<
      mpllibs::parser::one_of<
        mpllibs::parser::fail,
        mpllibs::parser::fail
      >::apply<helloString>::type,
      mpllibs::parser::nothing
    >
  {};    
}


