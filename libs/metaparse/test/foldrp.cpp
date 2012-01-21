// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/foldrp.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/string.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/char.hpp>

#include <mpllibs/metatest/boost_test.hpp>
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
  using mpllibs::metatest::has_type;
  using mpllibs::metatest::meta_require;
  
  using mpllibs::metaparse::foldrp;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::lit_c;
  using mpllibs::metaparse::get_result;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;
  using boost::mpl::char_;

  typedef foldrp<lit_c<'a'>, lit_c<'b'>, keep_state> p;

  meta_require<has_type<p> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal_to<get_result<apply_wrap2<p, str_b, start> >::type, char_<'b'> >
  >(MPLLIBS_HERE, "test_b");
  
  meta_require<
    equal_to<get_result<apply_wrap2<p, str_ab, start> >::type, char_<'b'> >
  >(MPLLIBS_HERE, "test_ab");

  meta_require<
    equal_to<get_result<apply_wrap2<p, str_aaaab, start> >::type, char_<'b'> >
  >(MPLLIBS_HERE, "test_aaaab");

  meta_require<
    is_error<apply_wrap2<p, str_c, start> >
  >(MPLLIBS_HERE, "test_c");

  meta_require<
    is_error<apply_wrap2<p, str_ac, start> >
  >(MPLLIBS_HERE, "test_ac");
}

