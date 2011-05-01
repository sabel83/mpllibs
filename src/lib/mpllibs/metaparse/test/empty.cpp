// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/empty.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_result.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::empty;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;

using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const test_suite suite("empty");
  
  typedef empty<int13> empty13;

  typedef
    equal_to<get_result<apply<empty13, str_, start> >::type, int13>
    test_accept_empty;

  typedef is_error<apply<empty13, str_a, start> > test_reject_non_empty;
}

MPLLIBS_ADD_TEST(suite, test_accept_empty)
MPLLIBS_ADD_TEST(suite, test_reject_non_empty)


