#ifndef MPLLIBS_METAMONAD_V1_IMPL_LAMBDA_IMPL_STEP_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_LAMBDA_IMPL_STEP_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/let.hpp>
#include <mpllibs/metamonad/v1/syntax.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>
#include <mpllibs/metamonad/v1/_.hpp>
#include <mpllibs/metamonad/v1/if_.hpp>
#include <mpllibs/metamonad/v1/first.hpp>
#include <mpllibs/metamonad/v1/second.hpp>
#include <mpllibs/metamonad/v1/pair.hpp>
#include <mpllibs/metamonad/v1/is_same.hpp>

#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        struct lambda_impl_step : tmp_value<lambda_impl_step>
        {
          // MPLLIBS_V1_METAFUNCTION depends on it
          template <class State, class T>
          struct apply :
            pair<
              boost::mpl::pop_front<typename first<State>::type>,
              if_<
                is_same<boost::mpl::front<typename first<State>::type>, _>,
                second<State>,
                let<
                  boost::mpl::front<typename first<State>::type>,
                  syntax<T>,
                  second<State>
                >
              >
            >
          {};
        };
      }
    }
  }
}

#endif

