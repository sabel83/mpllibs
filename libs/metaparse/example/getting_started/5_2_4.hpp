#ifndef MPLLIBS_METAPARSE_GETTING_STARTED_5_2_4_HPP
#define MPLLIBS_METAPARSE_GETTING_STARTED_5_2_4_HPP

// Automatically generated header file

// Definitions before section 5.2.3
#include "5_2_3.hpp"

// Definitions of section 5.2.3
#include <mpllibs/metaparse/foldl.hpp>

using exp_parser10 = 
 build_parser< 
   transform< 
     sequence< 
       int_token, 
       foldl< 
         sequence<plus_token, int_token>, 
         boost::mpl::int_<0>, 
         boost::mpl::quote2<sum_items> 
       > 
     >, 
     boost::mpl::quote1<sum_vector>> 
 >;

#endif

