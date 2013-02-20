#ifndef MPLLIBS_METAMONAD_FIRST_HPP
#define MPLLIBS_METAMONAD_FIRST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mpllibs
{
  namespace metamonad
  {
    // LAZY_METAFUNCTION uses lambda, which uses pairs
    template <class P>
    struct first : P::type::first {};
  }
}

#endif

