// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metamonad/writer.hpp>
#include <mpllibs/metamonad/list.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/pair.hpp>
#include <mpllibs/metamonad/apply.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"

using boost::mpl::list;
using boost::mpl::plus;

using mpllibs::metamonad::tmp_value;
using mpllibs::metamonad::lambda_c;
using mpllibs::metamonad::pair;

using namespace mpllibs::metamonad::name;
  
namespace
{
  MPLLIBS_METAFUNCTION(log_plus, (A))
  ((lambda_c<r, pair<plus<A,r>, list<A> > >));
}

BOOST_AUTO_TEST_CASE(test_writer)
{
  using mpllibs::metamonad::writer_tag;
  using mpllibs::metamonad::list_tag;
  using mpllibs::metamonad::monad;
  using mpllibs::metamonad::apply;
  
  using boost::mpl::equal_to;
  using boost::mpl::equal;

  typedef writer_tag<list_tag> list_writer_tag;
  
  typedef apply<monad<list_writer_tag>::return_, int11>::type return11;
  
  // test_return_value
  BOOST_MPL_ASSERT((equal_to<int11, return11::first>));
  
  // test_return_log
  BOOST_MPL_ASSERT((equal<list<>, return11::second>));

  // test_bind_value
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      apply<
        monad<list_writer_tag>::bind,
        return11,
        log_plus<int2>
      >::type::first
    >
  ));

  // test_bind_log
  BOOST_MPL_ASSERT((
    equal<
      list<int2>,
      apply<
        monad<list_writer_tag>::bind,
        return11,
        log_plus<int2>
      >::type::second
    >
  ));
}


