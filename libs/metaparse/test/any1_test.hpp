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
#include <boost/mpl/vector_c.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

DEFINE_TEST_CASE
{ 
  using mpllibs::metatest::has_type;
  using mpllibs::metatest::meta_require;
  
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::letter;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  
  using boost::mpl::equal;
  using boost::mpl::apply_wrap2;
  using boost::mpl::list;
  using boost::mpl::vector_c;

  typedef any1<letter> any1_letter;

  meta_require<has_type<any1_letter> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    is_error<apply_wrap2<any1_letter, str_, start> >
  >(MPLLIBS_HERE, "test_empty_input");
  
  meta_require<
    is_error<apply_wrap2<any1_letter, chars0, start> >
  >(MPLLIBS_HERE, "test0");
  
  meta_require<
    equal<
      get_result<apply_wrap2<any1_letter, chars1, start> >::type,
      vector_c<char, 'h'>
    >
  >(MPLLIBS_HERE, "test1");
  
  meta_require<
    equal<
      get_result<apply_wrap2<any1_letter, chars2, start> >::type,
      vector_c<char, 'h', 'e'>
    >
  >(MPLLIBS_HERE, "test2");
  
  meta_require<
    equal<
      get_result<apply_wrap2<any1_letter, chars3, start> >::type,
      vector_c<char, 'h', 'e', 'l'>
    >
  >(MPLLIBS_HERE, "test3");
  
  meta_require<
    equal<
      get_result<apply_wrap2<any1_letter, chars4, start> >::type,
      vector_c<char, 'h', 'e', 'l', 'l'>
    >
  >(MPLLIBS_HERE, "test4");
  
  meta_require<
    equal<
      get_result<apply_wrap2<any1_letter, chars5, start> >::type,
      vector_c<char, 'h', 'e', 'l', 'l', 'o'>
    >
  >(MPLLIBS_HERE, "test5");
}


