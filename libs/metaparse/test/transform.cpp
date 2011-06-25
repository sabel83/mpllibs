// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/any.hpp>
#include <mpllibs/metaparse/one_char.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/lambda.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::transform;
using mpllibs::metaparse::start;
using mpllibs::metaparse::is_error;
using mpllibs::metaparse::any;
using mpllibs::metaparse::one_char;

using boost::mpl::always;
using boost::mpl::equal_to;
using boost::mpl::apply_wrap2;
using boost::mpl::front;
using boost::mpl::_1;

namespace
{
  const suite_path suite("transform");

  typedef always<char_x> f;
  typedef any<one_char> any_one_char;
    
  typedef has_type<transform<lit_h, f> > test_has_type;

  typedef
    equal_to<
      get_result<apply_wrap2<transform<lit_h, f>, str_hello, start> >::type,
      char_x
    >
    test_normal_case;

  typedef
    is_error<apply_wrap2<transform<lit_x, f>, str_hello, start> >
    test_parser_fails;

  typedef
    is_error<apply_wrap2<transform<lit_h, f>, str_, start> >
    test_empty_input;
  
  typedef
    equal_to<
      get_result<
        apply_wrap2<transform<any_one_char, front<_1> >, str_hello, start>
      >::type,
      char_h
    >
    test_tranformation_functions_arg;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_normal_case)
MPLLIBS_ADD_TEST(suite, test_parser_fails)
MPLLIBS_ADD_TEST(suite, test_empty_input)
MPLLIBS_ADD_TEST(suite, test_tranformation_functions_arg)


