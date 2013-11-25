#ifndef MPLLIBS_METAPARSE_V1_IMPL_POP_BACK_HPP
#define MPLLIBS_METAPARSE_V1_IMPL_POP_BACK_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/config.hpp>
#include <mpllibs/metaparse/v1/fwd/string.hpp>
#include <mpllibs/metaparse/v1/impl/push_front_c.hpp>
#include <mpllibs/metaparse/v1/impl/size.hpp>
#include <mpllibs/metaparse/v1/impl/update_c.hpp>

#include <boost/mpl/clear.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      namespace impl
      {
        template <class S>
        struct pop_back;

#ifdef MPLLIBS_VARIADIC_STRING
        template <char C>
        struct pop_back<string<C>> : boost::mpl::clear<string<C>> {};

        template <char C, char... Cs>
        struct pop_back<string<C, Cs...>> :
          push_front_c<typename pop_back<string<Cs...>>::type, C>
        {};
#else
        template <class S>
        struct pop_back :
          update_c<
            typename S::type,
            size<typename S::type>::type::value - 1,
            MPLLIBS_NO_CHAR
          >
        {};
#endif
      }
    }
  }
}

#endif

