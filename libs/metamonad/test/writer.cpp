// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/writer.hpp>
#include <mpllibs/metamonad/list.hpp>

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/to_stream.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>

#include "common.hpp"

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::writer_tag;
using mpllibs::metamonad::list_tag;
using mpllibs::metamonad::monad;

using boost::mpl::equal_to;
using boost::mpl::equal;
using boost::mpl::apply;
using boost::mpl::pair;
using boost::mpl::plus;
using boost::mpl::list;

namespace
{
  const suite_path suite("writer");
  
  typedef writer_tag<list_tag> list_writer_tag;
  
  typedef apply<monad<list_writer_tag>::return_, int11>::type return11;
  
  template <class A>
  struct log_plus
  {
    typedef log_plus type;
    
    template <class R>
    struct apply : pair<plus<A, R>, list<A> > {};
  };

  typedef equal_to<int11, return11::first> test_return_value;
  
  typedef equal<list<>, return11::second> test_return_log;

  typedef
    equal_to<
      int13,
      apply<
        monad<list_writer_tag>::bind,
        return11,
        log_plus<int2>
      >::type::first
    >
    test_bind_value;

  typedef
    equal<
      list<int2>,
      apply<
        monad<list_writer_tag>::bind,
        return11,
        log_plus<int2>
      >::type::second
    >
    test_bind_log;
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, log_plus, "log_plus")

MPLLIBS_ADD_TEST(suite, test_return_value)
MPLLIBS_ADD_TEST(suite, test_return_log)
MPLLIBS_ADD_TEST(suite, test_bind_value)
MPLLIBS_ADD_TEST(suite, test_bind_log)




