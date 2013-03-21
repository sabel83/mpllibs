// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/data.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/type_traits.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/assert.hpp>

#include <string>

#include "common.hpp"

namespace
{
  MPLLIBS_DATA(foo, 0, ((con0, 0))((con1, 1))((con2, 1))((con3, 2)));

  MPLLIBS_LAZY_METAFUNCTION(lazy_not, (E)) ((boost::mpl::not_<E>));

  template <char C>
  struct print_c
  {
    typedef print_c type;

    static std::string get_value()
    {
      char s[] = {C, 0};
      return s;
    }
  };
}

BOOST_AUTO_TEST_CASE(test_data)
{
  using mpllibs::metamonad::returns;

  using boost::is_same;

  using boost::mpl::equal_to;
  using boost::mpl::int_;

  // test_type_of_nullary_constructor
  BOOST_MPL_ASSERT((is_same<con0, con0::type>));

  // test_type_of_unary_constructor
  BOOST_MPL_ASSERT((is_same<con1<int>, con1<returns<int> >::type>));

  // test_equality
  BOOST_MPL_ASSERT((equal_to<con1<int_<1> >, con1<int_<1> > >));

  // test_different_constructor_args
  BOOST_MPL_ASSERT((lazy_not<equal_to<con1<int_<1> >, con1<int_<2> > > >));

  // test_different_constructors
  BOOST_MPL_ASSERT((lazy_not<equal_to<con1<int_<1> >, con2<int_<1> > > >));

  // test_nullary_constructor_equality
  BOOST_MPL_ASSERT((equal_to<con0, con0>));

  // test_currying
  BOOST_MPL_ASSERT((
    equal_to<
      con3<int11, int13>,
      con3<>::type::apply<int11>::type::apply<int13>
    >
  ));

  BOOST_CHECK_EQUAL("con0", con0::get_value());
  BOOST_CHECK_EQUAL("con0", con0::value);

  BOOST_CHECK_EQUAL("con1<x>", con1<print_c<'x'> >::get_value());
  BOOST_CHECK_EQUAL("con1<x>", con1<print_c<'x'> >::value);

  BOOST_CHECK_EQUAL(
    "con3<a, b>",
    (con3<print_c<'a'>, print_c<'b'> >::get_value())
  );
  BOOST_CHECK_EQUAL("con3<a, b>", (con3<print_c<'a'>, print_c<'b'> >::value));
}


