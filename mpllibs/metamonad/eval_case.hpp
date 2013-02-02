#ifndef MPLLIBS_METAMONAD_EVAL_CASE_HPP
#define MPLLIBS_METAMONAD_EVAL_CASE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/case.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      template <class E>
      struct eval_case_impl : eval_syntax<E> {};

      template <class E>
      struct eval_case_impl<exception<E> > : exception<E> {};
    }

    template <
      class E,
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_LIMIT_CASE_SIZE,
        class C,
        boost::mpl::na
      )
    >
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

#endif

