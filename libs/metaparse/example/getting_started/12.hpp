#ifndef MPLLIBS_METAPARSE_GETTING_STARTED_12_HPP
#define MPLLIBS_METAPARSE_GETTING_STARTED_12_HPP

// Automatically generated header file

// Definitions before section 11.3
#include "11_3.hpp"

// Definitions of section 11.3
// query:
//    exp_parser20::apply<MPLLIBS_STRING("(1+2")>::type

// query:
//    exp_parser20::apply<MPLLIBS_STRING("0+(1+2")>::type

#include <mpllibs/metaparse/fail_at_first_char_expected.hpp>

#include <mpllibs/metaparse/first_of.hpp>

struct plus_exp4 : 
 first_of< 
   foldlp< 
     sequence<one_of<plus_token, minus_token>, mult_exp6>, 
     mult_exp6, 
     boost::mpl::quote2<binary_op> 
   >, 
   fail_at_first_char_expected< 
     sequence<one_of<plus_token, minus_token>, mult_exp6> 
   > 
 > {};

using exp_parser21 = build_parser<plus_exp4>;

// query:
//    exp_parser21::apply<MPLLIBS_STRING("0+(1+2")>::type

#endif

