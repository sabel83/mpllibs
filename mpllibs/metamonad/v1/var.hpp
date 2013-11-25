#ifndef MPLLIBS_METAMONAD_V1_VAR_HPP
#define MPLLIBS_METAMONAD_V1_VAR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/var.hpp>
#include <mpllibs/metamonad/v1/fwd/lazy.hpp>
#include <mpllibs/metamonad/v1/var_tag.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      // MPLLIBS_V1_METAFUNCTION depends on it
      template <class Name>
      struct var : tmp_value<var<Name>, var_tag> {};
      
      template <class Name>
      struct lazy<var<Name> > : var<Name> {};
    }
  }
}

#endif

