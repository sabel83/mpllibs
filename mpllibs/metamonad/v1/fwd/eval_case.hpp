#ifndef MPLLIBS_METAMONAD_V1_FWD_EVAL_CASE_HPP
#define MPLLIBS_METAMONAD_V1_FWD_EVAL_CASE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/eval_case_impl.hpp>
#include <mpllibs/metamonad/limit_case_size.hpp>

#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

// To get boost::mpl::na
#include <boost/mpl/vector.hpp>

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
      struct eval_case;
    }
  }
}

#endif

