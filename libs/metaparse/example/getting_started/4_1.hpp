#ifndef MPLLIBS_METAPARSE_GETTING_STARTED_4_1_HPP
#define MPLLIBS_METAPARSE_GETTING_STARTED_4_1_HPP

// Automatically generated header file

// Definitions before section 4
#include "4.hpp"

// Definitions of section 4
#include <mpllibs/metaparse/lit_c.hpp>

#include <mpllibs/metaparse/sequence.hpp>

using exp_parser4 = build_parser<sequence<token<int_>, token<lit_c<'+'>>, token<int_>>>;

// query:
//    exp_parser4::apply<MPLLIBS_STRING("11 + 2")>::type

#ifdef __METASHELL
#include <metashell/formatter.hpp>
#endif

// query:
//    exp_parser4::apply<MPLLIBS_STRING("11 + 2")>::type

#endif

