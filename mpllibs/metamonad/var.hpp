#ifndef MPLLIBS_METAMONAD_VAR_HPP
#define MPLLIBS_METAMONAD_VAR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    // MPLLIBS_METAFUNCTION depends on it
    template <class Name>
    struct var : tmp_value<var<Name> > {};
    
    // Protection against lazy
    template <class E>
    struct lazy;

    template <class Name>
    struct lazy<var<Name> > : var<Name> {};
  }
}

#endif

