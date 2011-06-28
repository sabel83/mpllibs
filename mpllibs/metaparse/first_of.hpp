#ifndef MPLLIBS_METAPARSE_FIRST_OF_HPP
#define MPLLIBS_METAPARSE_FIRST_OF_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/nth_of.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        MPLLIBS_SEQUENCE_MAX_ARGUMENT,
        class P,
        mpllibs::metaparse::impl::sequence_no_argument
      )
    >
    struct first_of :
      nth_of_c<0, BOOST_PP_ENUM_PARAMS(MPLLIBS_SEQUENCE_MAX_ARGUMENT, P)>
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "first_of<";
          mpllibs::metatest::to_stream_argument_list<
            BOOST_PP_ENUM_PARAMS(MPLLIBS_SEQUENCE_MAX_ARGUMENT, P)
          >::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

