// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// This header file contains code that is reused by other cpp files

#include <mpllibs/metaparse/letter.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <mpllibs/metatest/has_type.hpp>

#include "common.hpp"
 
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::has_type;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::letter;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;

using boost::mpl::equal;
using boost::mpl::apply_wrap2;
using boost::mpl::list;

namespace
{ 
  typedef any1<letter> any1_letter;

  typedef has_type<any1_letter> test_has_type;

  typedef is_error<apply_wrap2<any1_letter, str_, start> > test_empty_input;
  
  typedef is_error<apply_wrap2<any1_letter, chars0, start> > test0;
  
  typedef
    equal<
      get_result<apply_wrap2<any1_letter, chars1, start> >::type,
      list<char_h>
    >
    test1;
  
  typedef
    equal<
      get_result<apply_wrap2<any1_letter, chars2, start> >::type,
      list<char_h, char_e>
    >
    test2;
  
  typedef
    equal<
      get_result<apply_wrap2<any1_letter, chars3, start> >::type,
      list<char_h, char_e, char_l>
    >
    test3;
  
  typedef
    equal<
      get_result<apply_wrap2<any1_letter, chars4, start> >::type,
      list<char_h, char_e, char_l, char_l>
    >
    test4;
  
  typedef
    equal<
      get_result<apply_wrap2<any1_letter, chars5, start> >::type,
      list<char_h, char_e, char_l, char_l, char_o>
    >
    test5;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_empty_input)
MPLLIBS_ADD_TEST(suite, test0)
MPLLIBS_ADD_TEST(suite, test1)
MPLLIBS_ADD_TEST(suite, test2)
MPLLIBS_ADD_TEST(suite, test3)
MPLLIBS_ADD_TEST(suite, test4)
MPLLIBS_ADD_TEST(suite, test5)


