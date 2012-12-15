#ifndef MPLLIBS_METAMONAD_LAZY_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_LAZY_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/preprocessor/seq/enum.hpp>

#ifdef MPLLIBS_LAZY_REC_METAFUNCTION
  #error MPLLIBS_LAZY_REC_METAFUNCTION already defined
#endif
#define MPLLIBS_LAZY_REC_METAFUNCTION(name, args) \
  template <BOOST_PP_SEQ_ENUM(args)> \
  struct name : MPLLIBS_LAZY_REC_METAFUNCTION_BODY

#ifdef MPLLIBS_LAZY_METAFUNCTION_CLASS
  #error MPLLIBS_LAZY_METAFUNCTION_CLASS
#endif
#define MPLLIBS_LAZY_METAFUNCTION_CLASS(name, args) \
  struct name : mpllibs::metamonad::tmp_value<name> \
  { \
    template <BOOST_PP_SEQ_ENUM(args)> \
    MPLLIBS_LAZY_METAFUNCTION_CLASS_BODY

#ifdef MPLLIBS_LAZY_REC_METAFUNCTION_BODY
  #error MPLLIBS_LAZY_REC_METAFUNCTION_BODY already defined
#endif

#ifdef MPLLIBS_LAZY_METAFUNCTION
  #error MPLLIBS_LAZY_METAFUNCTION already defined
#endif

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES

#define MPLLIBS_LAZY_REC_METAFUNCTION_BODY(body) \
  mpllibs::metamonad::lazy< \
    typename mpllibs::metamonad::impl::argument_type<void (*)body>::type \
  > \
  {}

#define MPLLIBS_LAZY_METAFUNCTION MPLLIBS_LAZY_REC_METAFUNCTION

#define MPLLIBS_LAZY_METAFUNCTION_CLASS_BODY(body) \
    struct apply : MPLLIBS_LAZY_REC_METAFUNCTION_BODY(body); \
  }

#else

#ifdef MPLLIBS_LAZY_METAFUNCTION_BODY
  #error MPLLIBS_LAZY_METAFUNCTION_BODY already defined
#endif
#define MPLLIBS_LAZY_METAFUNCTION_BODY(body) \
  mpllibs::metamonad::lazy< MPLLIBS_UNPACK body >

#define MPLLIBS_LAZY_REC_METAFUNCTION_BODY(body) \
  MPLLIBS_LAZY_METAFUNCTION_BODY(body) {}

#define MPLLIBS_LAZY_METAFUNCTION(name, args) \
  template <BOOST_PP_SEQ_ENUM(args)> \
  using name = MPLLIBS_LAZY_METAFUNCTION_BODY

#define MPLLIBS_LAZY_METAFUNCTION_CLASS_BODY(body) \
    using apply = MPLLIBS_LAZY_METAFUNCTION_BODY(body); \
  }

#endif

#endif

