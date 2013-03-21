#ifndef SAFE_PRINTF_POP_EXPECTED_HPP
#define SAFE_PRINTF_POP_EXPECTED_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/deque.hpp>
#include <boost/mpl/at.hpp>

namespace safe
{
  template <class Expected>
  struct pop_expected :
    boost::mpl::eval_if<
      typename boost::mpl::front<
        typename boost::mpl::front<Expected>::type
      >::type,
      boost::mpl::push_front<
        typename boost::mpl::pop_front<Expected>::type,
        boost::mpl::deque<
          boost::mpl::false_,
          typename boost::mpl::back<
            typename boost::mpl::front<Expected>::type
          >::type
        >
      >,
      boost::mpl::eval_if<
        typename boost::mpl::at_c<
          typename boost::mpl::front<Expected>::type,
          1
        >::type,
        boost::mpl::push_front<
          typename boost::mpl::pop_front<Expected>::type,
          boost::mpl::deque<
            boost::mpl::false_,
            boost::mpl::false_,
            typename boost::mpl::back<
              typename boost::mpl::front<Expected>::type
            >::type
          >
        >,
        boost::mpl::pop_front<Expected>
      >
    >
  {};
}

#endif

