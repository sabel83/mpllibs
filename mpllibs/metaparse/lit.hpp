#ifndef MPLLIBS_METAPARSE_LIT_HPP
#define MPLLIBS_METAPARSE_LIT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/accept_when.hpp>
#include <mpllibs/metaparse/one_char.hpp>

#include <mpllibs/metaparse/util/is_char.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      template <class C>
      struct literal_expected
      {
        typedef literal_expected type;
      };
    }
  
    template <class C>
    struct lit :
      accept_when<
        one_char,
        mpllibs::metaparse::util::is_char<C>,
        mpllibs::metaparse::errors::literal_expected<C>
      >
    {};
  }
  
  namespace metatest
  {
    template <class C>
    struct to_stream<mpllibs::metaparse::errors::literal_expected<C> >
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "'" << C::type::value << "' literal expected.";
      }
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(1, mpllibs::metaparse::lit, "lit");

#endif


