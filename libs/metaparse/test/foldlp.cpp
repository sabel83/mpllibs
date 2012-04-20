// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/foldlp.hpp>
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

BOOST_AUTO_TEST_CASE(test_foldlp)
{
  using mpllibs::metatest::has_type;
  using mpllibs::metatest::meta_require;
  
  using mpllibs::metaparse::foldlp;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::lit_c;
  using mpllibs::metaparse::get_result;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;
  using boost::mpl::char_;

  typedef foldlp<lit_c<'a'>, lit_c<'b'>, keep_state> p;

  meta_require<has_type<p> >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal_to<get_result<apply_wrap2<p, str_b, start> >::type, char_<'b'> >
  >(MPLLIBS_HERE, "test_b");
  
  meta_require<
    equal_to<get_result<apply_wrap2<p, str_ba, start> >::type, char_<'b'> >
  >(MPLLIBS_HERE, "test_ba");

  meta_require<
    equal_to<get_result<apply_wrap2<p, str_baaaa, start> >::type, char_<'b'> >
  >(MPLLIBS_HERE, "test_baaaa");

  meta_require<
    is_error<apply_wrap2<p, str_c, start> >
  >(MPLLIBS_HERE, "test_c");

  meta_require<
    is_error<apply_wrap2<p, str_ca, start> >
  >(MPLLIBS_HERE, "test_ca");
}

// Test foldlp as a normal fold

using mpllibs::metaparse::foldlp;
using mpllibs::metaparse::return_;

using boost::mpl::vector;
using boost::mpl::push_back;
using boost::mpl::_1;
using boost::mpl::_2;
using boost::mpl::lambda;

namespace
{ 
  template <class P>
  struct any :
    foldlp<P, return_<vector<> >, lambda<push_back<_2, _1> >::type>
  {};
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, any, "::any")

#define DEFINE_TEST_CASE BOOST_AUTO_TEST_CASE(test_foldlp_as_foldl)

#include "any_test.hpp"  

