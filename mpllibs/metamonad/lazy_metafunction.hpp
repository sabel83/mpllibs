#ifndef MPLLIBS_METAMONAD_LAZY_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_LAZY_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/metafunction.hpp>
#include <mpllibs/metamonad/lazy.hpp>

#ifdef MPLLIBS_LAZY_REC_METAFUNCTION
  #error MPLLIBS_LAZY_REC_METAFUNCTION already defined
#endif

#ifdef MPLLIBS_LAZY_METAFUNCTION
  #error MPLLIBS_LAZY_METAFUNCTION already defined
#endif

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES

#define MPLLIBS_LAZY_REC_METAFUNCTION(name, body) \
  struct name : \
    mpllibs::metamonad::lazy< \
      typename mpllibs::metamonad::impl::argument_type<void (*)body>::type \
    > \
  {}

#define MPLLIBS_LAZY_METAFUNCTION MPLLIBS_LAZY_REC_METAFUNCTION

#else

#define MPLLIBS_LAZY_REC_METAFUNCTION(name, body) \
  struct name : mpllibs::metamonad::lazy< MPLLIBS_UNPACK body > {};

#define MPLLIBS_LAZY_METAFUNCTION(name, body) \
  using name = mpllibs::metamonad::lazy< MPLLIBS_UNPACK body >

#endif

#endif

