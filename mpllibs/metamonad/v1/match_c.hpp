#ifndef MPLLIBS_METAMONAD_V1_MATCH_C_HPP
#define MPLLIBS_METAMONAD_V1_MATCH_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/match_c.hpp>
#include <mpllibs/metamonad/v1/impl/match_c_impl.hpp>
#include <mpllibs/metamonad/v1/metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      MPLLIBS_V1_METAFUNCTION(match_c, (P)(V))
      ((impl::match_c_impl<P, typename V::type>));
    }
  }
}

#endif

