// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/unless_error.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::fail;
using mpllibs::metaparse::is_error;

using mpllibs::metaparse::util::unless_error;

using boost::mpl::apply;
using boost::mpl::equal_to;

namespace
{
  const suite_path suite = suite_path("util")("unless_error");
  
  typedef apply<fail<int1>, int11, int2> err;
  
  typedef has_type<unless_error<err, int13> > test_has_type;

  typedef is_error<unless_error<err, int13> > test_error;

  typedef equal_to<int13, unless_error<int11, int13>::type> test_not_error;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_error)
MPLLIBS_ADD_TEST(suite, test_not_error)

