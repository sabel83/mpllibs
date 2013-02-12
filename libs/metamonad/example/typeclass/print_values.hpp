#ifndef MPLLIBS_METAMONAD_EXAMPLE_PRINT_VALUES_HPP
#define MPLLIBS_METAMONAD_EXAMPLE_PRINT_VALUES_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "print_after.hpp"
#include "print_empty.hpp"

#include <boost/mpl/fold.hpp>

#include <iostream>

template <class L>
void print_values()
{
  std::cout << "[";
  boost::mpl::fold<typename L::type, print_empty, print_after>::type::run();
  std::cout << "]";
}

#endif

