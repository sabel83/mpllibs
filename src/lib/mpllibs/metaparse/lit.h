#ifndef MPLLIBS_PARSER_LIT_H
#define MPLLIBS_PARSER_LIT_H

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/accept_when.h>
#include <mpllibs/metaparse/one_char.h>

#include <mpllibs/metaparse/util/is_char.h>

#include <mpllibs/metatest/to_stream.h>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      template <class c>
      struct literal_expected
      {
        typedef literal_expected type;
      };
    }
  
    template <class c>
    struct lit :
      mpllibs::metaparse::accept_when<
        mpllibs::metaparse::one_char,
        mpllibs::metaparse::util::is_char<c>,
        mpllibs::metaparse::errors::literal_expected<c>
      >
    {};
  }
  
  namespace metatest
  {
    template <class c>
    struct to_stream<mpllibs::metaparse::errors::literal_expected<c> >
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "'" << c::type::value << "' literal expected.";
      }
    };
  }
}

#endif


