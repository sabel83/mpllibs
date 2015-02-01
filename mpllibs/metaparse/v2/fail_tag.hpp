#ifndef MPLLIBS_METAPARSE_V2_FAIL_TAG_HPP
#define MPLLIBS_METAPARSE_V2_FAIL_TAG_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>

#include <mpllibs/metaparse/v2/fwd/get_message.hpp>
#include <mpllibs/metaparse/v2/fwd/get_position.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      struct fail_tag : metamonad::tmp_tag<fail_tag> {};

      template <>
      struct get_message_impl<fail_tag>
      {
        template <class A>
        struct apply { typedef typename A::message type; };
      };

      template <>
      struct get_position_impl<fail_tag>
      {
        template <class A>
        struct apply : A::source_position {};
      };
    }
  }
}

#endif


