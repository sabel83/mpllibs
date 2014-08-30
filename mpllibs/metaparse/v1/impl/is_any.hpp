#ifndef MPLLIBS_METAPARSE_V1_IMPL_IS_ANY_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_IS_ANY_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/limit_one_char_except_size.hpp>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/apply_wrap.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        template <class Stub = int>
        struct is_any0
        {
          template <class C>
          struct apply : boost::mpl::true_ {};
        };

        #ifdef MPLLIBS_METAPARSE_DEFINE_IS_ANY
        #  error MPLLIBS_METAPARSE_DEFINE_IS_ANY already defined
        #endif
        #define MPLLIBS_METAPARSE_DEFINE_IS_ANY(z, n, unused) \
          template <BOOST_PP_ENUM_PARAMS(n, class T)> \
          struct BOOST_PP_CAT(is_any, n) \
          { \
            template <class C> \
            struct apply : \
              boost::mpl::eval_if< \
                boost::mpl::bool_< \
                  C::type::value \
                  == BOOST_PP_CAT(T, BOOST_PP_DEC(n))::type::value \
                >, \
                boost::mpl::false_, \
                boost::mpl::apply_wrap1< \
                  BOOST_PP_CAT(is_any, BOOST_PP_DEC(n))< \
                    BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), T) \
                  >, \
                  C \
                > \
              > \
            {}; \
          };

        BOOST_PP_REPEAT_FROM_TO(
          1,
          MPLLIBS_LIMIT_ONE_CHAR_EXCEPT_SIZE,
          MPLLIBS_METAPARSE_DEFINE_IS_ANY,
          ~
        )

        #undef MPLLIBS_METAPARSE_DEFINE_IS_ANY
      }
    }
  }
}

#endif

