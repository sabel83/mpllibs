// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/util/compose.hpp>

#include "common.hpp"

#include <mpllibs/metatest/has_type.hpp>

#include <boost/mpl/identity.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <boost/type_traits/is_same.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

namespace
{
  using std::ostream;

  using boost::mpl::identity;
  using boost::mpl::plus;
  using boost::mpl::times;

  struct make_pointer
  {
    template <class T>
    struct apply : identity<T*> {};
  };
  
  struct incr
  {
    template <class T>
    struct apply : plus<int13, T> {};
  };

  struct double_value
  {
    template <class T>
    struct apply : times<int2, T> {};
  };

  struct take_first
  {
    template <class A, class B>
    struct apply : identity<A> {};
  };
}

MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(make_pointer)
MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(incr)
MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(double_value)
MPLLIBS_DEFINE_TO_STREAM_FOR_SIMPLE_TYPE(take_first)

BOOST_AUTO_TEST_CASE(test_compose)
{
  using mpllibs::metatest::has_type;
  using mpllibs::metatest::meta_require;
  
  using mpllibs::metaparse::util::compose;
  
  using boost::mpl::apply_wrap1;
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal_to;
  
  using boost::is_same;

  meta_require<
    has_type<compose<make_pointer, make_pointer> >
  >(MPLLIBS_HERE, "test_has_type");

  meta_require<
    is_same<apply_wrap1<compose<make_pointer, make_pointer>, int>::type, int**>
  >(MPLLIBS_HERE, "test_same_function_twice");

  meta_require<
    is_same<
      apply_wrap1<
        compose<
          make_pointer,
          make_pointer,
          make_pointer,
          make_pointer,
          make_pointer
        >,
        int
      >::type,
      int*****
    >
  >(MPLLIBS_HERE, "test_same_function_five_times");

  meta_require<
    equal_to<apply_wrap1<compose<double_value, incr>, int1>::type, int28>
  >(MPLLIBS_HERE, "test_order");

  meta_require<
    equal_to<
      apply_wrap2<compose<double_value, take_first>, int1, int3>::type,
      int2
    >
  >(MPLLIBS_HERE, "test_two_arguments_for_the_first_function");
}


