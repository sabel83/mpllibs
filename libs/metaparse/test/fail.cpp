// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/fail.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>

#include <mpllibs/metaparse/util/define_data.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::fail;
using mpllibs::metaparse::start;

using boost::mpl::apply;

namespace
{
  const suite_path suite("fail");

  MPLLIBS_METAPARSE_DEFINE_DATA(test_error);

  typedef
    is_error<apply<fail<test_error>, str_hello, start> >
    test_fail_for_non_empty_string;
}

MPLLIBS_ADD_TEST(suite, test_fail_for_non_empty_string)


