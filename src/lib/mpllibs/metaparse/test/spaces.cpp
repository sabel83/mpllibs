// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/spaces.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>
#include <mpllibs/metaparse/get_remaining.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/test_suite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::test_suite;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::spaces;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_remaining;

using boost::mpl::list_c;
using boost::mpl::apply;
using boost::mpl::not_;
using boost::mpl::equal;

namespace
{
  const test_suite suite("spaces");
  
  typedef list_c<char, 'e', 'l', 'l', 'o'> str_ello;
  typedef
    list_c<char, ' ', '\t', '\n', '\r', 'e', 'l', 'l', 'o'>
    str_____ello;

  typedef is_error<apply<spaces, str_hello, start> > test_reject_no_space;

  typedef
    not_<is_error<apply<spaces, str__ello, start> > >
    test_accept_one_space;

  typedef
    equal<get_remaining<apply<spaces, str__ello, start> >::type, str_ello>
    test_accept_only_space;

  typedef
    not_<is_error<apply<spaces, str_____ello, start> > >
    test_accept_all_spaces;

  typedef
    equal<get_remaining<apply<spaces, str_____ello, start> >::type, str_ello>
    test_consume_all_spaces;
}

MPLLIBS_ADD_TEST(suite, test_reject_no_space)
MPLLIBS_ADD_TEST(suite, test_accept_one_space)
MPLLIBS_ADD_TEST(suite, test_accept_only_space)
MPLLIBS_ADD_TEST(suite, test_accept_all_spaces)
MPLLIBS_ADD_TEST(suite, test_consume_all_spaces)


