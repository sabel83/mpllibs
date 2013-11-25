#ifndef MPLLIBS_METAMONAD_V1_IMPL_UNPACK_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_UNPACK_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/config.hpp>

#if \
  !defined(BOOST_NO_CXX11_VARIADIC_MACROS) && !defined(BOOST_NO_VARIADIC_MACROS)

#ifdef MPLLIBS_V1_UNPACK
#  error MPLLIBS_V1_UNPACK already defined
#endif
#define MPLLIBS_V1_UNPACK(...) __VA_ARGS__

#endif

#endif

