#ifndef MPLLIBS_METAMONAD_V1_IMPL_METAFUNCTION_BODY_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_METAFUNCTION_BODY_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/unpack.hpp>
#include <mpllibs/metamonad/v1/impl/argument_type.hpp>

#include <mpllibs/metamonad/v1/returns.hpp>

#include <boost/config.hpp>

#ifdef MPLLIBS_V1_METAFUNCTION_BODY
#  error MPLLIBS_V1_METAFUNCTION_BODY already defined
#endif

#if defined(BOOST_NO_CXX11_VARIADIC_MACROS) || defined(BOOST_NO_VARIADIC_MACROS)

#define MPLLIBS_V1_METAFUNCTION_BODY(body) \
  mpllibs::metamonad::v1::impl::argument_type<void (*)body>::type {}

#else

// returns is used to make
//    MPLLIBS_V1_METAFUNCTION(x, (class T)) ((typename f<T>::type))
// work the same way as it does without variadic macros
#define MPLLIBS_V1_METAFUNCTION_BODY(body) \
  mpllibs::metamonad::v1::returns< MPLLIBS_V1_UNPACK body >::type {}

#endif

#endif

