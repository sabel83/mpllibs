#ifndef MPLLIBS_METAMONAD_V1_FWD_CASE_HPP
#define MPLLIBS_METAMONAD_V1_FWD_CASE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/limit_case_size.hpp>

// For boost::mpl::na
#include <boost/mpl/vector.hpp>

#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <
        class E,
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          MPLLIBS_LIMIT_CASE_SIZE,
          class C,
          boost::mpl::na
        )
      >
      struct case_;
    }
  }
}

#endif

