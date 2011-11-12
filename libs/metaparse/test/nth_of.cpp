// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nth_of.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/source_position.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_nth_of)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::nth_of_c;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::nth_of;
  using mpllibs::metaparse::is_error;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply_wrap2;

  namespace mpl = boost::mpl;
  namespace mp = mpllibs::metaparse;

  meta_require<has_type<nth_of_c<0, lit_h> > >(MPLLIBS_HERE, "test_has_type_c");
  meta_require<has_type<nth_of<int0, lit_h> > >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    equal_to<
      get_result<apply_wrap2<nth_of_c<0, lit_h>, str_hello, start> >::type,
      char_h
    >
  >(MPLLIBS_HERE, "test_first_of_one");

  meta_require<
    equal_to<
      get_result<
        apply_wrap2<nth_of_c<0, lit_h, lit_e>, str_hello, start>
      >::type,
      char_h
    >
  >(MPLLIBS_HERE, "test_first_of_two");

  meta_require<
    equal_to<
      get_result<
        apply_wrap2<nth_of<int1, lit_h, lit_e>, str_hello, start>
      >::type,
      char_e
    >
  >(MPLLIBS_HERE, "test_second_of_two");

  meta_require<
    is_error<apply_wrap2<nth_of_c<1, lit_x, lit_e>, str_hello, start> >
  >(MPLLIBS_HERE, "test_nothing");
  
  meta_require<
    is_error<apply_wrap2<nth_of_c<0>, str_hello, start> >
  >(MPLLIBS_HERE, "test_first_of_none");

  meta_require<
    is_error<apply_wrap2<nth_of_c<-1, lit_h, lit_e>, str_hello, start> >
  >(MPLLIBS_HERE, "test_n_is_less_than_zero");

  meta_require<
    is_error<apply_wrap2<nth_of_c<2, lit_h, lit_e>, str_hello, start> >
  >(MPLLIBS_HERE, "test_n_is_greater_than_the_number_of_parsers");

  meta_require<
    is_error<apply_wrap2<nth_of_c<1, lit_x, lit_e, lit_l>, str_hello, start> >
  >(MPLLIBS_HERE, "test_error_before_the_nth");

  meta_require<
    is_error<apply_wrap2<nth_of_c<1, lit_h, lit_x, lit_l>, str_hello, start> >
  >(MPLLIBS_HERE, "test_error_at_the_nth");

  meta_require<
    is_error<apply_wrap2<nth_of_c<1, lit_h, lit_e, lit_x>, str_hello, start> >
  >(MPLLIBS_HERE, "test_error_after_the_nth");
}

