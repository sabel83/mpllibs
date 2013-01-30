#ifndef MPLLIBS_METAMONAD_MONAD_HPP
#define MPLLIBS_METAMONAD_MONAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/bind.hpp>
#include <mpllibs/metamonad/typeclass.hpp>
#include <mpllibs/metamonad/exception_core.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/name.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class Tag>
    struct monad
    {
      MPLLIBS_TYPECLASS_EXPECT(return_);
      MPLLIBS_TYPECLASS_EXPECT(bind);
      MPLLIBS_TYPECLASS_EXPECT(bind_);
    };
    
    template <class Tag>
    struct monad_defaults : monad<typeclass_expectations>
    {
      typedef
        lambda_c<a, b, mpllibs::metamonad::bind<Tag, a, lambda_c<s, b> > >
        bind_;

      typedef lambda_c<s, exception<s> > fail;
    };
  }
}

#endif

