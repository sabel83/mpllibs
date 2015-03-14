#ifndef MPLLIBS_METAPARSE_GETTING_STARTED_4_2_HPP
#define MPLLIBS_METAPARSE_GETTING_STARTED_4_2_HPP

// Automatically generated header file

// Definitions before section 4.1
#include "4_1.hpp"

// Definitions of section 4.1
using int_token = token<int_>;

using plus_token = token<lit_c<'+'>>;

using exp_parser5 = build_parser<sequence<int_token, plus_token, int_token>>;

// query:
//    exp_parser5::apply<MPLLIBS_STRING("11 + 2")>::type

#endif

