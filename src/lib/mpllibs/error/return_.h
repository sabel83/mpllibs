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
     * Syntactic sugar
     */
    #ifdef RETURN
      #error RETURN already defined
    #endif
    #define RETURN mpllibs::error::return_
  
    /*
     * return_
     */
    template <class>
    struct return__impl;
    // No default implementation

    template <class monad>
    struct return_
    {
      template <class a>
      struct apply :
        boost::mpl::apply<
          mpllibs::error::return__impl<typename boost::mpl::tag<monad>::type>,
          a
        >
      {};
    };
  }
}

#endif

