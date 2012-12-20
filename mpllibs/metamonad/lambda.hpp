#ifndef MPLLIBS_METAMONAD_LAMBDA_HPP
#define MPLLIBS_METAMONAD_LAMBDA_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    template <class ArgName, class F>
    MPLLIBS_METAFUNCTION_CLASS(lambda, (T))
    ((typename let<ArgName, T, F>::type));

    template <class T>
    struct lazy;

    template <class ArgName, class F>
    struct lazy<lambda<ArgName, F> > : lambda<ArgName, lazy<F> > {};
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  2,
  mpllibs::metamonad::lambda,
  "metamonad::lambda" // avoid confusion with mpl::lambda
)

#endif

