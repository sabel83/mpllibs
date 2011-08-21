// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/util/id.hpp>

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

using boost::mpl::int_;
using boost::mpl::equal_to;

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::util::id;

using std::string;

namespace
{
  const suite_path suite = suite_path("util")("id");

  typedef int_<13> int13;

  typedef equal_to<int13, id<int13>::type> test_identity;
}

MPLLIBS_ADD_TEST(suite, test_identity)

