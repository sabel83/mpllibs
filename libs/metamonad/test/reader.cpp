// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/reader.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/make_tmp_value.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/quote.hpp>

#include "common.hpp"

using boost::mpl::plus;

using mpllibs::metamonad::tmp_value;
using mpllibs::metamonad::lambda_c;
using namespace mpllibs::metamonad::name;

namespace
{
  MPLLIBS_METAFUNCTION(fplus, (A)) ((lambda_c<r, plus<A, r> >));
}

BOOST_AUTO_TEST_CASE(test_reader)
{
  using mpllibs::metatest::meta_require;

  using mpllibs::metamonad::reader_tag;
  using mpllibs::metamonad::monad;
  using mpllibs::metamonad::make_tmp_value;
  
  using boost::mpl::equal_to;
  using boost::mpl::apply;
  using boost::mpl::int_;
  using boost::mpl::quote1;

  typedef int_<22> int22;
  typedef apply<monad<reader_tag>::return_, int11>::type return11;

  meta_require<
    equal_to<int11, apply<return11, int13>::type>
  >(MPLLIBS_HERE, "test_return");
  
  meta_require<
    equal_to<
      int22,
      apply<
        apply<
          monad<reader_tag>::bind,
          return11,
          make_tmp_value<quote1<fplus> >
        >::type,
        int11
      >::type
    >
  >(MPLLIBS_HERE, "test_bind");
}




