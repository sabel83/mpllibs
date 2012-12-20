#ifndef MPLLIBS_METAMONAD_LAZY_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_LAZY_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>

#ifndef MPLLIBS_HELPER_METAFUNCTION
  #define MPLLIBS_HELPER_METAFUNCTION(name) BOOST_PP_CAT(name, __impl)
#endif

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
  MPLLIBS_LAZY_DECLARE_HELPER(name, args) \
  \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct name : \
    MPLLIBS_HELPER_METAFUNCTION(name)<MPLLIBS_LAZY_EVAL_ARGS(args)> \
  {}; \
  \
  MPLLIBS_LAZY_DEFINE_HELPER(name, args)

#ifdef MPLLIBS_LAZY_VARIADIC_METAFUNCTION
  #error MPLLIBS_LAZY_VARIADIC_METAFUNCTION already defined
#endif
#define MPLLIBS_LAZY_VARIADIC_METAFUNCTION(name, args, pack_name) \
  MPLLIBS_LAZY_DECLARE_HELPER(name, args(...pack_name)) \
  \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args(...pack_name))> \
  struct name : \
    MPLLIBS_HELPER_METAFUNCTION(name)< \
      MPLLIBS_LAZY_EVAL_ARGS(args) \
      BOOST_PP_COMMA_IF(BOOST_PP_SEQ_SIZE(args)) typename pack_name::type... \
    > \
  {}; \
  \
  MPLLIBS_LAZY_DEFINE_HELPER(name, args(...pack_name))

#ifdef MPLLIBS_LAZY_DECLARE_HELPER
  #error MPLLIBS_LAZY_DECLARE_HELPER already defined
#endif
#define MPLLIBS_LAZY_DECLARE_HELPER(name, args) \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct MPLLIBS_HELPER_METAFUNCTION(name);

#ifdef MPLLIBS_LAZY_DEFINE_HELPER
  #error MPLLIBS_LAZY_DEFINE_HELPER already defined
#endif
#define MPLLIBS_LAZY_DEFINE_HELPER(name, args) \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct MPLLIBS_HELPER_METAFUNCTION(name) : MPLLIBS_METAFUNCTION_BODY

#ifdef MPLLIBS_LAZY_VARIADIC_METAFUNCTION_CLASS
  #error MPLLIBS_LAZY_VARIADIC_METAFUNCTION_CLASS
#endif
#define MPLLIBS_LAZY_VARIADIC_METAFUNCTION_CLASS(name, args, pack_name) \
  MPLLIBS_LAZY_DECLARE_HELPER(name, args(...pack_name)) \
  \
  struct name \
  { \
    typedef name type; \
    \
    template <MPLLIBS_EXPAND_ARGS_USAGE(args(...pack_name))> \
    struct apply : \
      MPLLIBS_HELPER_METAFUNCTION(name)< \
        MPLLIBS_LAZY_EVAL_ARGS(args) \
        BOOST_PP_COMMA_IF(BOOST_PP_SEQ_SIZE(args)) typename pack_name::type... \
      > \
    {}; \
  }; \
  \
  MPLLIBS_LAZY_DEFINE_HELPER(name, args(...pack_name))

#ifdef MPLLIBS_LAZY_METAFUNCTION_CLASS
  #error MPLLIBS_LAZY_METAFUNCTION_CLASS
#endif
#define MPLLIBS_LAZY_METAFUNCTION_CLASS(name, args) \
  MPLLIBS_LAZY_DECLARE_HELPER(name, args) \
  \
  struct name \
  { \
    typedef name type; \
    \
    template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
    struct apply : \
      MPLLIBS_HELPER_METAFUNCTION(name)<MPLLIBS_LAZY_EVAL_ARGS(args)> \
    {}; \
  }; \
  \
  MPLLIBS_LAZY_DEFINE_HELPER(name, args)
#endif

