// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_MPL_LIMIT_STRING_SIZE 50
#define MPLLIBS_STRING_MAX_LENGTH BOOST_MPL_LIMIT_STRING_SIZE

#include <meta_hs.hpp>

#include <mpllibs/metaparse/string.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/times.hpp>

#include <boost/config.hpp>

#include <iostream>

using boost::mpl::int_;
using boost::mpl::times;

#ifdef BOOST_NO_CONSTEXPR

int main()
{
  std::cout << "Please use a compiler that supports constexpr" << std::endl;
}

#else

#ifdef _S
  #error _S already defined
#endif
#define _S MPLLIBS_STRING

template <class N>
struct double_number : times<typename N::type, int_<2> > {};

typedef
  meta_hs
    ::import1<_S("f"), double_number>::type
    ::import<_S("val"), int_<11> >::type

    ::define<_S("fib n = if n<2 then 1 else fib(n-2) + fib(n-1)")>::type
    ::define<_S("fact n = if n<1 then 1 else n * fact(n-1)")>::type
    ::define<_S("times4 n = f (f n)")>::type
    ::define<_S("times11 n = n * val")>::type
  metafunctions;

typedef metafunctions::get<_S("fib")> fib;
typedef metafunctions::get<_S("fact")> fact;
typedef metafunctions::get<_S("times4")> times4;
typedef metafunctions::get<_S("times11")> times11;

int main()
{
  std::cout
    << "fib 6 = " << fib::apply<int_<6> >::type::value << std::endl
    << "fact 4 = " << fact::apply<int_<4> >::type::value << std::endl
    << "times4 3 = " << times4::apply<int_<3> >::type::value << std::endl
    << "times11 2 = " << times11::apply<int_<2> >::type::value << std::endl;
}

#endif

