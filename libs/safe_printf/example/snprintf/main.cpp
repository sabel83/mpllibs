// Copyright Abel Sinkovics (abel@sinkovics.hu)  2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/snprintf.hpp>
#include <mpllibs/metaparse/string.hpp>

namespace safe = mpllibs::safe_printf;

#ifdef BOOST_NO_CONSTEXPR

int main()
{
  using mpllibs::metaparse::string;
  
  char s[128];
  safe::snprintf<
    string<'%','d',' ','/',' ','%','d',' ','=',' ','%','.','2','f'>
  >(s, sizeof(s), 13, 2, 6.5);
}

#else

int main()
{
  char s[128];
  safe::snprintf<MPLLIBS_STRING("%d / %d = %.2f")>(s, sizeof(s), 13, 2, 6.5);
}

#endif

