#ifndef MPLLIBS_METAMONAD_V1_IMPL_DATA_ARGS_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_DATA_ARGS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/preprocessor/tuple/eat.hpp>
#include <boost/preprocessor/repetition/enum.hpp>

#ifdef MPLLIBS_V1_DATA_ARGS
#  error MPLLIBS_V1_DATA_ARGS already defined
#endif
#define MPLLIBS_V1_DATA_ARGS(arity) \
  template <BOOST_PP_ENUM(arity, class BOOST_PP_TUPLE_EAT(3), ~)>

#endif

