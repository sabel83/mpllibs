// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/try_c.hpp>
#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/is_tag.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/plus.hpp>

#include <boost/type_traits/is_same.hpp>

#include "common.hpp"

using mpllibs::metamonad::tmp_tag;
using mpllibs::metamonad::tmp_value;

namespace
{
  struct tag1 : tmp_tag<tag1> {};
  struct e1 : tmp_value<e1, tag1> {};
  
  struct tag2 : tmp_tag<tag2> {};
  struct e2 : tmp_value<e2, tag2> {};
}

BOOST_AUTO_TEST_CASE(test_try_c)
{
  using mpllibs::metatest::meta_require;

  using boost::mpl::equal_to;
  using boost::mpl::tag;
  using boost::mpl::plus;
  using boost::mpl::true_;
  
  using mpllibs::metamonad::exception;
  using mpllibs::metamonad::try_c;
  using mpllibs::metamonad::catch_;
  using mpllibs::metamonad::catch_c;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::is_tag;

  meta_require<
    equal_to<
      int13,
      try_c<int13, catch_<e, syntax<is_tag<tag1, e> >, syntax<int11> > >::type
    >
  >(MPLLIBS_HERE, "test_no_exception");

  meta_require<
    equal_to<int2, try_c<plus<int1, int1> >::type>
  >(MPLLIBS_HERE, "test_no_exception_no_catch");

  meta_require<
    equal_to<
      int11,
      try_c<
        exception<e1>,
        catch_<e, syntax<is_tag<tag1, e> >, syntax<int11> >
      >::type
    >
  >(MPLLIBS_HERE, "test_catch");

  meta_require<
    equal_to<
      int13,
      try_c<
        exception<int13>,
        catch_<e, syntax<is_tag<tag<int13>::type, e> >, syntax<e> >
      >::type
    >
  >(MPLLIBS_HERE, "test_exception_value_in_catch");

  meta_require<
    equal_to<
      exception<int13>,
      try_c<
        exception<int13>,
        catch_<e, syntax<is_tag<tag2, e> >, syntax<int11> >
      >::type
    >
  >(MPLLIBS_HERE, "test_not_catching");

  meta_require<
    equal_to<
      int13,
      try_c<
        exception<e2>,
        catch_<e, syntax<is_tag<tag1, e> >, syntax<int11> >,
        catch_<e, syntax<is_tag<tag2, e> >, syntax<int13> >
      >::type
    >
  >(MPLLIBS_HERE, "test_second_catch");

  meta_require<
    equal_to<
      exception<int2>,
      try_c<
        plus<int1, exception<int2> >,
        catch_<e, syntax<is_tag<tag1, e> >, syntax<int11> >
      >::type
    >
  >(MPLLIBS_HERE, "test_exception_propagation");

  meta_require<
    equal_to<
      exception<int13>,
      try_c<
        exception<e1>,
        catch_<e, syntax<true_>, syntax<exception<int13> > >
      >::type
    >
  >(MPLLIBS_HERE, "test_rethrowing");

  meta_require<
    equal_to<
      exception<int13>,
      try_c<
        exception<e1>,
        catch_<e, syntax<true_>, syntax<exception<int13> > >,
        catch_<e, syntax<true_>, syntax<exception<int13> > >
      >::type
    >
  >(MPLLIBS_HERE, "test_rethrowing_not_caught_by_next_catch");
}


