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
#include <boost/mpl/quote.hpp>

#include <boost/preprocessor/repetition.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/repeat_from_to.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace util
    {
      #ifndef CURRY_MAX_ARGUMENT
        #define CURRY_MAX_ARGUMENT 5
      #endif

      namespace impl
      {
        template <
          class UnpackedMetafunctionClass,
          class ArgumentsLeft,
          class ArgumentList
        >
        struct curry_impl;
  
  
  
        template <
          class UnpackedMetafunctionClass,
          class ArgumentsLeft,
          class ArgumentList
        >
        struct next_currying_step
        {
          typedef next_currying_step type;
      
          template <class T>
          struct apply :
            curry_impl<
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
        struct curry_impl :
          boost::mpl::eval_if<
            typename boost::mpl::equal_to<
              ArgumentsLeft,
              boost::mpl::int_<0>
            >::type,
            boost::mpl::apply<UnpackedMetafunctionClass, ArgumentList>,
            next_currying_step<
              UnpackedMetafunctionClass,
              ArgumentsLeft,
              ArgumentList
            >
          >
        {};
      }

    
      template <class T>
      struct curry0 : T {};

      #ifdef CLASS_REPEAT
        #error CLASS_REPEAT already defined
      #endif
      #define CLASS_REPEAT(z, n, unused) BOOST_PP_COMMA_IF(n) class

      #ifdef CURRY
        #error CURRY already defined
      #endif
      #define CURRY(z, n, unused) \
        template <template <BOOST_PP_REPEAT(n, CLASS_REPEAT, ~)> class T> \
        struct curry##n : \
          mpllibs::metaparse::util::impl::curry_impl< \
            boost::mpl::unpack_args<boost::mpl::quote##n <T> >, \
            boost::mpl::int_<n>, \
            boost::mpl::deque<> \
          >::type \
          {};
    
      BOOST_PP_REPEAT_FROM_TO(1, CURRY_MAX_ARGUMENT, CURRY, ~)
    
      #undef CURRY
      #undef CLASS_REPEAT
    }
  }
}

#endif

