// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/verify_printf_arguments.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <boost/mpl/list.hpp>

#include <iostream>

namespace safe = mpllibs::safe_printf;

template <class S, class ArgTypes>
void validate_and_show()
{
  std::cout
    << boost::mpl::c_str<S>::type::value << ": "
    << mpllibs::safe_printf::verify_printf_arguments<S, ArgTypes>::type::value
    << std::endl;
}

#ifdef BOOST_NO_CONSTEXPR

int main()
{
  using mpllibs::metaparse::string;
  using boost::mpl::list;
  
  validate_and_show<
    string<'J','o','h','n',' ','%','d',',',' ','%','s',' ','%','d'>,
    list<int, const char*, int>
  >();

  validate_and_show<
    string<'J','o','h','n',' ','%','d',',',' ','%','s',' ','%','d'>,
    list<int, double, int>
  >();
}

#else

int main()
{
  validate_and_show<
    MPLLIBS_STRING("John %d, %s %d")>,
    list<int, const char*, int>
  >();

  validate_and_show<
    MPLLIBS_STRING("John %d, %s %d")>,
    list<int, double, int>
  >();
}

#endif

