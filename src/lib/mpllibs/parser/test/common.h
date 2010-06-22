#ifndef MPLLIBS_PARSER_TEST_COMMON_H
#define MPLLIBS_PARSER_TEST_COMMON_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/lit.h>
#include <mpllibs/parser/lit_c.h>

#include <boost/mpl/list_c.hpp>
#include <boost/mpl/integral_c.hpp>
#include <boost/mpl/int.hpp>

typedef boost::mpl::list_c<char> str_;
typedef boost::mpl::list_c<char, '1'> str_1;
typedef boost::mpl::list_c<char, '1', '9', '8', '3'> str_1983;
typedef boost::mpl::list_c<char, 'a'> str_a;
typedef boost::mpl::list_c<char, 'b', 'e', 'l', 'l', 'o'> str_bello;
typedef boost::mpl::list_c<char, 'h', 'e', 'l', 'l', 'o'> str_hello;

typedef boost::mpl::integral_c<char, '1'> char_1;
typedef boost::mpl::integral_c<char, 'e'> char_e;
typedef boost::mpl::integral_c<char, 'h'> char_h;
typedef boost::mpl::integral_c<char, 'l'> char_l;
typedef boost::mpl::integral_c<char, 'o'> char_o;
typedef boost::mpl::integral_c<char, 'x'> char_x;

typedef boost::mpl::int_<0> int0;
typedef boost::mpl::int_<1> int1;
typedef boost::mpl::int_<2> int2;
typedef boost::mpl::int_<3> int3;
typedef boost::mpl::int_<11> int11;
typedef boost::mpl::int_<13> int13;


typedef mpllibs::parser::lit<char_e> lit_e;
typedef mpllibs::parser::lit<char_h> lit_h;
typedef mpllibs::parser::lit<char_l> lit_l;
typedef mpllibs::parser::lit<char_x> lit_x;

typedef mpllibs::parser::lit_c<'e'> lit_c_e;
typedef mpllibs::parser::lit_c<'h'> lit_c_h;

#endif

