// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/printf.hpp>
#include <mpllibs/metaparse/string.hpp>

namespace safe = mpllibs::safe_printf;

int main()
{
  using safe::printf;
  using safe::sprintf;
  using safe::fprintf;
  
  printf<MPLLIBS_STRING("John %d, %s %d\n")>(11, "Joe", 13);

  char s[128];
  sprintf<MPLLIBS_STRING("%d / %d = %.2f")>(s, 13, 2, 6.5);
  
  fprintf<MPLLIBS_STRING("Using sprintf: %s\n")>(stderr, s);
}

