#ifndef MPLLIBS_METATEST_TO_STREAM_ARGUMENT_LIST_HPP
#define MPLLIBS_METATEST_TO_STREAM_ARGUMENT_LIST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metatest
  {
    #ifndef MPLLIBS_TO_STREAM_ARGUMENT_LIST_MAX_ARG
      #define MPLLIBS_TO_STREAM_ARGUMENT_LIST_MAX_ARG 20
    #endif
    
    struct to_stream_argument_list_no_arg;
    
    namespace impl
    {
      template <int N, class T>
      struct to_stream_arg
      {
        static void run(std::ostream& o)
        {
          if (N > 0)
          {
            o << ", ";
          }
          to_stream<T>::run(o);
        }
      };

      template <int N>
      struct to_stream_arg<N, mpllibs::metatest::to_stream_argument_list_no_arg>
      {
        static void run(std::ostream&) {}
      };
    }

    #ifdef MPLLIBS_TO_STREAM_CASE
      #error MPLLIBS_TO_STREAM_CASE already defined
    #endif
    #define MPLLIBS_TO_STREAM_CASE(z, n, unused) \
      mpllibs::metatest::impl::to_stream_arg<n, T##n>::run(o);
    
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_TO_STREAM_ARGUMENT_LIST_MAX_ARG,
        class T,
        to_stream_argument_list_no_arg
      )
    >
    struct to_stream_argument_list
    {
      static std::ostream& run(std::ostream& o)
      {
        BOOST_PP_REPEAT(
          MPLLIBS_TO_STREAM_ARGUMENT_LIST_MAX_ARG,
          MPLLIBS_TO_STREAM_CASE,
          ~
        );
        return o;
      }
      
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "to_stream_argument_list<";
          to_stream_argument_list<
            BOOST_PP_ENUM_PARAMS(MPLLIBS_TO_STREAM_ARGUMENT_LIST_MAX_ARG, T)
          >::run(o);
          return o << ">";
        }
      };
    };
    
    #undef MPLLIBS_TO_STREAM_CASE
  }
}

#endif

