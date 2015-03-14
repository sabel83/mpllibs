#ifndef MPLLIBS_METAPARSE_GETTING_STARTED_8_1_HPP
#define MPLLIBS_METAPARSE_GETTING_STARTED_8_1_HPP

// Automatically generated header file

// Definitions before section 8
#include "8.hpp"

// Definitions of section 8
#include <boost/mpl/divides.hpp>

template <class L, class R> struct eval_binary_op<L, '/', R> : boost::mpl::divides<L, R>::type {};

using divides_token = token<lit_c<'/'>>;

using mult_exp2 = 
 foldlp< 
   sequence<one_of<times_token, divides_token>, int_token>, 
   int_token, 
   boost::mpl::quote2<binary_op> 
 >;

using exp_parser16 = 
 build_parser< 
   foldlp< 
     sequence<one_of<plus_token, minus_token>, mult_exp2>, 
     mult_exp2, 
     boost::mpl::quote2<binary_op> 
   > 
 >;

// query:
//    exp_parser16::apply<MPLLIBS_STRING("8 / 4")>::type

#endif

