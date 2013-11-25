#ifndef MPLLIBS_METAMONAD_V1_DATA_CONSTR_CB_HPP
#define MPLLIBS_METAMONAD_V1_DATA_CONSTR_CB_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/data_constr.hpp>

#include <boost/preprocessor/tuple/elem.hpp>

#ifdef MPLLIBS_V1_DATA_CONSTR_CB
#  error MPLLIBS_V1_DATA_CONSTR_CB already defined
#endif
#define MPLLIBS_V1_DATA_CONSTR_CB(r, unused, constr) \
  MPLLIBS_V1_DATA_CONSTR( \
    BOOST_PP_TUPLE_ELEM(2, 0, constr), \
    BOOST_PP_TUPLE_ELEM(2, 1, constr) \
  )

#endif

