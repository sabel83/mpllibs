// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/iterate_c.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::iterate_c;
using mpllibs::metaparse::one_char;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_result;

using boost::mpl::apply;
using boost::mpl::equal;
using boost::mpl::list;

namespace
{
  const suite_path suite("iterate_c");

  typedef has_type<iterate_c<one_char, 0> > test_has_type;

  typedef
    is_error<apply<iterate_c<one_char, 13>, str_, start> >
    test_empty_input;

  typedef
    equal<
      get_result<apply<iterate_c<one_char, 0>, str_hello, start> >::type,
      list<>
    >
    test0;

  typedef
    equal<
      get_result<apply<iterate_c<one_char, 1>, str_hello, start> >::type,
      list<char_h>
    >
    test1;

  typedef
    equal<
      get_result<apply<iterate_c<one_char, 2>, str_hello, start> >::type,
      list<char_h, char_e>
    >
    test2;

  typedef
    equal<
      get_result<apply<iterate_c<one_char, 3>, str_hello, start> >::type,
      list<char_h, char_e, char_l>
    >
    test3;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_empty_input)
MPLLIBS_ADD_TEST(suite, test0)
MPLLIBS_ADD_TEST(suite, test1)
MPLLIBS_ADD_TEST(suite, test2)
MPLLIBS_ADD_TEST(suite, test3)

