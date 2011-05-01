#ifndef MPLLIBS_PARSER_GET_RESULT_H
#define MPLLIBS_PARSER_GET_RESULT_H

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply.hpp>
#include <boost/mpl/tag.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P>
    struct get_result_impl;
    
    template <class P>
    struct get_result :
      boost::mpl::apply<
        get_result_impl<typename boost::mpl::tag<typename P::type>::type>,
        typename P::type
      >
    {};
  }
}

#endif

