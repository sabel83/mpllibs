#ifndef MPLLIBS_METAPARSE_V2_ANY_ONE_OF_HPP
#define MPLLIBS_METAPARSE_V2_ANY_ONE_OF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/limit_one_of_size.hpp>
#include <mpllibs/metaparse/v2/impl/one_of.hpp>
#include <mpllibs/metaparse/v2/any.hpp>

#include <boost/mpl/vector.hpp>

#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <
        BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
          MPLLIBS_LIMIT_ONE_OF_SIZE,
          class P,
          boost::mpl::na
        )
      >
      struct any_one_of :
        any<
          impl::one_of<
            boost::mpl::vector<
              BOOST_PP_ENUM_PARAMS(MPLLIBS_LIMIT_ONE_OF_SIZE, P)
            >
          >
        >
      {};
    }
  }
}

#endif

