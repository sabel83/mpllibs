// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/look_ahead.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/digit_val.hpp>
#include <mpllibs/metaparse/fail.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::look_ahead;
using mpllibs::metaparse::digit_val;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;
using mpllibs::metaparse::fail;
using mpllibs::metaparse::get_remaining;

using boost::mpl::equal_to;
using boost::mpl::apply;
using boost::mpl::equal;

namespace
{
  const suite_path suite("look_ahead");
  
  typedef has_type<look_ahead<digit_val> > test_has_type;

  typedef
    equal_to<
      int1,
      get_result<apply<look_ahead<digit_val>, str_1983, start> >::type
    >
    test_returns_result;

  typedef
    is_error<apply<look_ahead<fail<int13> >, str_1983, start> >
    test_returns_error;

  typedef
    equal<
      str_1983,
      get_remaining<apply<look_ahead<digit_val>, str_1983, start> >::type
    >
    test_doesnt_process_input;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_returns_result)
MPLLIBS_ADD_TEST(suite, test_returns_error)
MPLLIBS_ADD_TEST(suite, test_doesnt_process_input)


