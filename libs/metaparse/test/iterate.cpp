// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/iterate.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::iterate;
using mpllibs::metaparse::one_char;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_result;

using boost::mpl::apply_wrap2;
using boost::mpl::equal;
using boost::mpl::list;

namespace
{
  const suite_path suite("iterate");

  typedef has_type<iterate<one_char, int0> > test_has_type;

  typedef
    is_error<apply_wrap2<iterate<one_char, int13>, str_, start> >
    test_empty_input;

  typedef
    equal<
      get_result<apply_wrap2<iterate<one_char, int0>, str_hello, start> >::type,
      list<>
    >
    test0;

  typedef
    equal<
      get_result<apply_wrap2<iterate<one_char, int1>, str_hello, start> >::type,
      list<char_h>
    >
    test1;

  typedef
    equal<
      get_result<apply_wrap2<iterate<one_char, int2>, str_hello, start> >::type,
      list<char_h, char_e>
    >
    test2;

  typedef
    equal<
      get_result<apply_wrap2<iterate<one_char, int3>, str_hello, start> >::type,
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

