#ifndef MPLLIBS_METAMONAD_IMPL_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_IMPL_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/config.hpp>

#ifdef BOOST_NO_CXX11_TEMPLATE_ALIASES

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

#else

#ifdef MPLLIBS_UNPACK
  #error MPLLIBS_UNPACK already defined
#endif
#define MPLLIBS_UNPACK(...) __VA_ARGS__

#endif

#endif

