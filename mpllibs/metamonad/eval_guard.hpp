#ifndef MPLLIBS_METAMONAD_EVAL_GUARD_HPP
#define MPLLIBS_METAMONAD_EVAL_GUARD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(eval_guard, (T)) ((tmp_value<eval_guard<T> >));

    template <class E>
    struct lazy;

    template <class T>
    struct lazy<eval_guard<T> > : eval_guard<T> {};
  }
}

#endif

