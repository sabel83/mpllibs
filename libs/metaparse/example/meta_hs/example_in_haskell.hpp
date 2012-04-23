#ifndef EXAMPLE_IN_HASKELL_HPP
#define EXAMPLE_IN_HASKELL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/config.hpp>

#ifdef BOOST_NO_CONSTEXPR

// We have to fall back on the handcrafted one
#include <example_handcrafted.hpp>

#else

#define BOOST_MPL_LIMIT_STRING_SIZE 50
#define MPLLIBS_STRING_MAX_LENGTH BOOST_MPL_LIMIT_STRING_SIZE

#include <meta_hs.hpp>
#include <double_number.hpp>

#include <mpllibs/metaparse/string.hpp>

#include <boost/mpl/int.hpp>

#ifdef _S
  #error _S already defined
#endif
#define _S MPLLIBS_STRING

typedef
  meta_hs
    ::import1<_S("f"), double_number>::type
    ::import<_S("val"), boost::mpl::int_<11> >::type

    ::define<_S("fib n = if n<2 then 1 else fib(n-2) + fib(n-1)")>::type
    ::define<_S("fact n = if n<1 then 1 else n * fact(n-1)")>::type
    ::define<_S("times4 n = f (f n)")>::type
    ::define<_S("times11 n = n * val")>::type
  metafunctions;

typedef metafunctions::get<_S("fib")> fib;
typedef metafunctions::get<_S("fact")> fact;
typedef metafunctions::get<_S("times4")> times4;
typedef metafunctions::get<_S("times11")> times11;

#endif

#endif


