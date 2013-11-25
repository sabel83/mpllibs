#ifndef MPLLIBS_METAMONAD_V1_FWD_APPLY_HPP
#define MPLLIBS_METAMONAD_V1_FWD_APPLY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// For BOOST_MPL_LIMIT_METAFUNCTION_ARITY
#include <boost/mpl/apply.hpp>

#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <
        class F,
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
          class T,
          boost::mpl::na
        )
      >
      struct apply;
    }
  }
}

#endif

