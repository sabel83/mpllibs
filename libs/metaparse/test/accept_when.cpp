// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/accept_when.hpp>
#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>

#include "common.hpp"

#include <mpllibs/metaparse/util/is_digit.hpp>

#include <mpllibs/metamonad/meta_atom.hpp>

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::is_error;
using mpllibs::metaparse::accept_when;
using mpllibs::metaparse::one_char;
using mpllibs::metaparse::start;
using mpllibs::metaparse::get_result;
using mpllibs::metaparse::error_tag;

using mpllibs::metaparse::util::is_digit;

using boost::mpl::apply;
using boost::mpl::equal_to;
using boost::mpl::apply_wrap2;

namespace
{
  const suite_path suite("accept_when");

  MPLLIBS_DEFINE_META_ATOM(error_tag, test_error)

  typedef has_type<accept_when<one_char, is_digit, test_error> > test_has_type;

  typedef
    is_error<
      apply_wrap2<accept_when<one_char, is_digit, test_error>, str_hello, start>
    >
    test_with_text;
  
  typedef
    equal_to<
      get_result<
        apply_wrap2<
          accept_when<one_char, is_digit, test_error>,
          str_1983,
          start
        >
      >::type,
      char_1
    >
    test_with_number;

  typedef
    is_error<
      apply_wrap2<accept_when<one_char, is_digit, test_error>, str_, start>
    >
    test_with_empty_string;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_with_text)
MPLLIBS_ADD_TEST(suite, test_with_number)
MPLLIBS_ADD_TEST(suite, test_with_empty_string)

