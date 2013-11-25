#ifndef MPLLIBS_METAMONAD_V1_LAZY_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_V1_LAZY_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/helper_metafunction.hpp>

#include <mpllibs/metamonad/v1/impl/expand_arg_usage.hpp>
#include <mpllibs/metamonad/v1/impl/expand_arg_usage_with_na.hpp>
#include <mpllibs/metamonad/v1/impl/metafunction_body.hpp>
#include <mpllibs/metamonad/v1/impl/lazy_eval_arg.hpp>
#include <mpllibs/metamonad/v1/impl/curried_call.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/seq/size.hpp>

#ifdef MPLLIBS_V1_LAZY_METAFUNCTION
#  error MPLLIBS_V1_LAZY_METAFUNCTION already defined
#endif
#define MPLLIBS_V1_LAZY_METAFUNCTION(name, args) \
  template <BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_V1_EXPAND_ARG_USAGE, ~, args)> \
  struct MPLLIBS_HELPER_METAFUNCTION(name); \
  \
  template <BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_V1_EXPAND_ARG_USAGE, ~, args)> \
  struct BOOST_PP_CAT(name, ___impl); \
  \
  template < \
    BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_V1_EXPAND_ARG_USAGE_WITH_NA, ~, args) \
  > \
  struct name : \
    BOOST_PP_CAT( \
      mpllibs::metamonad::v1::impl::curried_call, \
      BOOST_PP_SEQ_SIZE(args) \
    )<BOOST_PP_CAT(name, ___impl), BOOST_PP_SEQ_ENUM(args)> \
  {}; \
  \
  template <BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_V1_EXPAND_ARG_USAGE, ~, args)> \
  struct BOOST_PP_CAT(name, ___impl) : \
    MPLLIBS_HELPER_METAFUNCTION(name)< \
      BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_V1_LAZY_EVAL_ARG, ~, args) \
    > \
  {}; \
  \
  template <BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_V1_EXPAND_ARG_USAGE, ~, args)> \
  struct MPLLIBS_HELPER_METAFUNCTION(name) : MPLLIBS_V1_METAFUNCTION_BODY

#endif

