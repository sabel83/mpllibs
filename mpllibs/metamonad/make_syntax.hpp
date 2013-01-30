#ifndef MPLLIBS_METAMONAD_MAKE_SYNTAX_HPP
#define MPLLIBS_METAMONAD_MAKE_SYNTAX_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(make_syntax, (E)) ((syntax<typename E::type>));
  }
}

#endif

