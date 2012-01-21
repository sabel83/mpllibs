// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/spaces.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/equal.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

namespace
{
  using boost::mpl::list_c;

  typedef list_c<char, 'e', 'l', 'l', 'o'> str_ello;
  typedef
    list_c<char, ' ', '\t', '\n', '\r', 'e', 'l', 'l', 'o'>
    str_____ello;

}

BOOST_AUTO_TEST_CASE(test_spaces)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::spaces;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_remaining;
  
  using boost::mpl::apply_wrap2;
  using boost::mpl::not_;
  using boost::mpl::equal;

  meta_require<has_type<spaces> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    is_error<apply_wrap2<spaces, str_hello, start> >
  >(MPLLIBS_HERE, "test_reject_no_space");

  meta_require<
    not_<is_error<apply_wrap2<spaces, str__ello, start> > >
  >(MPLLIBS_HERE, "test_accept_one_space");

  meta_require<
    equal<get_remaining<apply_wrap2<spaces, str__ello, start> >::type, str_ello>
  >(MPLLIBS_HERE, "test_accept_only_space");

  meta_require<
    not_<is_error<apply_wrap2<spaces, str_____ello, start> > >
  >(MPLLIBS_HERE, "test_accept_all_spaces");

  meta_require<
    equal<
      get_remaining<apply_wrap2<spaces, str_____ello, start> >::type,
      str_ello
    >
  >(MPLLIBS_HERE, "test_consume_all_spaces");
}


