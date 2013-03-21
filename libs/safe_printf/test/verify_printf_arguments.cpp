// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/safe_printf/verify_printf_arguments.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/assert.hpp> 

BOOST_AUTO_TEST_CASE(test_verify_printf_arguments)
{
  using mpllibs::safe_printf::verify_printf_arguments;

  using boost::mpl::vector;
  using boost::mpl::string;

  // Check empty format string
  BOOST_MPL_ASSERT((verify_printf_arguments<string<>, vector<> >));

  // Check format string with no placeholders
  BOOST_MPL_ASSERT((verify_printf_arguments<string<'Hell','o'>, vector<> >));

  // Check format string with one placeholder
  BOOST_MPL_ASSERT((verify_printf_arguments<string<'%d'>, vector<int> >));

  // Check format string with two placeholders
  BOOST_MPL_ASSERT((
    verify_printf_arguments<string<'%d  ', '%f'>, vector<int, double> >
  ));

  // Check format string with too few placeholders
  BOOST_MPL_ASSERT_NOT((
    verify_printf_arguments<string<'%d'>, vector<int, double> >
  ));

  // Check format string with too many placeholders
  BOOST_MPL_ASSERT_NOT((
    verify_printf_arguments<string<'%d ', '%f'>, vector<int> >
  ));

  // Check format string with invalid placeholder
  BOOST_MPL_ASSERT_NOT((verify_printf_arguments<string<'%d'>,vector<double> >));
}

