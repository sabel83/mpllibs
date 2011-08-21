// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/alphanum.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::alphanum;
using mpllibs::metaparse::start;
using mpllibs::metaparse::digit;
using mpllibs::metaparse::is_error;

using boost::mpl::list_c;
using boost::mpl::equal_to;
using boost::mpl::apply_wrap2;

namespace
{
  const suite_path suite("alphanum");

  typedef list_c<char, '.', '.', ','> other_string;
  
  typedef has_type<alphanum> test_has_type;

  typedef
    equal_to<get_result<apply_wrap2<alphanum, str_hello, start> >::type, char_h>
    test_with_text;
   
  typedef
    equal_to<get_result<apply_wrap2<digit, str_1983, start> >::type, char_1>
    test_with_number;

  typedef
    is_error<apply_wrap2<digit, other_string, start> >
    test_with_non_alphanum;

  typedef is_error<apply_wrap2<digit, str_, start> > test_with_empty_string;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_with_text)
MPLLIBS_ADD_TEST(suite, test_with_number)
MPLLIBS_ADD_TEST(suite, test_with_non_alphanum)
MPLLIBS_ADD_TEST(suite, test_with_empty_string)


