#ifndef MPLLIBS_METAMONAD_V1_IMPL_RUN_PARAM_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_RUN_PARAM_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/value_to_stream.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/control/if.hpp>

#include <iostream>

#ifdef MPLLIBS_V1_RUN_PARAM
#  error MPLLIBS_V1_RUN_PARAM already defined
#endif
#define MPLLIBS_V1_RUN_PARAM(z, n, unused) \
  s << BOOST_PP_IF(n, ", ", ""); \
  mpllibs::metamonad::v1::value_to_stream<BOOST_PP_CAT(T, n)>::run(s);

#endif

