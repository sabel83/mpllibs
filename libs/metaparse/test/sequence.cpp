// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::sequence;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;

using boost::mpl::equal;
using boost::mpl::apply;
using boost::mpl::list;
using boost::mpl::equal_to;
using boost::mpl::at_c;

namespace
{
  const suite_path suite("sequence");

  typedef
    equal<get_result<apply<sequence<>, str_hello, start> >::type, list<> >
    test_no_parser;

  typedef
    equal<
      get_result<apply<sequence<lit_h>, str_hello, start> >::type,
      list<char_h>
    >
    test_one_parser;

  typedef
    is_error<apply<sequence<lit_e>, str_hello, start> >
    test_one_failing_parser;
  
  typedef
    equal<
      get_result<apply<sequence<lit_h, lit_e>, str_hello, start> >::type,
      list<char_h, char_e>
    >
    test_two_chars;

  typedef
    is_error<apply<sequence<lit_x, lit_e>, str_hello, start> >
    test_first_fails;

  typedef
    is_error<apply<sequence<lit_h, lit_x>, str_hello, start> >
    test_second_fails;

  typedef
    is_error<apply<sequence<lit_h, lit_e>, str_, start> >
    test_empty_input;

  typedef
    equal<
      get_result<apply<sequence<lit_h, lit_e, lit_l>, str_hello, start> >::type,
      list<char_h, char_e, char_l>
    >
    test_three_chars;

  typedef
    equal_to<
      at_c<
        get_result<
          apply<sequence<lit_h, lit_e, lit_l>, str_hello, start>
        >::type,
        1
      >::type,
      char_e
    >
    test_indexing_in_result;
}

MPLLIBS_ADD_TEST(suite, test_no_parser)
MPLLIBS_ADD_TEST(suite, test_one_parser)
MPLLIBS_ADD_TEST(suite, test_one_failing_parser)
MPLLIBS_ADD_TEST(suite, test_two_chars)
MPLLIBS_ADD_TEST(suite, test_first_fails)
MPLLIBS_ADD_TEST(suite, test_second_fails)
MPLLIBS_ADD_TEST(suite, test_empty_input)
MPLLIBS_ADD_TEST(suite, test_three_chars)
MPLLIBS_ADD_TEST(suite, test_indexing_in_result)


