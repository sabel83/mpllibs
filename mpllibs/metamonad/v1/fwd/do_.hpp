#ifndef MPLLIBS_METAMONAD_V1_FWD_DO_HPP
#define MPLLIBS_METAMONAD_V1_FWD_DO_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/limit_do_size.hpp>
#include <mpllibs/metamonad/v1/syntax.hpp>

#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

// for boost::mpl::na
#include <boost/mpl/vector.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <
        class Monad,
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          MPLLIBS_LIMIT_DO_SIZE,
          class E,
          syntax<boost::mpl::na>
        )
      >
      struct do_;
    }
  }
}

#endif

