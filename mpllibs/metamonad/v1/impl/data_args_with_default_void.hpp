#ifndef MPLLIBS_METAMONAD_V1_DATA_ARGS_WITH_DEFAULT_VOID_HPP
#define MPLLIBS_METAMONAD_V1_DATA_ARGS_WITH_DEFAULT_VOID_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

#include <boost/mpl/void.hpp>

#ifdef MPLLIBS_V1_DATA_ARGS_WITH_DEFAULT_VOID
#  error MPLLIBS_V1_DATA_ARGS_WITH_DEFAULT_VOID already defined
#endif
#define MPLLIBS_V1_DATA_ARGS_WITH_DEFAULT_VOID(arity) \
  template < \
    BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(arity, class T, boost::mpl::void_) \
  >

#endif

