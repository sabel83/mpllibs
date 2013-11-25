#ifndef MPLLIBS_METAMONAD_V1_IMPL_LAZY_EVAL_ARG_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_LAZY_EVAL_ARG_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/preprocessor/punctuation/comma_if.hpp>

#ifdef MPLLIBS_V1_LAZY_EVAL_ARG
#  error MPLLIBS_V1_LAZY_EVAL_ARG already defined
#endif
#define MPLLIBS_V1_LAZY_EVAL_ARG(r, unused, n, arg) \
  BOOST_PP_COMMA_IF(n) typename arg::type

#endif


