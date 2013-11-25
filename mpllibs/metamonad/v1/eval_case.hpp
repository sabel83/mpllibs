#ifndef MPLLIBS_METAMONAD_V1_EVAL_CASE_HPP
#define MPLLIBS_METAMONAD_V1_EVAL_CASE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/eval_case.hpp>
#include <mpllibs/metamonad/v1/impl/eval_case_impl.hpp>

#include <mpllibs/metamonad/v1/case_.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      template <class E, BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_CASE_SIZE, class C)>
      struct eval_case :
        impl::eval_case_impl<
          typename case_<
            E,
            BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_CASE_SIZE, C)
          >::type
        >
      {};
    }
  }
}

#endif

