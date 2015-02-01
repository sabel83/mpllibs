#ifndef MPLLIBS_METAPARSE_V2_IMPL_SEQUENCE_HPP
#define MPLLIBS_METAPARSE_V2_IMPL_SEQUENCE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/impl/sequence_impl.hpp>
#include <mpllibs/metaparse/limit_sequence_size.hpp>

#include <boost/mpl/vector.hpp>

#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/cat.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace impl
      {
        #ifdef MPLLIBS_SEQUENCE_CASE
        #  error MPLLIBS_SEQUENCE_CASE already defined
        #endif
        #define MPLLIBS_SEQUENCE_CASE(z, n, unused) \
          template <BOOST_PP_ENUM_PARAMS(n, class P)> \
          struct BOOST_PP_CAT(sequence, n) \
          { \
            typedef BOOST_PP_CAT(sequence, n) type; \
            \
            template <class S, class Pos> \
            struct apply : \
              sequence_impl< \
                boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, P)>, \
                S, \
                Pos \
              > \
            {}; \
          };
        
        BOOST_PP_REPEAT_FROM_TO(
          1,
          MPLLIBS_LIMIT_SEQUENCE_SIZE,
          MPLLIBS_SEQUENCE_CASE,
          ~
        )
        
        #undef MPLLIBS_SEQUENCE_CASE
      } 
    }
  }
}

#endif

