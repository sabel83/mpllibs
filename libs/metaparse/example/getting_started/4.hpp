#ifndef MPLLIBS_METAPARSE_GETTING_STARTED_4_HPP
#define MPLLIBS_METAPARSE_GETTING_STARTED_4_HPP

// Automatically generated header file

// Definitions before section 3.3
#include "3_3.hpp"

// Definitions of section 3.3
// query:
//    exp_parser2::apply<MPLLIBS_STRING("11 ")>::type

#include <mpllibs/metaparse/token.hpp>

using exp_parser3 = build_parser<entire_input<token<int_>>>;

// query:
//    exp_parser3::apply<MPLLIBS_STRING("11 ")>::type

#endif

