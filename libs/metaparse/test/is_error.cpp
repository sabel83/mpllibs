// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/fail.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/not.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_is_error)
{
  using mpllibs::metatest::meta_require;
  using mpllibs::metatest::has_type;
  
  using mpllibs::metaparse::is_error;
  using mpllibs::metaparse::fail;
  
  using boost::mpl::not_;
  using boost::mpl::apply_wrap2;

  meta_require<not_<is_error<int13> > >(MPLLIBS_HERE, "test_not_error");

  meta_require<
    is_error<apply_wrap2<fail<int11>, int1, int13> >
  >(MPLLIBS_HERE, "test_error");
}

