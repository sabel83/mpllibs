// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/printf.hpp>

namespace safe = mpllibs::safe_printf;

int main()
{
  using safe::printf;
  using safe::sprintf;
  using safe::fprintf;
/*
  // This version assumes solutions based on the new standard
  
  printf<_S("John %d, %s %d\n")>(11, "Joe", 13);

  char s[128];
  sprintf<_S("%d / %d = %.2f")>(s, 13, 2, 6.5);
  
  fprintf<_S("Using sprintf: %s\n")>(stderr, s);
*/
  
  using boost::mpl::string;
  
  printf<string<'John',' %d,',' %s ','%d\n'> >(11, "Joe", 13);

  char s[128];
  sprintf<string<'%d /',' %d ','= %.','2f'> >(s, 13, 2, 6.5);
  
  fprintf<string<'Usin','g sp','rint','f: %','s\n'> >(stderr, s);
}

