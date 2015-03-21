#ifndef MPLLIBS_METAPARSE_V2_LIT_HPP
#define MPLLIBS_METAPARSE_V2_LIT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/lit_c.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class C>
      struct lit : lit_c<C::type::value> {};
    }
  }
}

#endif

