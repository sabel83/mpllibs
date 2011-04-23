// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/transform.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::TestSuite;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::transform;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;

using boost::mpl::always;
using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const TestSuite suite("transform");

  typedef always<char_x> f;
    
  typedef
    equal_to<
      get_result<apply<transform<lit_h, f>, str_hello, start> >::type,
      char_x
    >
    test_normal_case;

  typedef
    is_error<apply<transform<lit_x, f>, str_hello, start> >
    test_parser_fails;

  typedef is_error<apply<transform<lit_h, f>, str_, start> > test_empty_input;
}

MPLLIBS_ADD_TEST(suite, test_normal_case)
MPLLIBS_ADD_TEST(suite, test_parser_fails)
MPLLIBS_ADD_TEST(suite, test_empty_input)


