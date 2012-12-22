#ifndef MPLLIBS_METAMONAD_MONOID_HPP
#define MPLLIBS_METAMONAD_MONOID_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/typeclass.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/reverse_fold.hpp>

#include <iostream>

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
      MPLLIBS_METAFUNCTION_CLASS(mconcat, (L))
      ((
        boost::mpl::reverse_fold<
          L,
          typename monoid<Tag>::mempty,
          typename monoid<Tag>::mappend
        >
      ));
    };
  }
}

#endif

