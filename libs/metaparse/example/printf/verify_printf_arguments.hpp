#ifndef SAFE_PRINTF_VERIFY_PRINTF_ARGUMENTS_HPP
#define SAFE_PRINTF_VERIFY_PRINTF_ARGUMENTS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "verify_printf_arguments_impl.hpp"
#include "printf_grammar.hpp"

#include <mpllibs/metaparse/build_parser.hpp>

#include <boost/mpl/apply_wrap.hpp>

namespace safe
{
  template <class F, class ArgTypes>
  struct verify_printf_arguments :
    verify_printf_arguments_impl<
      boost::mpl::apply_wrap1<
        mpllibs::metaparse::build_parser<safe::grammar::S>,
        F
      >,
      ArgTypes
    >
  {};
}

#endif

