// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/except.hpp>
#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/fail.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <mpllibs/metaparse/util/define_data.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::except;
using mpllibs::metaparse::one_char;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_result;
using mpllibs::metaparse::fail;

using boost::mpl::apply;
using boost::mpl::equal_to;

namespace
{
  const suite_path suite("except");

  MPLLIBS_METAPARSE_DEFINE_DATA(test_error);

  typedef
    is_error<apply<except<one_char, int13, test_error>, str_hello, start> >
    test_with_good;
  
  typedef
    equal_to<
      get_result<
        apply<except<fail<test_error>, int13, test_error>, str_hello, start>
      >::type,
      int13
    >
    test_with_bad;
}

MPLLIBS_ADD_TEST(suite, test_with_good)
MPLLIBS_ADD_TEST(suite, test_with_bad)


