// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/exception.hpp>
#include <mpllibs/metamonad/do.hpp>
#include <mpllibs/metamonad/get_data.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/always.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <boost/type_traits/is_same.hpp>

#include "common.hpp"

namespace
{
  struct x;
}

BOOST_AUTO_TEST_CASE(test_exception)
{
  using mpllibs::metatest::meta_require;

  using boost::is_same;
  
  using boost::mpl::equal_to;
  using boost::mpl::always;
  using boost::mpl::apply;
  using boost::mpl::apply_wrap1;
  using boost::mpl::tag;
  using boost::mpl::not_;
  
  using mpllibs::metamonad::exception;
  using mpllibs::metamonad::get_data;
  using mpllibs::metamonad::exception_monad;
  using mpllibs::metamonad::return_;
  using mpllibs::metamonad::do_;
  using mpllibs::metamonad::set;
  using mpllibs::metamonad::do_return;

  typedef exception<int13> e;

  typedef equal_to<int13, get_data<e>::type> test_get_data;

  meta_require<
    equal_to<
      int13,
      do_<exception_monad>::apply<
        do_return<int13>
      >::type
    >
  >(MPLLIBS_HERE, "test_monadic_no_exception");

  meta_require<
    equal_to<
      int13,
      get_data<
        do_<exception_monad>::apply<
          apply_wrap1<always<e>, int>
        >::type
      >::type
    >
  >(MPLLIBS_HERE, "test_monadic_exception");


  meta_require<
    equal_to<
      int13,
      get_data<
        do_<exception_monad>::apply<
          apply_wrap1<always<e>, int>,
          do_return<int13>
        >::type
      >::type
    >
  >(MPLLIBS_HERE, "test_exception_propagation");


  meta_require<
    is_same<int13, return_<exception_monad, int13>::type>
  >(MPLLIBS_HERE, "test_return_value");

  meta_require<
    is_same<
      int11,
      do_<exception_monad>::apply<
        do_return<int11>
      >::type
    >
  >(MPLLIBS_HERE, "test_return_with_1_element_do");

  meta_require<
    equal_to<
      int11,
        do_<exception_monad>::apply<
          do_return<int13>,
          do_return<int11>
        >::type
    >
  >(MPLLIBS_HERE, "test_execution_sequence");
  
  meta_require<
    equal_to<
      int13,
      get_data<
        do_<exception_monad>::apply<
          set<x, apply_wrap1<always<e>, int> >,
          do_return<int13>
        >::type
      >::type
    >
  >(MPLLIBS_HERE, "test_exception_in_set");

  meta_require<
    equal_to<exception<int13>, exception<int13> >
  >(MPLLIBS_HERE, "test_compare_equal_exceptions");

  meta_require<
    not_<equal_to<exception<int11>, exception<int13> > >
  >(MPLLIBS_HERE, "test_compare_not_equal_exceptions");
}

