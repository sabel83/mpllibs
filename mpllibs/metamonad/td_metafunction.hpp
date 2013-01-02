#ifndef MPLLIBS_METAMONAD_TD_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_TD_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/overloading_error.hpp>
#include <mpllibs/metamonad/exception_core.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/tag.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#include <iostream>

#ifdef MPLLIBS_DEFINE_TD_METAFUNCTION_GET_TAG
  #error MPLLIBS_DEFINE_TD_METAFUNCTION_GET_TAG already defined
#endif
#define MPLLIBS_DEFINE_TD_METAFUNCTION_GET_TAG(z, n, unused) \
  BOOST_PP_COMMA_IF(n) typename boost::mpl::tag<typename T##n::type>::type

#ifdef MPLLIBS_DEFINE_TD_METAFUNCTION_EVAL_ARG
  #error MPLLIBS_DEFINE_TD_METAFUNCTION_EVAL_ARG already defined
#endif
#define MPLLIBS_DEFINE_TD_METAFUNCTION_EVAL_ARG(z, n, unused) \
  BOOST_PP_COMMA_IF(n) typename T##n::type

#ifdef MPLLIBS_DEFINE_TAG_DISPATCHING_METAFUNCTION
  #error MPLLIBS_DEFINE_TAG_DISPATCHING_METAFUNCTION already defined
#endif
#define MPLLIBS_DEFINE_TAG_DISPATCHING_METAFUNCTION(name, arg_num) \
  struct invalid_args_for_##name : \
    mpllibs::metamonad::tmp_value< \
      invalid_args_for_##name, \
      mpllibs::metamonad::overloading_error_tag \
    > \
  {}; \
  \
  template <BOOST_PP_ENUM_PARAMS(arg_num, class Tag)> \
  struct name##_impl : \
    mpllibs::metamonad::tmp_value< \
      name##_impl<BOOST_PP_ENUM_PARAMS(arg_num, Tag)> \
    > \
  { \
    template <BOOST_PP_ENUM_PARAMS(arg_num, class T)> \
    struct apply : mpllibs::metamonad::exception<invalid_args_for_##name> {}; \
  }; \
  \
  template <BOOST_PP_ENUM_PARAMS(arg_num, class T)> \
  struct name : \
    name##_impl< \
      BOOST_PP_REPEAT(arg_num, MPLLIBS_DEFINE_TD_METAFUNCTION_GET_TAG, ~) \
    >:: \
      template apply< \
        BOOST_PP_REPEAT(arg_num, MPLLIBS_DEFINE_TD_METAFUNCTION_EVAL_ARG, ~) \
      > \
  {};

#endif

