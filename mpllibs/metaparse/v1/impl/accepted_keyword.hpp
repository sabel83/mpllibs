#ifndef MPLLIBS_METAPARSE_V1_IMPL_ACCEPTED_KEYWORD_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_ACCEPTED_KEYWORD_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/impl/accepted_keyword_tag.hpp>

#include <mpllibs/metamonad/tmp_value.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        struct accepted_keyword :
          metamonad::tmp_value<accepted_keyword, accepted_keyword_tag>
        {};
      }
    }
  }
}

#endif

