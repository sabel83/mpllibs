// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/one_char_except_c.hpp>

#include "common.hpp"

namespace
{
  typedef mpllibs::metaparse::one_char_except_c<'0', '1'> oc;
}

#include <mpllibs/metatest/boost_test.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <boost/mpl/apply_wrap.hpp>

BOOST_AUTO_TEST_CASE(test_one_char_except_except_c)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::start;

  using boost::mpl::apply_wrap2;
  
  meta_require<
    is_error<apply_wrap2<oc, str_0, start> >
  >(MPLLIBS_HERE, "rejects_except_char");
}

#define TEST_NAME test_one_char_except_c

#include "one_char_test.hpp"


