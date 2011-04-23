// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/any.h>
#include <mpllibs/metaparse/letter.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include "common.h"
 
#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::any;
using mpllibs::metaparse::letter;
using mpllibs::metaparse::start;

using boost::mpl::equal;
using boost::mpl::apply;
using boost::mpl::list;

namespace
{ 
  const test_suite suite("any");
  
  typedef any<letter> any_letter;

  typedef
    equal<get_result<apply<any_letter, str_, start> >::type, list<> >
    test_empty_input;
  
  typedef
    equal<get_result<apply<any_letter, chars0, start> >::type, list<> >
    test0;
  
  typedef
    equal<get_result<apply<any_letter, chars1, start> >::type, list<char_h> >
    test1;
  
  typedef
    equal<
      get_result<apply<any_letter, chars2, start> >::type,
      list<char_h, char_e>
    >
    test2;
  
  typedef
    equal<
      get_result<apply<any_letter, chars3, start> >::type,
      list<char_h, char_e, char_l>
    >
    test3;
  
  typedef
    equal<
      get_result<apply<any_letter, chars4, start> >::type,
      list<char_h, char_e, char_l, char_l>
    >
    test4;
  
  typedef
    equal<
      get_result<apply<any_letter, chars5, start> >::type,
      list<char_h, char_e, char_l, char_l, char_o>
    >
    test5;
}

MPLLIBS_ADD_TEST(suite, test_empty_input)
MPLLIBS_ADD_TEST(suite, test0)
MPLLIBS_ADD_TEST(suite, test1)
MPLLIBS_ADD_TEST(suite, test2)
MPLLIBS_ADD_TEST(suite, test3)
MPLLIBS_ADD_TEST(suite, test4)
MPLLIBS_ADD_TEST(suite, test5)

