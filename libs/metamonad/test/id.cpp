// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/util/id.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>

using boost::mpl::int_;
using boost::mpl::equal_to;

using mpllibs::metamonad::util::id;

using std::string;

BOOST_AUTO_TEST_CASE(test_util_id)
{
  using mpllibs::metatest::meta_require;

  typedef int_<13> int13;

  meta_require<
    equal_to<int13, id<int13>::type>
  >(MPLLIBS_HERE, "test_identity");
}
