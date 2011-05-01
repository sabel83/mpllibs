#ifndef MPLLIBS_PARSER_LIT_C_H
#define MPLLIBS_PARSER_LIT_C_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/lit.h>

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <char C>
    struct lit_c : lit<boost::mpl::integral_c<char, C> > {};
  }
}

#endif


