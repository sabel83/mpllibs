#ifndef MPLLIBS_METAPARSE_GETTING_STARTED_10_HPP
#define MPLLIBS_METAPARSE_GETTING_STARTED_10_HPP

// Automatically generated header file

// Definitions before section 9
#include "9.hpp"

// Definitions of section 9
#include <boost/mpl/negate.hpp>

using unary_exp1 = 
 foldrp< 
   minus_token, 
   int_token, 
   boost::mpl::lambda<boost::mpl::negate<boost::mpl::_1>>::type 
 >;

using mult_exp4 = 
 foldlp< 
   sequence<one_of<times_token, divides_token>, unary_exp1>, 
   unary_exp1, 
   boost::mpl::quote2<binary_op> 
 >;

using exp_parser18 = 
 build_parser< 
   foldlp< 
     sequence<one_of<plus_token, minus_token>, mult_exp4>, 
     mult_exp4, 
     boost::mpl::quote2<binary_op> 
   > 
 >;

// query:
//    exp_parser18::apply<MPLLIBS_STRING("---13")>::type

// query:
//    exp_parser18::apply<MPLLIBS_STRING("13")>::type

#endif

