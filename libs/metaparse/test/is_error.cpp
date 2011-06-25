// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/fail.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/not.hpp>
#include <boost/mpl/apply_wrap.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::fail;

using boost::mpl::not_;
using boost::mpl::apply_wrap2;

namespace
{
  const suite_path suite("is_error");
  
  typedef not_<is_error<int13> > test_not_error;

  typedef is_error<apply_wrap2<fail<int11>, int1, int13> > test_error;
}

MPLLIBS_ADD_TEST(suite, test_not_error)
MPLLIBS_ADD_TEST(suite, test_error)


