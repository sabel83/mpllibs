#ifndef MPLLIBS_METAPARSE_V2_LIT_C_HPP
#define MPLLIBS_METAPARSE_V2_LIT_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/lit.hpp>

#include <boost/mpl/char.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <char C>
      struct lit_c : lit<boost::mpl::char_<C> > {};
    }
  }
}

#endif


