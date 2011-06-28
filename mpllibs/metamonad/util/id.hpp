#ifndef MPLLIBS_ERROR_UTIL_ID_HPP
#define MPLLIBS_ERROR_UTIL_ID_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_argument_list.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace util
    {
      template <class T>
      struct id
      {
        typedef T type;
        
        struct to_stream
        {
          static std::ostream& run(std::ostream& o)
          {
            o << "id<";
            mpllibs::metatest::to_stream_argument_list<T>::run(o);
            return o << ">";
          }
        };
      };
    }
  }
}

#endif

