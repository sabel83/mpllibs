#ifndef MPLLIBS_METAMONAD_V1_IMPL_EXPAND_ARG_USAGE_WITH_NA_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_EXPAND_ARG_USAGE_WITH_NA_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/preprocessor/punctuation/comma_if.hpp>

#ifdef MPLLIBS_V1_EXPAND_ARG_USAGE_WITH_NA
#  error MPLLIBS_V1_EXPAND_ARG_USAGE_WITH_NA already defined
#endif
#define MPLLIBS_V1_EXPAND_ARG_USAGE_WITH_NA(r, unused, n, arg) \
  BOOST_PP_COMMA_IF(n) class arg = boost::mpl::na

#endif

