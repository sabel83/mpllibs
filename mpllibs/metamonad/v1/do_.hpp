#ifndef MPLLIBS_METAMONAD_V1_DO__HPP
#define MPLLIBS_METAMONAD_V1_DO__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/do_.hpp>
#include <mpllibs/metamonad/v1/do_c.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      #ifdef MPLLIBS_DO_ARG
      #  error MPLLIBS_DO_ARG already defined
      #endif
      #define MPLLIBS_DO_ARG(z, n, unused) , syntax<BOOST_PP_CAT(E, n)>
       
      template <
        class Monad,
        BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_DO_SIZE, class E)
      >
      struct
        do_<Monad BOOST_PP_REPEAT(MPLLIBS_LIMIT_DO_SIZE, MPLLIBS_DO_ARG, ~)> :
        do_c<Monad, BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_DO_SIZE, E)>
      {};

      #undef MPLLIBS_DO_ARG
    }
  }
}

#endif

