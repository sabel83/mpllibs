#ifndef MPLLIBS_METAMONAD_IMPL_LAMBDA_HPP
#define MPLLIBS_METAMONAD_IMPL_LAMBDA_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply.hpp>

#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      struct lambda_no_arg;
    }

    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
        class T,
        impl::lambda_no_arg
      ),
      class T = impl::lambda_no_arg // for the body
    >
    struct lambda;
  }
}

#endif

