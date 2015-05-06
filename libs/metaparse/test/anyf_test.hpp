// Copyright Abel Sinkovics (abel@sinkovics.hu) 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// This header file contains code that is reused by other cpp files

#include <mpllibs/metaparse/letter.hpp>
#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include "common.hpp"
 
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

DEFINE_TEST_CASE
{ 
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::letter;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::sequence;
  
  using boost::mpl::equal;
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;
  using boost::mpl::vector_c;
  using boost::mpl::vector;
  using boost::mpl::size;
  
  typedef sequence<letter, letter> letter_pair;
  typedef anyf<letter_pair> anyf_letter_pair;

  typedef boost::mpl::vector_c<char, 'h','e','l','l','o','w','0'> chars6;

  typedef
    boost::mpl::vector_c<char, 'h','e','l','l','o','w','o','r','0'>
    chars8;

  typedef
    boost::mpl::vector_c<char, 'h','e','l','l','o','w','o','r','l','d','0'>
    chars10;

  // test_empty_input
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<anyf_letter_pair, str_, start> >::type,
      vector<>
    >
  ));
  
  // test0
  BOOST_MPL_ASSERT_NOT((
    is_error<apply_wrap2<anyf_letter_pair, chars0, start> >
  ));
  
  // test_with_a_failing_item
  BOOST_MPL_ASSERT(( is_error<apply_wrap2<anyf_letter_pair, chars1, start> > ));
  
  // test1_pair
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<anyf_letter_pair, chars2, start> >::type,
      vector<vector_c<char, 'h', 'e'> >,
      equal_sequences
    >
  ));
  
  // test2_pairs
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<anyf_letter_pair, chars4, start> >::type,
      vector<vector_c<char, 'h','e'>, vector_c<char, 'l','l'> >,
      equal_sequences
    >
  ));
  
  // test3_pairs
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<anyf_letter_pair, chars6, start> >::type,
      vector<
        vector_c<char, 'h','e'>,
        vector_c<char, 'l','l'>,
        vector_c<char, 'o','w'>
      >,
      equal_sequences
    >
  ));
  
  // test4_pairs
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<anyf_letter_pair, chars8, start> >::type,
      vector<
        vector_c<char, 'h','e'>,
        vector_c<char, 'l','l'>,
        vector_c<char, 'o','w'>,
        vector_c<char, 'o','r'>
      >,
      equal_sequences
    >
  ));
  
  // test5
  BOOST_MPL_ASSERT((
    equal<
      get_result<apply_wrap2<anyf_letter_pair, chars10, start> >::type,
      vector<
        vector_c<char, 'h','e'>,
        vector_c<char, 'l','l'>,
        vector_c<char, 'o','w'>,
        vector_c<char, 'o','r'>,
        vector_c<char, 'l','d'>
      >,
      equal_sequences
    >
  ));
  
  // test_length
  BOOST_MPL_ASSERT((
    equal_to<
      size<
        get_result<apply_wrap2<anyf_letter_pair, chars6, start> >::type
      >::type,
      int3
    >
  ));
}

