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
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::fail;
using mpllibs::metaparse::start;

using boost::mpl::apply_wrap2;

namespace
{
  const suite_path suite("fail");

  MPLLIBS_METAPARSE_DEFINE_DATA(test_error);

  typedef has_type<fail<test_error> > test_has_type;

  typedef
    is_error<apply_wrap2<fail<test_error>, str_hello, start> >
    test_fail_for_non_empty_string;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_fail_for_non_empty_string)


