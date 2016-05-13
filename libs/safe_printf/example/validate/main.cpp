// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/valid_arguments.hpp>

#include <mpllibs/metamonad/box.hpp>

#include <boost/metaparse/string.hpp>

#include <boost/mpl/vector.hpp>

#include <iostream>

namespace safe = mpllibs::safe_printf;

template <class S, class ArgTypes>
void validate_and_show()
{
  std::cout
    << boost::mpl::c_str<S>::type::value << ": "
    << mpllibs::safe_printf::valid_arguments<S, ArgTypes>::type::value
    << std::endl;
}

#ifdef BOOST_NO_CONSTEXPR

int main()
{
  using mpllibs::metamonad::box;
  using boost::metaparse::string;
  using boost::mpl::vector;
  
  validate_and_show<
    string<'J','o','h','n',' ','%','d',',',' ','%','s',' ','%','d'>,
    vector<box<int>, box<const char*>, box<int> >
  >();

  validate_and_show<
    string<'J','o','h','n',' ','%','d',',',' ','%','s',' ','%','d'>,
    vector<box<int>, box<double>, box<int> >
  >();
}

#else

int main()
{
  using boost::mpl::vector;
  using mpllibs::metamonad::box;

  validate_and_show<
    BOOST_METAPARSE_STRING("John %d, %s %d"),
    vector<box<int>, box<const char*>, box<int>>
  >();

  validate_and_show<
    BOOST_METAPARSE_STRING("John %d, %s %d"),
    vector<box<int>, box<double>, box<int>>
  >();
}

#endif

