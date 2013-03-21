// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/foldrp.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/string.hpp>

#include "common.hpp"

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/char.hpp>
#include <boost/mpl/assert.hpp>

#include <boost/test/unit_test.hpp>

namespace
{
  struct keep_state
  {
    typedef keep_state type;

    template <class C, class S>
    struct apply : S {};
  };
}

BOOST_AUTO_TEST_CASE(test_foldrp)
{
  using mpllibs::metaparse::foldrp;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::lit_c;
  using mpllibs::metaparse::get_result;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;
  using boost::mpl::char_;

  typedef foldrp<lit_c<'a'>, lit_c<'b'>, keep_state> p;

  // test_b
  BOOST_MPL_ASSERT((
    equal_to<get_result<apply_wrap2<p, str_b, start> >::type, char_<'b'> >
  ));
  
  // test_ab
  BOOST_MPL_ASSERT((
    equal_to<get_result<apply_wrap2<p, str_ab, start> >::type, char_<'b'> >
  ));

  // test_aaaab
  BOOST_MPL_ASSERT((
    equal_to<get_result<apply_wrap2<p, str_aaaab, start> >::type, char_<'b'> >
  ));

  // test_c
  BOOST_MPL_ASSERT((is_error<apply_wrap2<p, str_c, start> >));

  // test_ac
  BOOST_MPL_ASSERT((is_error<apply_wrap2<p, str_ac, start> >));
}

