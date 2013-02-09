#ifndef MPLLIBS_METAMONAD_IF_HPP
#define MPLLIBS_METAMONAD_IF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_METAFUNCTION(if_, (C)(T)(F))
    ((boost::mpl::eval_if<typename C::type, T, F>));
  }
}

#endif

