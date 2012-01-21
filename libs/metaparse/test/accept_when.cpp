// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

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

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

namespace
{
  MPLLIBS_DEFINE_TAG(test_error_tag)
  MPLLIBS_DEFINE_META_ATOM(test_error_tag, test_error)
}

BOOST_AUTO_TEST_CASE(test_accept_when)
{
  using mpllibs::metatest::has_type;
  using mpllibs::metatest::meta_require;

  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::accept_when;
  using mpllibs::metaparse::one_char;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::get_result;

  using mpllibs::metaparse::util::is_digit;

  using boost::mpl::apply;
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;

  meta_require<
    has_type<accept_when<one_char, is_digit, test_error> >
  >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    is_error<
      apply_wrap2<accept_when<one_char, is_digit, test_error>, str_hello, start>
    >
  >(MPLLIBS_HERE, "test_with_text");
  
  meta_require<
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
  >(MPLLIBS_HERE, "test_with_number");

  meta_require<
    is_error<
      apply_wrap2<accept_when<one_char, is_digit, test_error>, str_, start>
    >
  >(MPLLIBS_HERE, "test_with_empty_string");
}

