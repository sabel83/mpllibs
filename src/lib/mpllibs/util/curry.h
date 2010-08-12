#ifndef MPLLIBS_UTIL_CURRY_H
#define MPLLIBS_UTIL_CURRY_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/minus.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/unpack_args.hpp>
#include <boost/mpl/deque.hpp>

namespace mpllibs
{
  namespace util
  {
    namespace impl
    {
      template <
        class UnpackedMetafunctionClass,
        class ArgumentsLeft,
        class ArgumentList
      >
      struct curryImpl;
  
  
  
      template <
        class UnpackedMetafunctionClass,
        class ArgumentsLeft,
        class ArgumentList
      >
      struct nextCurryingStep
      {
        typedef nextCurryingStep type;
      
        template <class T>
        struct apply :
          mpllibs::util::impl::curryImpl<
            UnpackedMetafunctionClass,
            typename boost::mpl::minus<
              ArgumentsLeft,
              boost::mpl::int_<1>
            >::type,
            typename boost::mpl::push_back<ArgumentList, T>::type
          >
        {};
      };
  
  
      template <
        class UnpackedMetafunctionClass,
        class ArgumentsLeft,
        class ArgumentList
      >
      struct curryImpl :
        boost::mpl::eval_if<
          typename boost::mpl::equal_to<
            ArgumentsLeft,
            boost::mpl::int_<0>
          >::type,
          boost::mpl::apply<UnpackedMetafunctionClass, ArgumentList>,
          mpllibs::util::impl::nextCurryingStep<
            UnpackedMetafunctionClass,
            ArgumentsLeft,
            ArgumentList
          >
        >
      {};
    }

    template <class MetafunctionClass, class ArgumentNumber>
    struct curry :
      mpllibs::util::impl::curryImpl<
        boost::mpl::unpack_args<MetafunctionClass>,
        ArgumentNumber,
        boost::mpl::deque<>
      >::type
    {};
  }
}

#endif

