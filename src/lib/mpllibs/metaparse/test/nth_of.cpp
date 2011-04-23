// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nth_of.h>
#include <mpllibs/metaparse/is_error.h>
#include <mpllibs/metaparse/get_result.h>
#include <mpllibs/metaparse/source_position.h>

#include "common.h"

#include <mpllibs/metatest/test.h>
#include <mpllibs/metatest/TestSuite.h>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/int.hpp>

using mpllibs::metatest::TestSuite;

using mpllibs::metaparse::get_result;
using mpllibs::metaparse::nth_of_c;
using mpllibs::metaparse::start;
using mpllibs::metaparse::nth_of;
using mpllibs::metaparse::is_error;

using boost::mpl::equal_to;
using boost::mpl::apply;
using boost::mpl::int_;

namespace mpl = boost::mpl;
namespace mp = mpllibs::metaparse;

namespace
{
  const TestSuite suite("nth_of");
  
  typedef
    equal_to<
      get_result<apply<nth_of_c<0, lit_h>, str_hello, start> >::type,
      char_h
    >
    test_first_of_one;

  typedef
    equal_to<
      get_result<apply<nth_of_c<0, lit_h, lit_e>, str_hello, start> >::type,
      char_h
    >
    test_first_of_two;

  typedef
    equal_to<
      get_result<apply<nth_of<int_<1>, lit_h, lit_e>, str_hello, start> >::type,
      char_e
    >
    test_second_of_two;

  typedef
    is_error<apply<nth_of_c<1, lit_x, lit_e>, str_hello, start> >
    test_nothing;
  
  typedef is_error<apply<nth_of_c<0>, str_hello, start> > test_first_of_none;

  typedef
    is_error<apply<nth_of_c<-1, lit_h, lit_e>, str_hello, start> >
    test_n_is_less_than_zero;

  typedef
    is_error<apply<nth_of_c<2, lit_h, lit_e>, str_hello, start> >
    test_n_is_greater_than_the_number_of_parsers;

  typedef
    is_error<apply<nth_of_c<1, lit_x, lit_e, lit_l>, str_hello, start> >
    test_error_before_the_nth;

  typedef
    is_error<apply<nth_of_c<1, lit_h, lit_x, lit_l>, str_hello, start> >
    test_error_at_the_nth;

  typedef
    is_error<apply<nth_of_c<1, lit_h, lit_e, lit_x>, str_hello, start> >
    test_error_after_the_nth;
}

MPLLIBS_ADD_TEST(suite, test_first_of_one)
MPLLIBS_ADD_TEST(suite, test_first_of_two)
MPLLIBS_ADD_TEST(suite, test_second_of_two)
MPLLIBS_ADD_TEST(suite, test_nothing)

MPLLIBS_ADD_TEST(suite, test_first_of_none)
MPLLIBS_ADD_TEST(suite, test_n_is_less_than_zero)
MPLLIBS_ADD_TEST(suite, test_n_is_greater_than_the_number_of_parsers)
MPLLIBS_ADD_TEST(suite, test_error_before_the_nth)
MPLLIBS_ADD_TEST(suite, test_error_at_the_nth)
MPLLIBS_ADD_TEST(suite, test_error_after_the_nth)


