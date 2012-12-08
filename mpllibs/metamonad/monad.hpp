#ifndef MPLLIBS_METAMONAD_MONAD_HPP
#define MPLLIBS_METAMONAD_MONAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/typeclass.hpp>
#include <mpllibs/metamonad/throw.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/always.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    template <class Tag>
    struct monad
    {
      MPLLIBS_TYPECLASS_EXPECT(return_)
      MPLLIBS_TYPECLASS_EXPECT(bind)
      MPLLIBS_TYPECLASS_EXPECT(bind_)
    };
    
    template <class Tag>
    struct monad_defaults : monad<typeclass_expectations>
    {
      struct bind_ : tmp_value<bind_>
      {
        template <class A, class B>
        struct apply :
          boost::mpl::apply_wrap2<
            typename monad<Tag>::bind,
            A,
            boost::mpl::always<B>
          >
        {};
      };

      struct fail : tmp_value<fail>
      {
        template <class S>
        struct apply : throw_<S> {};
      };
    };
  }
}

#endif

