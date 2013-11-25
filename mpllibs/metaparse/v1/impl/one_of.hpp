#ifndef MPLLIBS_METAPARSE_V1_IMPL_ONE_OF_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_ONE_OF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/limit_one_of_size.hpp>
#include <mpllibs/metaparse/v1/error/none_of_the_expected_cases_found.hpp>
#include <mpllibs/metaparse/v1/is_error.hpp>
#include <mpllibs/metaparse/v1/fail.hpp>

#include <boost/mpl/if.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        #ifdef MPLLIBS_ONE_OF_BODY_PREFIX
        #  error MPLLIBS_ONE_OF_BODY_PREFIX already defined
        #endif
        #define MPLLIBS_ONE_OF_BODY_PREFIX(z, n, unused) \
          typename boost::mpl::if_< \
            boost::mpl::not_< \
              typename is_error< \
                boost::mpl::apply<BOOST_PP_CAT(P, n), S, Pos> \
              >::type \
            >, \
            BOOST_PP_CAT(P, n), \
        
        #ifdef MPLLIBS_MPLLIBS_ONE_OF
        #  error MPLLIBS_MPLLIBS_ONE_OF already defined
        #endif
        #define MPLLIBS_MPLLIBS_ONE_OF(z, n, unused) \
          template <BOOST_PP_ENUM_PARAMS(n, class P)> \
          struct BOOST_PP_CAT(one_of_, n) \
          { \
            typedef BOOST_PP_CAT(one_of_, n) type; \
            \
            template <class S, class Pos> \
            struct apply : \
              boost::mpl::apply_wrap2< \
                BOOST_PP_REPEAT(n, MPLLIBS_ONE_OF_BODY_PREFIX, ~) \
                  fail<error::none_of_the_expected_cases_found> \
                BOOST_PP_REPEAT(n, >::type BOOST_PP_TUPLE_EAT(3), ~), \
                S, \
                Pos \
              > \
            {}; \
          };
        
        BOOST_PP_REPEAT_FROM_TO(
          1,
          MPLLIBS_LIMIT_ONE_OF_SIZE,
          MPLLIBS_MPLLIBS_ONE_OF,
          ~
        )
        
        #undef MPLLIBS_MPLLIBS_ONE_OF
        #undef MPLLIBS_ONE_OF_BODY_PREFIX
      }
    }
  }
}

#endif

