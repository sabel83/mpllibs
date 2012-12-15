#ifndef MPLLIBS_METAMONAD_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/impl/metafunction.hpp>

#ifdef MPLLIBS_REC_METAFUNCTION
  #error MPLLIBS_REC_METAFUNCTION already defined
#endif

#ifdef MPLLIBS_METAFUNCTION
  #error MPLLIBS_METAFUNCTION already defined
#endif

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES

#define MPLLIBS_REC_METAFUNCTION(name, body) \
  struct name : mpllibs::metamonad::impl::argument_type<void (*)body>::type {}

#define MPLLIBS_METAFUNCTION MPLLIBS_REC_METAFUNCTION

#else

#define MPLLIBS_REC_METAFUNCTION(name, body) \
  struct name : MPLLIBS_UNPACK body {};

#define MPLLIBS_METAFUNCTION(name, body) using name = MPLLIBS_UNPACK body

#endif

#endif

