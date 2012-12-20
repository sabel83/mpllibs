#ifndef MPLLIBS_METAMONAD_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/metafunction.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#ifdef MPLLIBS_METAFUNCTION
  #error MPLLIBS_METAFUNCTION already defined
#endif
#define MPLLIBS_METAFUNCTION(name, args) \
  template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
  struct name : MPLLIBS_METAFUNCTION_BODY

#ifdef MPLLIBS_VARIADIC_METAFUNCTION
  #error MPLLIBS_VARIADIC_METAFUNCTION already defined
#endif
#define MPLLIBS_VARIADIC_METAFUNCTION(name, args, pack_name) \
  MPLLIBS_METAFUNCTION(name, args(...pack_name))

#ifdef MPLLIBS_METAFUNCTION_CLASS
  #error MPLLIBS_METAFUNCTION_CLASS
#endif
#define MPLLIBS_METAFUNCTION_CLASS(name, args) \
  struct name \
  { \
    typedef name type; \
    \
    template <MPLLIBS_EXPAND_ARGS_USAGE(args)> \
    MPLLIBS_METAFUNCTION_CLASS_BODY

#ifdef MPLLIBS_METAFUNCTION_CLASS_BODY
  #error MPLLIBS_METAFUNCTION_CLASS_BODY already defined
#endif
#define MPLLIBS_METAFUNCTION_CLASS_BODY(body) \
    struct apply : MPLLIBS_METAFUNCTION_BODY(body); \
  }

#ifdef MPLLIBS_VARIADIC_METAFUNCTION_CLASS
  #error MPLLIBS_VARIADIC_METAFUNCTION_CLASS already defined
#endif
#define MPLLIBS_VARIADIC_METAFUNCTION_CLASS(name, args, pack_name) \
  MPLLIBS_METAFUNCTION_CLASS(name, args(...pack_name))

#endif

