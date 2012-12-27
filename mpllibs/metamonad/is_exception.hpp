#ifndef MPLLIBS_METAMONAD_IS_EXCEPTION_HPP
#define MPLLIBS_METAMONAD_IS_EXCEPTION_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/exception_core.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>

#include <boost/mpl/tag.hpp>

#include <boost/type_traits/is_same.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_LAZY_METAFUNCTION(is_exception, (T))
    ((boost::is_same<exception_tag, typename boost::mpl::tag<T>::type>));
  }
}

#endif

