// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/reader.hpp>

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/to_stream.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/quote.hpp>

#include "common.hpp"

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::reader_tag;
using mpllibs::metamonad::monad;

using boost::mpl::equal_to;
using boost::mpl::apply;
using boost::mpl::plus;
using boost::mpl::int_;
using boost::mpl::quote1;

namespace
{
  const suite_path suite("reader");
  
  typedef int_<22> int22;
  typedef apply<monad<reader_tag>::return_, int11>::type return11;
  
  template <class A>
  struct fplus
  {
    typedef fplus type;
    
    template <class R>
    struct apply : plus<A, R> {};
  };


  typedef equal_to<int11, apply<return11, int13>::type> test_return;
  
  typedef
    equal_to<
      int22,
      apply<
        apply<monad<reader_tag>::bind, return11, quote1<fplus> >::type,
        int11
      >::type
    >
    test_bind;
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, fplus, "fplus")

MPLLIBS_ADD_TEST(suite, test_return)
MPLLIBS_ADD_TEST(suite, test_bind)




