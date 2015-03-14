#ifndef MPLLIBS_METAPARSE_GETTING_STARTED_5_2_HPP
#define MPLLIBS_METAPARSE_GETTING_STARTED_5_2_HPP

// Automatically generated header file

// Definitions before section 5.1
#include "5_1.hpp"

// Definitions of section 5.1
#include <mpllibs/metaparse/any.hpp>

using exp_parser7 = 
 build_parser< 
   sequence< 
     int_token,                           /* The first <number> */ 
     any<sequence<plus_token, int_token>> /* The "+ <number>" elements */ 
   > 
 >;

// query:
//    exp_parser7::apply<MPLLIBS_STRING("1 + 2 + 3 + 4")>::type

#endif

