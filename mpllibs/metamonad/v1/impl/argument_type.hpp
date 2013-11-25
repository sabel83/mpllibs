#ifndef MPLLIBS_METAMONAD_V1_IMPL_ARGUMENT_TYPE_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_ARGUMENT_TYPE_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      template <class T>
      struct argument_type;

      template <class T>
      struct argument_type<void (*)(T)>
      {
        typedef T type;
      };
    }
  }
}

#endif

