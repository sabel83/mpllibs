#ifndef MPLLIBS_METAMONAD_V1_TD_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_V1_TD_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/define_td_metafunction_get_tag.hpp>
#include <mpllibs/metamonad/v1/impl/define_td_metafunction_eval_arg.hpp>

#include <mpllibs/metamonad/v1/overloading_error_tag.hpp>
#include <mpllibs/metamonad/v1/exception.hpp>
#include <mpllibs/metamonad/v1/tmp_value.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum.hpp>

#include <iostream>

#ifdef MPLLIBS_V1_DEFINE_TAG_DISPATCHING_METAFUNCTION
#  error MPLLIBS_V1_DEFINE_TAG_DISPATCHING_METAFUNCTION already defined
#endif
#define MPLLIBS_V1_DEFINE_TAG_DISPATCHING_METAFUNCTION(name, arg_num) \
  struct BOOST_PP_CAT(invalid_args_for_, name) : \
    mpllibs::metamonad::v1::tmp_value< \
      BOOST_PP_CAT(invalid_args_for_, name), \
      mpllibs::metamonad::v1::overloading_error_tag \
    > \
  {}; \
  \
  template <BOOST_PP_ENUM_PARAMS(arg_num, class Tag)> \
  struct BOOST_PP_CAT(name, _impl) : \
    mpllibs::metamonad::v1::tmp_value< \
      BOOST_PP_CAT(name, _impl)<BOOST_PP_ENUM_PARAMS(arg_num, Tag)> \
    > \
  { \
    template <BOOST_PP_ENUM_PARAMS(arg_num, class T)> \
    struct apply : \
      mpllibs::metamonad::v1::exception<BOOST_PP_CAT(invalid_args_for_, name)> \
    {}; \
  }; \
  \
  template <BOOST_PP_ENUM_PARAMS(arg_num, class T)> \
  struct name : \
    BOOST_PP_CAT(name, _impl)< \
      BOOST_PP_ENUM(arg_num, MPLLIBS_V1_DEFINE_TD_METAFUNCTION_GET_TAG, ~) \
    >:: \
      template apply< \
        BOOST_PP_ENUM(arg_num, MPLLIBS_V1_DEFINE_TD_METAFUNCTION_EVAL_ARG, ~) \
      > \
  {};

#endif

