#ifndef MPLLIBS_METAMONAD_V1_IF__HPP
#define MPLLIBS_METAMONAD_V1_IF__HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/if_.hpp>

#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      // MPLLIBS_V1_METAFUNCTION depends on it
      template <class C, class T, class F>
      struct if_ : boost::mpl::eval_if<typename C::type, T, F> {};
    }
  }
}

#endif

