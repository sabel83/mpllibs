// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/vector_c.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_sequence)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::sequence;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  
  using boost::mpl::equal;
  using boost::mpl::apply_wrap2;
  using boost::mpl::list;
  using boost::mpl::equal_to;
  using boost::mpl::at_c;
  using boost::mpl::vector_c;

  meta_require<has_type<sequence<lit_h> > >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal<get_result<apply_wrap2<sequence<>, str_hello, start> >::type, list<> >
  >(MPLLIBS_HERE, "test_no_parser");

  meta_require<
    equal<
      get_result<apply_wrap2<sequence<lit_h>, str_hello, start> >::type,
      vector_c<char, 'h'>
    >
  >(MPLLIBS_HERE, "test_one_parser");

  meta_require<
    is_error<apply_wrap2<sequence<lit_e>, str_hello, start> >
  >(MPLLIBS_HERE, "test_one_failing_parser");
  
  meta_require<
    equal<
      get_result<apply_wrap2<sequence<lit_h, lit_e>, str_hello, start> >::type,
      vector_c<char, 'h', 'e'>
    >
  >(MPLLIBS_HERE, "test_two_chars");

  meta_require<
    is_error<apply_wrap2<sequence<lit_x, lit_e>, str_hello, start> >
  >(MPLLIBS_HERE, "test_first_fails");

  meta_require<
    is_error<apply_wrap2<sequence<lit_h, lit_x>, str_hello, start> >
  >(MPLLIBS_HERE, "test_second_fails");

  meta_require<
    is_error<apply_wrap2<sequence<lit_h, lit_e>, str_, start> >
  >(MPLLIBS_HERE, "test_empty_input");

  meta_require<
    equal<
      get_result<
        apply_wrap2<sequence<lit_h, lit_e, lit_l>, str_hello, start>
      >::type,
      vector_c<char, 'h', 'e', 'l'>
    >
  >(MPLLIBS_HERE, "test_three_chars");

  meta_require<
    equal_to<
      at_c<
        get_result<
          apply_wrap2<sequence<lit_h, lit_e, lit_l>, str_hello, start>
        >::type,
        1
      >::type,
      char_e
    >
  >(MPLLIBS_HERE, "test_indexing_in_result");
}


