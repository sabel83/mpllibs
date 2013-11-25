#ifndef MPLLIBS_METAPARSE_V1_ACCEPT_TAG_HPP
#define MPLLIBS_METAPARSE_V1_ACCEPT_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/fwd/get_remaining.hpp>
#include <mpllibs/metaparse/v1/fwd/get_position.hpp>
#include <mpllibs/metaparse/v1/fwd/get_result.hpp>

#include <mpllibs/metamonad/tmp_tag.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      struct accept_tag : metamonad::tmp_tag<accept_tag> {};

      template <>
      struct get_position_impl<accept_tag>
      {
        template <class A>
        struct apply : A::source_position {};
      };

      template <>
      struct get_remaining_impl<accept_tag>
      {
        template <class A>
        struct apply : A::remaining {};
      };

      template <>
      struct get_result_impl<accept_tag>
      {
        template <class A>
        struct apply : A::result {};
      };
    }
  }
}

#endif

