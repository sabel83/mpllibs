#ifndef MPLLIBS_METAMONAD_HELPER_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_HELPER_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/preprocessor/cat.hpp>

#ifndef MPLLIBS_HELPER_METAFUNCTION
#  define MPLLIBS_HELPER_METAFUNCTION(name) BOOST_PP_CAT(name, __impl)
#endif

#endif

