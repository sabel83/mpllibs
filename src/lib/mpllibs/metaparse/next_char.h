#ifndef MPLLIBS_PARSER_NEXT_CHAR_H
#define MPLLIBS_PARSER_NEXT_CHAR_H

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/int.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/tag.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P>
    struct next_char_impl;
    
    template <class P, class Ch>
    struct next_char :
      boost::mpl::apply<
        next_char_impl<typename boost::mpl::tag<typename P::type>::type>,
        typename P::type,
        typename Ch::type
      >
    {};
  }
}

#endif

