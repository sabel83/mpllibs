#ifndef MPLLIBS_METAPARSE_V2_SWAP_HPP
#define MPLLIBS_METAPARSE_V2_SWAP_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <class F>
      struct swap
      {
        typedef swap type;

        template <class A, class B>
        struct apply : boost::mpl::apply<F, B, A> {};
      };
    }
  }
}

#endif


