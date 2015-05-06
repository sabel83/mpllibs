#ifndef MPLLIBS_METAPARSE_GETTING_STARTED_11_3_2_HPP
#define MPLLIBS_METAPARSE_GETTING_STARTED_11_3_2_HPP

// Automatically generated header file

// Definitions before section 11.3.1
#include "11_3_1.hpp"

// Definitions of section 11.3.1
#include <mpllibs/metaparse/foldlfp.hpp>

struct plus_exp5 : 
 foldlfp< 
   sequence<one_of<plus_token, minus_token>, mult_exp6>, 
   mult_exp6, 
   boost::mpl::quote2<binary_op> 
 > {};

using exp_parser22 = build_parser<plus_exp5>;

// query:
//    exp_parser22::apply<MPLLIBS_STRING("0+(1+2")>::type

#endif

