#ifndef MPLLIBS_METAPARSE_GET_REMAINING_HPP
#define MPLLIBS_METAPARSE_GET_REMAINING_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/tag.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P>
    struct get_remaining_impl;
    
    template <class P>
    struct get_remaining :
      get_remaining_impl<typename boost::mpl::tag<typename P::type>::type>::
        template apply<typename P::type>
    {};
  }
}

#endif

