// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/safe_printf/verify_printf_arguments.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/string.hpp>
#include <boost/mpl/not.hpp>

namespace
{
  // lazy not
  template <class T>
  struct not_ : boost::mpl::not_<typename T::type> {};
}

BOOST_AUTO_TEST_CASE(test_verify_printf_arguments)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::safe_printf::verify_printf_arguments;

  using boost::mpl::vector;
  using boost::mpl::string;

  meta_require<
    verify_printf_arguments<string<>, vector<> >
  >(MPLLIBS_HERE, "Check empty format string");

  meta_require<
    verify_printf_arguments<string<'Hell','o'>, vector<> >
  >(MPLLIBS_HERE, "Check format string with no placeholders");

  meta_require<
    verify_printf_arguments<string<'%d'>, vector<int> >
  >(MPLLIBS_HERE, "Check format string with one placeholder");

  meta_require<
    verify_printf_arguments<string<'%d  ', '%f'>, vector<int, double> >
  >(MPLLIBS_HERE, "Check format string with two placeholders");

  meta_require<
    not_<verify_printf_arguments<string<'%d'>, vector<int, double> > >
  >(MPLLIBS_HERE, "Check format string with too few placeholders");

  meta_require<
    not_<verify_printf_arguments<string<'%d ', '%f'>, vector<int> > >
  >(MPLLIBS_HERE, "Check format string with too many placeholders");

  meta_require<
    not_<verify_printf_arguments<string<'%d'>, vector<double> > >
  >(MPLLIBS_HERE, "Check format string with invalid placeholder");
}

