#ifndef MPLLIBS_METAMONAD_V1_DO_RETURN_HPP
#define MPLLIBS_METAMONAD_V1_DO_RETURN_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/do_return.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class V>
      struct do_return : tmp_value<do_return<V> > {};
    }
  }
}

#endif

