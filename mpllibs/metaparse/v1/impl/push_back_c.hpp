#ifndef MPLLIBS_METAPARSE_V1_PUSH_BACK_C_HPP
#define MPLLIBS_METAPARSE_V1_PUSH_BACK_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/v1/fwd/string.hpp>
#include <mpllibs/metaparse/v1/impl/update_c.hpp>
#include <mpllibs/metaparse/v1/impl/size.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        template <class S, char C>
        struct push_back_c;

#ifdef MPLLIBS_VARIADIC_STRING
        template <char... Cs, char C>
        struct push_back_c<string<Cs...>, C> : string<Cs..., C> {};
#else
        template <class S, char C>
        struct push_back_c :
          update_c<typename S::type, size<typename S::type>::type::value, C>
        {};
#endif
      }
    }
  }
}

#endif

