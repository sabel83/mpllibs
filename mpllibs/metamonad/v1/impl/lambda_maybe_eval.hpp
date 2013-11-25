#ifndef MPLLIBS_METAMONAD_V1_IMPL_LAMBDA_MAYBE_EVAL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_LAMBDA_MAYBE_EVAL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/fwd/lambda_impl.hpp>

#include <mpllibs/metamonad/v1/eval_syntax.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/first.hpp>
#include <mpllibs/metamonad/v1/second.hpp>

#include <boost/mpl/empty.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class State>
        struct lambda_maybe_eval :
          if_<
            boost::mpl::empty<typename first<State>::type>,
            eval_syntax<second<State> >,
            lambda_impl<State>
          >::type
        {};
      }
    }
  }
}

#endif

