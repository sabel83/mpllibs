#ifndef MPLLIBS_METAMONAD_V1_IMPL_NON_NULLARY_DATA_CONSTR_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_NON_NULLARY_DATA_CONSTR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/run_param.hpp>
#include <mpllibs/metamonad/v1/impl/build_seq.hpp>

#include <mpllibs/metamonad/v1/lazy_metafunction.hpp>
#include <mpllibs/metamonad/v1/calculated_value.hpp>
#include <mpllibs/metamonad/v1/algebraic_data_type_tag.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

#include <string>
#include <sstream>
#include <iostream>

#ifdef MPLLIBS_V1_NON_NULLARY_DATA_CONSTR
#  error MPLLIBS_V1_NON_NULLARY_DATA_CONSTR already defined
#endif
#define MPLLIBS_V1_NON_NULLARY_DATA_CONSTR(name, arity) \
  template <BOOST_PP_ENUM_PARAMS(arity, class T)> \
  struct BOOST_PP_CAT(name, __body); \
  \
  MPLLIBS_V1_LAZY_METAFUNCTION( \
    name, \
    BOOST_PP_REPEAT(arity, MPLLIBS_V1_BUILD_SEQ, ~) \
  ) \
  (( BOOST_PP_CAT(name, __body)<BOOST_PP_ENUM_PARAMS(arity, T)> )); \
  \
  template <BOOST_PP_ENUM_PARAMS(arity, class T)> \
  struct BOOST_PP_CAT(name, __body) : \
    mpllibs::metamonad::v1::calculated_value<\
      name<BOOST_PP_ENUM_PARAMS(arity, T)>, \
      std::string, \
      mpllibs::metamonad::v1::algebraic_data_type_tag \
    > \
  { \
    static std::string get_value() \
    { \
      std::ostringstream s; \
      s << BOOST_PP_STRINGIZE(name) "<"; \
      BOOST_PP_REPEAT(arity, MPLLIBS_V1_RUN_PARAM, ~) \
      s << ">"; \
      return s.str(); \
    } \
  }; \

#endif

