#ifndef MPLLIBS_ERROR_GET_LINE_H
#define MPLLIBS_ERROR_GET_LINE_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply.hpp>
#include <boost/mpl/tag.hpp>

namespace mpllibs
{
  namespace error
  {
    template <class>
    struct get_line_impl;
    
    template <class e>
    struct get_line :
      boost::mpl::apply<
        mpllibs::error::get_line_impl<
          typename boost::mpl::tag<typename e::type>::type
        >,
        typename e::type
      >
    {};
  }
}

#endif

