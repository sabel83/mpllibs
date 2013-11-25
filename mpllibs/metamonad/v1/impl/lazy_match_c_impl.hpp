#ifndef MPLLIBS_METAMONAD_V1_IMPL_LAZY_MATCH_C_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_LAZY_MATCH_C_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/fwd/match_c_impl.hpp>
#include <mpllibs/metamonad/v1/impl/match_c_impl.hpp>

#include <mpllibs/metamonad/v1/lazy_metafunction.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        MPLLIBS_V1_LAZY_METAFUNCTION(lazy_match_c_impl, (Pattern)(Value))
        ((match_c_impl<Pattern, Value>));
      }
    }
  }
}

#endif

