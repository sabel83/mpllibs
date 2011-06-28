#ifndef MPLLIBS_SAFE_PRINTF_VERIFY_PRINTF_ARGUMENTS_HPP
#define MPLLIBS_SAFE_PRINTF_VERIFY_PRINTF_ARGUMENTS_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/printf_parser.hpp>
#include <mpllibs/safe_printf/verify_printf_arguments_impl.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/apply_wrap.hpp>

namespace mpllibs
{
  namespace safe_printf
  {
    template <class F, class ArgTypes>
    struct verify_printf_arguments :
      verify_printf_arguments_impl<
        boost::mpl::apply_wrap1<printf_parser, F>,
        ArgTypes
      >
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "verify_printf_arguments<";
          mpllibs::metatest::to_stream_argument_list<F, ArgTypes>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif

