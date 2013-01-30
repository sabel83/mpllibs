// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/return_.hpp>
#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include "common.hpp"

#include <boost/mpl/equal.hpp>

using boost::mpl::list;

using mpllibs::metamonad::lambda_c;
using namespace mpllibs::metamonad::name;

namespace
{
  typedef lambda_c<t, list<t, t> > twice;
}

BOOST_AUTO_TEST_CASE(test_list_monad)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::return_;
  using mpllibs::metamonad::bind;
  using mpllibs::metamonad::list_tag;
  
  using boost::mpl::equal;
  
  meta_require<
    equal<return_<list_tag, int13>, list<int13> >
  >(MPLLIBS_HERE, "test_return");

  meta_require<
    equal<
      bind<list_tag, list<int13, int11>, twice>::type,
      list<int13, int13, int11, int11>
    >
  >(MPLLIBS_HERE, "test_bind");
}

