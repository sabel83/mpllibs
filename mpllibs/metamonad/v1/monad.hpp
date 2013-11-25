#ifndef MPLLIBS_METAMONAD_V1_MONAD_HPP
#define MPLLIBS_METAMONAD_V1_MONAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/monad.hpp>
#include <mpllibs/metamonad/v1/fwd/exception.hpp>
#include <mpllibs/metamonad/v1/bind.hpp>
#include <mpllibs/metamonad/v1/typeclass.hpp>
#include <mpllibs/metamonad/v1/lambda_c.hpp>
#include <mpllibs/metamonad/v1/name.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class Tag>
      struct monad
      {
        MPLLIBS_V1_TYPECLASS_EXPECT(return_);
        MPLLIBS_V1_TYPECLASS_EXPECT(bind);
        MPLLIBS_V1_TYPECLASS_EXPECT(bind_);
      };
      
      template <class Tag>
      struct monad_defaults : monad<typeclass_expectations>
      {
        typedef
          lambda_c<a, b, mpllibs::metamonad::v1::bind<Tag, a, lambda_c<s, b> > >
          bind_;
  
        typedef exception<> fail;
      };
    }
  }
}

#endif

