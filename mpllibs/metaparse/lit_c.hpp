#ifndef MPLLIBS_METAPARSE_LIT_C_HPP
#define MPLLIBS_METAPARSE_LIT_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/lit.hpp>

#include <boost/mpl/char.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <char C>
    struct lit_c : lit<boost::mpl::char_<C> > {};
  }
}

#endif


