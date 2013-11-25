#ifndef MPLLIBS_METAMONAD_V1_IMPL_DEFINE_TD_METAFUNCTION_EVAL_ARG_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_DEFINE_TD_METAFUNCTION_EVAL_ARG_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/preprocessor/cat.hpp>

#ifdef MPLLIBS_V1_DEFINE_TD_METAFUNCTION_EVAL_ARG
#  error MPLLIBS_V1_DEFINE_TD_METAFUNCTION_EVAL_ARG already defined
#endif
#define MPLLIBS_V1_DEFINE_TD_METAFUNCTION_EVAL_ARG(z, n, unused) \
  typename BOOST_PP_CAT(T, n)::type

#endif

