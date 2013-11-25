#ifndef MPLLIBS_METAMONAD_INSTANTIATE_HPP
#define MPLLIBS_METAMONAD_INSTANTIATE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/instantiate.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    #ifdef MPLLIBS_INSTANTIATE_CASE
      #error MPLLIBS_INSTANTIATE_CASE already defined
    #endif
    #define MPLLIBS_INSTANTIATE_CASE(z, n, unused) \
      using v1::BOOST_PP_CAT(instantiate, n);

    BOOST_PP_REPEAT_FROM_TO(
      1,
      MPLLIBS_LIMIT_INSTANTIATE_ARITY,
      MPLLIBS_INSTANTIATE_CASE,
      ~
    )
    
    #undef MPLLIBS_INSTANTIATE_CASE
  }
}

#endif

