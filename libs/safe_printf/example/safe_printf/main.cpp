// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/printf.hpp>
#include <mpllibs/safe_printf/sprintf.hpp>
#include <mpllibs/safe_printf/fprintf.hpp>
#include <mpllibs/metaparse/string.hpp>

namespace safe = mpllibs::safe_printf;

#ifdef BOOST_NO_CONSTEXPR

int main()
{
  using mpllibs::metaparse::string;
  
  safe::printf<
    string<'J','o','h','n',' ','%','d',',',' ','%','s',' ','%','d','\n'>
  >(11, "Joe", 13);

  char s[128];
  safe::sprintf<
    string<'%','d',' ','/',' ','%','d',' ','=',' ','%','.','2','f'>
  >(s, 13, 2, 6.5);
  
  safe::fprintf<
    string<
      'U','s','i','n','g',' ','s','p','r','i','n','t','f',':',' ','%','s','\n'
    >
  >(stderr, s);
}

#else

int main()
{
  safe::printf<MPLLIBS_STRING("John %d, %s %d\n")>(11, "Joe", 13);

  char s[128];
  safe::sprintf<MPLLIBS_STRING("%d / %d = %.2f")>(s, 13, 2, 6.5);
  
  safe::fprintf<MPLLIBS_STRING("Using sprintf: %s\n")>(stderr, s);
}

#endif

