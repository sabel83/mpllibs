#ifndef MPLLIBS_PARSER_TEST_COMMON_H
#define MPLLIBS_PARSER_TEST_COMMON_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/lit.hpp>
#include <mpllibs/metaparse/lit_c.hpp>

#include <boost/mpl/list.hpp>
#include <boost/mpl/list_c.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/at.hpp>

typedef boost::mpl::list_c<char> str_;
typedef boost::mpl::list_c<char, '0'> str_0;
typedef boost::mpl::list_c<char, '1'> str_1;
typedef boost::mpl::list_c<char, '1', '9', '8', '3'> str_1983;
typedef boost::mpl::list_c<char, 'a'> str_a;
typedef boost::mpl::list_c<char, 'h'> str_h;
typedef boost::mpl::list_c<char, 'e'> str_e;
typedef boost::mpl::list_c<char, 'l'> str_l;
typedef boost::mpl::list_c<char, 'b', 'e', 'l', 'l', 'o'> str_bello;
typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> str_hello;
typedef boost::mpl::list_c<char, ' ', 'e', 'l', 'l', 'o'> str__ello;

typedef boost::mpl::list_c<char, '0', 'e', 'l', 'l', 'o'> chars0;
typedef boost::mpl::list_c<char, 'h', '0', 'l', 'l', 'o'> chars1;
typedef boost::mpl::list_c<char, 'h', 'e', '0', 'l', 'o'> chars2;
typedef boost::mpl::list_c<char, 'h', 'e', 'l', '0', 'o'> chars3;
typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', '0'> chars4;
typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> chars5;

typedef boost::mpl::integral_c<char, '0'> char_0;
typedef boost::mpl::integral_c<char, '1'> char_1;
typedef boost::mpl::integral_c<char, '7'> char_7;
typedef boost::mpl::integral_c<char, '9'> char_9;
typedef boost::mpl::integral_c<char, 'a'> char_a;
typedef boost::mpl::integral_c<char, 'b'> char_b;
typedef boost::mpl::integral_c<char, 'e'> char_e;
typedef boost::mpl::integral_c<char, 'h'> char_h;
typedef boost::mpl::integral_c<char, 'k'> char_k;
typedef boost::mpl::integral_c<char, 'K'> char_K;
typedef boost::mpl::integral_c<char, 'l'> char_l;
typedef boost::mpl::integral_c<char, 'o'> char_o;
typedef boost::mpl::integral_c<char, 'x'> char_x;

typedef boost::mpl::integral_c<char, ' '> char_space;
typedef boost::mpl::integral_c<char, '\t'> char_tab;
typedef boost::mpl::integral_c<char, '\n'> char_new_line;
typedef boost::mpl::integral_c<char, '\r'> char_cret;

typedef boost::mpl::int_<0> int0;
typedef boost::mpl::int_<1> int1;
typedef boost::mpl::int_<2> int2;
typedef boost::mpl::int_<3> int3;
typedef boost::mpl::int_<9> int9;
typedef boost::mpl::int_<10> int10;
typedef boost::mpl::int_<11> int11;
typedef boost::mpl::int_<12> int12;
typedef boost::mpl::int_<13> int13;
typedef boost::mpl::int_<14> int14;
typedef boost::mpl::int_<28> int28;

typedef mpllibs::metaparse::lit<char_e> lit_e;
typedef mpllibs::metaparse::lit<char_h> lit_h;
typedef mpllibs::metaparse::lit<char_l> lit_l;
typedef mpllibs::metaparse::lit<char_x> lit_x;

typedef mpllibs::metaparse::lit_c<'e'> lit_c_e;
typedef mpllibs::metaparse::lit_c<'h'> lit_c_h;

typedef boost::mpl::list< > empty_list;

typedef
  boost::mpl::at<boost::mpl::vector<int, double>, int11>
  can_not_be_instantiated;

#endif

