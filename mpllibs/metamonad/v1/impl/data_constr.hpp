#ifndef MPLLIBS_METAMONAD_V1_IMPL_DATA_CONSTR_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_DATA_CONSTR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/non_nullary_data_constr.hpp>
#include <mpllibs/metamonad/v1/impl/nullary_data_constr.hpp>

#include <boost/preprocessor/control/if.hpp>

#ifdef MPLLIBS_V1_DATA_CONSTR
#  error MPLLIBS_V1_DATA_CONSTR already defined
#endif
#define MPLLIBS_V1_DATA_CONSTR(name, arity) \
  BOOST_PP_IF( \
    arity, \
    MPLLIBS_V1_NON_NULLARY_DATA_CONSTR, \
    MPLLIBS_V1_NULLARY_DATA_CONSTR \
  )(name, arity)

#endif

