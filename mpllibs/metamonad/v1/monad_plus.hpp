#ifndef MPLLIBS_METAMONAD_V1_MONAD_PLUS_HPP
#define MPLLIBS_METAMONAD_V1_MONAD_PLUS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/monad_plus.hpp>
#include <mpllibs/metamonad/v1/typeclass.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      /*
        class (Monad m) => MonadPlus m where
          mzero :: m a
          mplus :: m a -> m a -> m a
       */
      template <class Tag>
      struct monad_plus
      {
        MPLLIBS_V1_TYPECLASS_EXPECT(mzero);
        MPLLIBS_V1_TYPECLASS_EXPECT(mplus);
      };
    }
  }
}

#endif

