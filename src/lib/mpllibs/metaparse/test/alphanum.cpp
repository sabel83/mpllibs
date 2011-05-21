// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/alphanum.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/source_position.h>

#include "common.h"

#include <mpllibs/metatest/test.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>

using mpllibs::metatest::suite_path;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::alphanum;
using mpllibs::metaparse::start;
using mpllibs::metaparse::digit;
using mpllibs::metaparse::is_error;

using boost::mpl::list_c;
using boost::mpl::equal_to;
using boost::mpl::apply;

namespace
{
  const suite_path suite("alphanum");

  typedef list_c<char, '.', '.', ','> other_string;
  
  typedef
    equal_to<get_result<apply<alphanum, str_hello, start> >::type, char_h>
    test_with_text;
   
  typedef
    equal_to<get_result<apply<digit, str_1983, start> >::type, char_1>
    test_with_number;

  typedef is_error<apply<digit, other_string, start> > test_with_non_alphanum;

  typedef is_error<apply<digit, str_, start> > test_with_empty_string;
}

MPLLIBS_ADD_TEST(suite, test_with_text)
MPLLIBS_ADD_TEST(suite, test_with_number)
MPLLIBS_ADD_TEST(suite, test_with_non_alphanum)
MPLLIBS_ADD_TEST(suite, test_with_empty_string)


