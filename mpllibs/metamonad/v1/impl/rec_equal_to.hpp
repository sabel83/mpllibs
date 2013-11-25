#ifndef MPLLIBS_METAMONAD_V1_IMPL_REC_EQUAL_TO_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_REC_EQUAL_TO_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/rec_equal_to_impl.hpp>

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        // It detects when the same constructor is used for both values and
        // compares the constructor arguments using equal_to
        template <class A, class B>
        struct rec_equal_to : rec_equal_to_impl<A, B> {};

        template <class A>
        struct rec_equal_to<A, A> : boost::mpl::true_ {};
      }
    }
  }
}

#endif

