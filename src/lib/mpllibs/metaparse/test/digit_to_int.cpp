// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/digit_to_int.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::util::digit_to_int;

using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const suite_path suite = suite_path("util")("digit_to_int");

  typedef equal_to<apply<digit_to_int, char_0>::type, int0> test0;

  typedef equal_to<apply<digit_to_int, char_9>::type, int9> test9;
}

MPLLIBS_ADD_TEST(suite, test0)
MPLLIBS_ADD_TEST(suite, test9)


