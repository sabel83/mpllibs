// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/nothing.hpp>
#include <mpllibs/metamonad/is_nothing.hpp>

#include <mpllibs/metatest/test.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::nothing;
using mpllibs::metamonad::is_nothing;

using boost::mpl::equal_to;

namespace
{
  const suite_path suite("nothing");
  
  typedef equal_to<nothing, nothing> test_compare_nothing_to_nothing;

  typedef is_nothing<nothing> test_is_nothing;
}

MPLLIBS_ADD_TEST(suite, test_compare_nothing_to_nothing)
MPLLIBS_ADD_TEST(suite, test_is_nothing)


