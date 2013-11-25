#ifndef MPLLIBS_METAMONAD_V1_DATA_HPP
#define MPLLIBS_METAMONAD_V1_DATA_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/data_constr_cb.hpp>
#include <mpllibs/metamonad/v1/impl/data_args.hpp>
#include <mpllibs/metamonad/v1/impl/data_args_with_default_void.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

#ifdef MPLLIBS_V1_DATA
#  error MPLLIBS_V1_DATA already defined
#endif
#define MPLLIBS_V1_DATA(name, type_arity, constrs) \
  BOOST_PP_IF( \
    type_arity, \
    MPLLIBS_V1_DATA_ARGS_WITH_DEFAULT_VOID, \
    BOOST_PP_TUPLE_EAT(1) \
  )(type_arity) \
  struct BOOST_PP_CAT(name, _tag); \
  \
  BOOST_PP_SEQ_FOR_EACH(MPLLIBS_V1_DATA_CONSTR_CB, ~, constrs) \
  \
  BOOST_PP_IF(type_arity, MPLLIBS_V1_DATA_ARGS, BOOST_PP_TUPLE_EAT(1)) \
    (type_arity) \
  struct BOOST_PP_CAT(name, _tag) \
  { \
    typedef BOOST_PP_CAT(name, _tag) type; \
    typedef mpllibs::metamonad::v1::tag_tag tag; \
  }

#endif

