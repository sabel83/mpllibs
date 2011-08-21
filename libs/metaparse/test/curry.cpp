// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/util/curry.hpp>

#include "common.hpp"

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/has_type.hpp>
#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/identity.hpp>

using mpllibs::metatest::suite_path;
using mpllibs::metatest::has_type;

using mpllibs::metaparse::util::curry0;
using mpllibs::metaparse::util::curry2;

using boost::mpl::identity;
using boost::mpl::equal_to;
using boost::mpl::apply_wrap1;

namespace
{
  const suite_path suite = suite_path("util")("curry");
  
  template <class A, class B>
  struct get_first : identity<A>
  {
    struct to_stream
    {
      static std::ostream& run(std::ostream& o)
      {
        o << "get_first<";
        mpllibs::metatest::to_stream_argument_list<A, B>::run(o);
        return o << ">";
      }
    };
  };
  
  template <class A, class B>
  struct get_second : identity<B>
  {
    struct to_stream
    {
      static std::ostream& run(std::ostream& o)
      {
        o << "get_second<";
        mpllibs::metatest::to_stream_argument_list<A, B>::run(o);
        return o << ">";
      }
    };
  };
  
  typedef identity<int13> nullary_metafunction;
  
  typedef has_type<curry2<get_second> > test_has_type;

  typedef
    equal_to<
      apply_wrap1<apply_wrap1<curry2<get_first>, int11>::type, int13>::type,
      int11
    >
    test_currying_first_argument;

  typedef
    equal_to<
      apply_wrap1<apply_wrap1<curry2<get_second>, int11>::type, int13>::type,
      int13
    >
    test_currying_second_argument;

  typedef equal_to<curry0<nullary_metafunction>::type, int13> test_nullary;
}

MPLLIBS_ADD_TEST(suite, test_has_type)
MPLLIBS_ADD_TEST(suite, test_currying_first_argument)
MPLLIBS_ADD_TEST(suite, test_currying_second_argument)
MPLLIBS_ADD_TEST(suite, test_nullary)

