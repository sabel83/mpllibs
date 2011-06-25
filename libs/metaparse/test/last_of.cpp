// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::last_of;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;

using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const suite_path suite("last_of");

  typedef has_type<last_of<lit_h, lit_e> > test_has_type;

  typedef
    equal_to<get_result<apply<last_of<lit_h>, str_hello, start> >::type, char_h>
    test_one_char;

  typedef
    equal_to<
      get_result<apply<last_of<lit_h, lit_e>, str_hello, start> >::type,
      char_e
    >
    test_two_chars;

  typedef
    is_error<apply<last_of<lit_x, lit_e>, str_hello, start> >
    test_first_fails;

  typedef
    is_error<apply<last_of<lit_h, lit_x>, str_hello, start> >
    test_second_fails;

  typedef is_error<apply<last_of<lit_h, lit_e>, str_, start> > test_empty_input;

  typedef
    equal_to<
      get_result<apply<last_of<lit_h, lit_e, lit_l>, str_hello, start> >::type,
      char_l
    >
    test_three_chars;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_one_char)
MPLLIBS_ADD_TEST(suite, test_two_chars)
MPLLIBS_ADD_TEST(suite, test_first_fails)
MPLLIBS_ADD_TEST(suite, test_second_fails)
MPLLIBS_ADD_TEST(suite, test_empty_input)
MPLLIBS_ADD_TEST(suite, test_three_chars)


