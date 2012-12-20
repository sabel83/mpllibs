#ifndef MPLLIBS_METAMONAD_LAZY_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_LAZY_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <boost/preprocessor/seq/seq.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/cat.hpp>

#ifdef MPLLIBS_LAZY_EXPAND_ARG
  #error MPLLIBS_LAZY_EXPAND_ARG already defined
#endif
#define MPLLIBS_LAZY_EXPAND_ARG(r, unused, n, arg) \
  BOOST_PP_COMMA_IF(n) class BOOST_PP_CAT(arg, _)

#ifdef MPLLIBS_LAZY_EXPAND_ARGS
  #error MPLLIBS_LAZY_EXPAND_ARGS already defined
#endif
#define MPLLIBS_LAZY_EXPAND_ARGS(args) \
  BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_LAZY_EXPAND_ARG, ~, args)

#ifdef MPLLIBS_LAZY_EXPAND_ARG_DEF
  #error MPLLIBS_LAZY_EXPAND_ARG_DEF already defined
#endif
#define MPLLIBS_LAZY_EXPAND_ARG_DEF(r, unused, arg) \
  typedef typename BOOST_PP_CAT(arg, _)::type arg;

#ifdef MPLLIBS_LAZY_EXPAND_ARGS_DEF
  #error MPLLIBS_LAZY_EXPAND_ARGS_DEF already defined
#endif
#define MPLLIBS_LAZY_EXPAND_ARGS_DEF(args) \
  private: \
    BOOST_PP_SEQ_FOR_EACH(MPLLIBS_LAZY_EXPAND_ARG_DEF, ~, args) \
  public:

#ifdef MPLLIBS_LAZY_METAFUNCTION
  #error MPLLIBS_LAZY_METAFUNCTION already defined
#endif
#define MPLLIBS_LAZY_METAFUNCTION(name, args) \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct BOOST_PP_CAT(name, _impl); \
  \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct name : BOOST_PP_CAT(name, _impl)<BOOST_PP_SEQ_ENUM(args)>::type {}; \
  \
  template <MPLLIBS_LAZY_EXPAND_ARGS(args)> \
  struct BOOST_PP_CAT(name, _impl) \
  { \
    MPLLIBS_LAZY_EXPAND_ARGS_DEF(args) \
    \
    typedef typename mpllibs::metamonad::impl::make_dependent< \
      BOOST_PP_SEQ_HEAD(args), \
      MPLLIBS_LAZY_METAFUNCTION_BODY

#ifdef MPLLIBS_LAZY_METAFUNCTION_CLASS
  #error MPLLIBS_LAZY_METAFUNCTION_CLASS
#endif
#define MPLLIBS_LAZY_METAFUNCTION_CLASS(name, args) \
  struct name \
  { \
    typedef name type; \
    \
    template <MPLLIBS_LAZY_EXPAND_ARGS(args)> \
    struct apply \
    { \
      MPLLIBS_LAZY_EXPAND_ARGS_DEF(args) \
      \
      typedef typename mpllibs::metamonad::impl::make_dependent< \
        BOOST_PP_SEQ_HEAD(args), \
        MPLLIBS_LAZY_METAFUNCTION_CLASS_BODY

#ifdef MPLLIBS_LAZY_METAFUNCTION_CLASS_BODY
  #error MPLLIBS_LAZY_METAFUNCTION_CLASS_BODY already defined
#endif
#define MPLLIBS_LAZY_METAFUNCTION_CLASS_BODY(body) \
    MPLLIBS_LAZY_METAFUNCTION_BODY(body); \
  }

#ifdef MPLLIBS_LAZY_METAFUNCTION_BODY
  #error MPLLIBS_LAZY_METAFUNCTION_BODY already defined
#endif

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
#if defined(BOOST_NO_CXX11_VARIADIC_MACROS) || defined(BOOST_NO_VARIADIC_MACROS)

      template <class, class T>
      struct make_dependent : returns<typename T::type> {};

#define MPLLIBS_LAZY_METAFUNCTION_BODY(body) \
    mpllibs::metamonad::impl::argument_type<void (*)body> >::type type; \
  }

#else

      template <class, class T>
      struct make_dependent : returns<T> {};

#define MPLLIBS_LAZY_METAFUNCTION_BODY(body) \
  MPLLIBS_UNPACK body >::type type; }

#endif
    }
  }
}

#endif

