#ifndef MPLLIBS_METAMONAD_MONAD_HPP
#define MPLLIBS_METAMONAD_MONAD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/typeclass.hpp>
#include <mpllibs/metamonad/throw.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/always.hpp>

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
      MPLLIBS_METAFUNCTION_CLASS(bind_, (A)(B))
      ((
        boost::mpl::apply_wrap2<
          typename monad<Tag>::bind,
          A,
          boost::mpl::always<B>
        >
      ));

      MPLLIBS_METAFUNCTION_CLASS(fail, (S)) ((throw_<S>));
    };
  }
}

#endif

