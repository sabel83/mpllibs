#ifndef MPLLIBS_METAMONAD_IMPL_METAFUNCTION_HPP
#define MPLLIBS_METAMONAD_IMPL_METAFUNCTION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>

#include <boost/config.hpp>

#ifdef MPLLIBS_EXPAND_ARG_USAGE
  #error MPLLIBS_EXPAND_ARG_USAGE already defined
#endif
#define MPLLIBS_EXPAND_ARG_USAGE(r, unused, n, arg) \
  BOOST_PP_COMMA_IF(n) class arg

#ifdef MPLLIBS_EXPAND_ARGS_USAGE
  #error MPLLIBS_EXPAND_ARGS_USAGE already defined
#endif
#define MPLLIBS_EXPAND_ARGS_USAGE(args) \
  BOOST_PP_SEQ_FOR_EACH_I(MPLLIBS_EXPAND_ARG_USAGE, ~, args)

#if defined(BOOST_NO_CXX11_VARIADIC_MACROS) || defined(BOOST_NO_VARIADIC_MACROS)

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

