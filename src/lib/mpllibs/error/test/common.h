#ifndef MPLLIBS_ERROR_TEST_COMMON_H
#define MPLLIBS_ERROR_TEST_COMMON_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/int.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/times.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>

namespace
{
  struct x;
  struct y;
  
  typedef boost::mpl::int_<0> int0;
  typedef boost::mpl::int_<1> int1;
  typedef boost::mpl::int_<2> int2;
  typedef boost::mpl::int_<4> int4;
  typedef boost::mpl::int_<9> int9;
  typedef boost::mpl::int_<11> int11;
  typedef boost::mpl::int_<13> int13;
  typedef boost::mpl::int_<24> int24;
  typedef boost::mpl::int_<26> int26;
  typedef boost::mpl::int_<37> int37;

  template <class T>
  struct double_value : boost::mpl::times<T, int2> {};
  
  template <class T>
  struct lazy_double_value : boost::mpl::times<typename T::type, int2> {};
  
  template <class a, class b>
  struct lazy_plus :
    boost::mpl::plus<typename a::type, typename b::type>
  {};

  template <class a, class b>
  struct double_lazy_plus :
    boost::mpl::plus<typename a::type::type, typename b::type::type>
  {};

  template <class a, class b>
  struct lazy_times : boost::mpl::times<typename a::type, typename b::type> {};

  template <class c, class t, class f>
  struct lazy_eval_if : boost::mpl::eval_if<typename c::type, t, f> {};

  template <class a, class b>
  struct lazy_equal_to :
    boost::mpl::equal_to<typename a::type, typename b::type>
  {};

  template <class f, class a1>
  struct lazy_apply : boost::mpl::apply<typename f::type, a1> {};
}

#endif

