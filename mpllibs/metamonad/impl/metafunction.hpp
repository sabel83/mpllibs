#ifndef MPLLIBS_METAMONAD_IMPL_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_IMPL_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/returns.hpp>

#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/cat.hpp>

#include <boost/config.hpp>

#ifndef MPLLIBS_HELPER_METAFUNCTION
  #define MPLLIBS_HELPER_METAFUNCTION(name) BOOST_PP_CAT(name, __impl)
#endif

#ifdef MPLLIBS_EXPAND_ARG_REF
  #error MPLLIBS_EXPAND_ARG_REF already defined
#endif
#define MPLLIBS_EXPAND_ARG_REF(r, unused, n, arg) BOOST_PP_COMMA_IF(n) arg

#ifdef MPLLIBS_EXPAND_ARGS_REF
  #error MPLLIBS_EXPAND_ARGS_REF already defined
#endif
#define MPLLIBS_EXPAND_ARGS_REF(args) \
  BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_EXPAND_ARG_REF, ~, args)

#ifdef MPLLIBS_EXPAND_ARG_USAGE
  #error MPLLIBS_EXPAND_ARG_USAGE already defined
#endif
#define MPLLIBS_EXPAND_ARG_USAGE(r, unused, n, arg) \
  BOOST_PP_COMMA_IF(n) class arg

#ifdef MPLLIBS_EXPAND_ARGS_USAGE
  #error MPLLIBS_EXPAND_ARGS_USAGE already defined
#endif
#define MPLLIBS_EXPAND_ARGS_USAGE(args) \
  BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_EXPAND_ARG_USAGE, ~, args)

#ifdef MPLLIBS_EXPAND_ARG_USAGE_WITH_NA
  #error MPLLIBS_EXPAND_ARG_USAGE_WITH_NA already defined
#endif
#define MPLLIBS_EXPAND_ARG_USAGE_WITH_NA(r, unused, n, arg) \
  BOOST_PP_COMMA_IF(n) class arg = boost::mpl::na

#ifdef MPLLIBS_EXPAND_ARGS_USAGE_WITH_NA
  #error MPLLIBS_EXPAND_ARGS_USAGE_WTIH_NA already defined
#endif
#define MPLLIBS_EXPAND_ARGS_USAGE_WITH_NA(args) \
  BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_EXPAND_ARG_USAGE_WITH_NA, ~, args)

#ifdef MPLLIBS_DECLARE_HELPER
  #error MPLLIBS_DECLARE_HELPER already defined
#endif
#define MPLLIBS_DECLARE_HELPER(name, args) \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct MPLLIBS_HELPER_METAFUNCTION(name);

#ifdef MPLLIBS_DEFINE_HELPER
  #error MPLLIBS_DEFINE_HELPER already defined
#endif
#define MPLLIBS_DEFINE_HELPER(name, args) \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct MPLLIBS_HELPER_METAFUNCTION(name) : MPLLIBS_METAFUNCTION_BODY

#ifdef MPLLIBS_METAFUNCTION_BODY
  #error MPLLIBS_METAFUNCTION_BODY already defined
#endif

#if defined(BOOST_NO_CXX11_VARIADIC_MACROS) || defined(BOOST_NO_VARIADIC_MACROS)

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      template <class T>
      struct argument_type;

      template <class T>
      struct argument_type<void (*)(T)>
      {
        typedef T type;
      };
    }
  }
}

#define MPLLIBS_METAFUNCTION_BODY(body) \
  mpllibs::metamonad::impl::argument_type<void (*)body>::type {}

#else

#ifdef MPLLIBS_UNPACK
  #error MPLLIBS_UNPACK already defined
#endif
#define MPLLIBS_UNPACK(...) __VA_ARGS__

// returns is used to make
//    MPLLIBS_METAFUNCTION(x, (class T)) ((typename f<T>::type))
// work the same way as it does without variadic macros
#define MPLLIBS_METAFUNCTION_BODY(body) \
  mpllibs::metamonad::returns< MPLLIBS_UNPACK body >::type {}

#endif

#endif

