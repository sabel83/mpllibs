#ifndef MPLLIBS_METAMONAD_MONOID_HPP
#define MPLLIBS_METAMONAD_MONOID_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/typeclass.hpp>
#include <mpllibs/metamonad/mempty.hpp>
#include <mpllibs/metamonad/mappend.hpp>
#include <mpllibs/metamonad/lambda_c.hpp>
#include <mpllibs/metamonad/lambda.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/already_lazy.hpp>

#include <boost/mpl/reverse_fold.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class Tag>
    struct monoid
    {
      MPLLIBS_TYPECLASS_EXPECT(mempty);
      MPLLIBS_TYPECLASS_EXPECT(mappend);
      MPLLIBS_TYPECLASS_EXPECT(mconcat);
    };
    
    template <class Tag>
    struct monoid_defaults : monoid<typeclass_expectations>
    {
      typedef
        lambda_c<l,
          lazy<
            boost::mpl::reverse_fold<
              already_lazy<l>,
              mpllibs::metamonad::mempty<already_lazy<Tag> >,
              lambda<s, t, syntax<mpllibs::metamonad::mappend<Tag, s, t> > >,
              lambda_c<x, _, x>
            >
          >
        >
        mconcat;
    };
  }
}

#endif

