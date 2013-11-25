#ifndef MPLLIBS_METAMONAD_V1_TRY_C_HPP
#define MPLLIBS_METAMONAD_V1_TRY_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/try_c.hpp>
#include <mpllibs/metamonad/v1/try_.hpp>
#include <mpllibs/metamonad/v1/syntax.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>

namespace mpllibs
{
  namespace metamonad
  { 
    namespace v1
    {
      template <
        class Expr, 
        BOOST_PP_ENUM_PARAMS(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, class Catch)
      >
      struct try_c :
        try_<
          syntax<Expr>,
          BOOST_PP_ENUM_PARAMS(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, Catch)
        >
      {};
    }
  }
}

#endif

