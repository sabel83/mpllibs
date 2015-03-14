#ifndef MPLLIBS_METAPARSE_GETTING_STARTED_6_HPP
#define MPLLIBS_METAPARSE_GETTING_STARTED_6_HPP

// Automatically generated header file

// Definitions before section 5.2.4
#include "5_2_4.hpp"

// Definitions of section 5.2.4
#include <mpllibs/metaparse/foldlp.hpp>

using exp_parser11 = 
 build_parser< 
   foldlp< 
     sequence<plus_token, int_token>, /* apply this parser repeatedly */ 
     int_token, /* use this parser to get the initial value */ 
     boost::mpl::quote2<sum_items> /* use this function to add a new value to the summary */ 
   > 
 >;

// query:
//    exp_parser11::apply<MPLLIBS_STRING("1 + 2 + 3 + 4")>::type

#endif

