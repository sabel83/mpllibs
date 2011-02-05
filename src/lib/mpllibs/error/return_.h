#ifndef MPLLIBS_ERROR_RETURN__H
#define MPLLIBS_ERROR_RETURN__H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply.hpp>
#include <boost/mpl/tag.hpp>

namespace mpllibs
{
  namespace error
  {
    /*
     * return_
     */
    template <class>
    struct return__impl;
    // No default implementation
    
    struct no_return_argument;

    // monad_tag is lazy
    template <class monad_tag, class a = mpllibs::error::no_return_argument>
    struct return_ :
      boost::mpl::apply<mpllibs::error::return_<monad_tag>, a>
    {};
    
    template <class monad_tag>
    struct return_<monad_tag, mpllibs::error::no_return_argument>
    {
      template <class a>
      struct apply :
        boost::mpl::apply<
          mpllibs::error::return__impl<typename monad_tag::type>,
          a
        >
      {};
    };
  }
}

#endif

