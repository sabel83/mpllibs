#ifndef MPLLIBS_METAMONAD_IS_NOTHING_HPP
#define MPLLIBS_METAMONAD_IS_NOTHING_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/nothing.hpp>
#include <mpllibs/metamonad/lazy_metafunction.hpp>

#include <boost/type_traits/is_same.hpp>

#include <boost/mpl/tag.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_LAZY_METAFUNCTION(is_nothing, (T))
    ((boost::is_same<typename boost::mpl::tag<T>::type, nothing_tag>));
  }
}

#endif

