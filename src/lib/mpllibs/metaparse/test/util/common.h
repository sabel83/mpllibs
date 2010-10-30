#ifndef MPLLIBS_UTIL_TEST_COMMON_H
#define MPLLIBS_UTIL_TEST_COMMON_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>

typedef boost::mpl::int_<0> int0;
typedef boost::mpl::int_<1> int1;
typedef boost::mpl::int_<2> int2;
typedef boost::mpl::int_<9> int9;
typedef boost::mpl::int_<10> int10;
typedef boost::mpl::int_<11> int11;
typedef boost::mpl::int_<12> int12;
typedef boost::mpl::int_<13> int13;
typedef boost::mpl::int_<14> int14;
typedef boost::mpl::int_<28> int28;

typedef boost::mpl::integral_c<char, '0'> char_0;
typedef boost::mpl::integral_c<char, '7'> char_7;
typedef boost::mpl::integral_c<char, '9'> char_9;
typedef boost::mpl::integral_c<char, 'a'> char_a;
typedef boost::mpl::integral_c<char, 'b'> char_b;
typedef boost::mpl::integral_c<char, 'k'> char_k;
typedef boost::mpl::integral_c<char, 'K'> char_K;
typedef boost::mpl::integral_c<char, ' '> char_space;
typedef boost::mpl::integral_c<char, '\t'> char_tab;
typedef boost::mpl::integral_c<char, '\n'> char_new_line;
typedef boost::mpl::integral_c<char, '\r'> char_cret;


typedef boost::mpl::list< > empty_list;

typedef
  boost::mpl::at<boost::mpl::vector<int, double>, int11>
  can_not_be_instantiated;

#endif



