#ifndef MPLLIBS_PARSER_LIT_C_H
#define MPLLIBS_PARSER_LIT_C_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/parser/lit.h>

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace parser
  {
    template <char c>
    struct lit_c : mpllibs::parser::lit<boost::mpl::integral_c<char, c> >
    {};
  }
}

#endif


