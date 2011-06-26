#ifndef MPLLIBS_METAMONAD_TAG_TAG_HPP
#define MPLLIBS_METAMONAD_TAG_TAG_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <mpllibs/metamonad/meta_atom.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    MPLLIBS_DEFINE_META_ATOM(tag_tag, tag_tag);
    
    #ifdef MPLLIBS_DEFINE_TAG
      #error MPLLIBS_DEFINE_TAG already defined
    #endif
    #define MPLLIBS_DEFINE_TAG(name) \
      MPLLIBS_DEFINE_META_ATOM(mpllibs::metamonad::tag_tag, name)
  }
}

#endif

