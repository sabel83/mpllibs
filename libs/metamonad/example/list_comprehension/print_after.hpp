#ifndef MPLLIBS_METAMONAD_EXAMPLE_PRINT_AFTER_HPP
#define MPLLIBS_METAMONAD_EXAMPLE_PRINT_AFTER_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_value.hpp>

#include <boost/mpl/pair.hpp>

#include <iostream>

struct print_after : mpllibs::metamonad::tmp_value<print_after>
{
  template <class Acc, class V>
  struct apply : mpllibs::metamonad::tmp_value<apply<Acc, V> >
  {
    static bool run()
    {
      const bool first_element = Acc::type::run();
      std::cout
        << (first_element ? "" : ", ") << "("
        << boost::mpl::first<V>::type::value << ", "
        << boost::mpl::second<V>::type::value
        << ")";
      return false;
    }
  };
};

#endif

