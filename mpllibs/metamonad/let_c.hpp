#ifndef MPLLIBS_METAMONAD_LET_C_HPP
#define MPLLIBS_METAMONAD_LET_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/let.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(let_c, (A)(E1)(E2))
    ((syntax<typename impl::let_in_syntax<typename A::type, E1, E2>::type>));
  }
}

#endif

