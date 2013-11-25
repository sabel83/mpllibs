#ifndef MPLLIBS_METAMONAD_V1_MONOID_HPP
#define MPLLIBS_METAMONAD_V1_MONOID_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/monoid.hpp>
#include <mpllibs/metamonad/v1/typeclass.hpp>
#include <mpllibs/metamonad/v1/mempty.hpp>
#include <mpllibs/metamonad/v1/mappend.hpp>
#include <mpllibs/metamonad/v1/lambda_c.hpp>
#include <mpllibs/metamonad/v1/lambda.hpp>
#include <mpllibs/metamonad/v1/syntax.hpp>
#include <mpllibs/metamonad/v1/name.hpp>
#include <mpllibs/metamonad/v1/lazy.hpp>
#include <mpllibs/metamonad/v1/lazy_protect_args.hpp>

#include <boost/mpl/reverse_fold.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class Tag>
      struct monoid
      {
        MPLLIBS_V1_TYPECLASS_EXPECT(mempty);
        MPLLIBS_V1_TYPECLASS_EXPECT(mappend);
        MPLLIBS_V1_TYPECLASS_EXPECT(mconcat);
      };
      
      template <class Tag>
      struct monoid_defaults : monoid<typeclass_expectations>
      {
        typedef
          lambda_c<l,
            lazy<
              boost::mpl::reverse_fold<
                l,
                lazy_protect_args<mpllibs::metamonad::v1::mempty<Tag> >,
                lambda<s, t,
                  syntax<mpllibs::metamonad::v1::mappend<Tag, s, t> >
                >,
                lambda_c<x, _, x>
              >
            >
          >
          mconcat;
      };
    }
  }
}

#endif

