#ifndef MPLLIBS_METAMONAD_LAZY_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_LAZY_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/metafunction.hpp>
#include <mpllibs/metamonad/curried_call.hpp>

#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/cat.hpp>

#ifdef MPLLIBS_LAZY_EVAL_ARG
  #error MPLLIBS_LAZY_EVAL_ARG already defined
#endif
#define MPLLIBS_LAZY_EVAL_ARG(r, unused, n, arg) \
  BOOST_PP_COMMA_IF(n) typename arg::type

#ifdef MPLLIBS_LAZY_EVAL_ARGS
  #error MPLLIBS_LAZY_EVAL_ARGS already defined
#endif
#define MPLLIBS_LAZY_EVAL_ARGS(args) \
  BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_LAZY_EVAL_ARG, ~, args)

#ifdef MPLLIBS_LAZY_METAFUNCTION
  #error MPLLIBS_LAZY_METAFUNCTION already defined
#endif
#define MPLLIBS_LAZY_METAFUNCTION(name, args) \
  MPLLIBS_DECLARE_HELPER(name, args) \
  \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct BOOST_PP_CAT(name, ___impl); \
  \
  template <MPLLIBS_EXPAND_ARGS_USAGE_WITH_NA(args)> \
  struct name : \
    BOOST_PP_CAT(mpllibs::metamonad::curried_call, BOOST_PP_SEQ_SIZE(args))< \
      BOOST_PP_CAT(name, ___impl), \
      MPLLIBS_EXPAND_ARGS_REF(args) \
    > \
  {}; \
  \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct BOOST_PP_CAT(name, ___impl) : \
    MPLLIBS_HELPER_METAFUNCTION(name)<MPLLIBS_LAZY_EVAL_ARGS(args)> \
  {}; \
  \
  MPLLIBS_DEFINE_HELPER(name, args)

#endif

