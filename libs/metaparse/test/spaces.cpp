// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/spaces.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/equal.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

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
  const suite_path suite("spaces");
  
  typedef list_c<char, 'e', 'l', 'l', 'o'> str_ello;
  typedef
    list_c<char, ' ', '\t', '\n', '\r', 'e', 'l', 'l', 'o'>
    str_____ello;

  typedef has_type<spaces> test_has_type;

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

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_reject_no_space)
MPLLIBS_ADD_TEST(suite, test_accept_one_space)
MPLLIBS_ADD_TEST(suite, test_accept_only_space)
MPLLIBS_ADD_TEST(suite, test_accept_all_spaces)
MPLLIBS_ADD_TEST(suite, test_consume_all_spaces)


