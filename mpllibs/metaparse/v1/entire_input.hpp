#ifndef MPLLIBS_METAPARSE_V1_ENTIRE_INPUT_HPP
#define MPLLIBS_METAPARSE_V1_ENTIRE_INPUT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/first_of.hpp>
#include <mpllibs/metaparse/v1/empty.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      template <class P>
      struct entire_input : first_of<P, empty<void> > {};
    }
  }
}

#endif

