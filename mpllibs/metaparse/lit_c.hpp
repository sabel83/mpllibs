#ifndef MPLLIBS_METAPARSE_LIT_C_HPP
#define MPLLIBS_METAPARSE_LIT_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/lit.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/integral_c.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    template <char C>
    struct lit_c : lit<boost::mpl::integral_c<char, C> > {};
  }
}

namespace mpllibs
{
  namespace metatest
  {
    template <char C>
    struct to_stream<mpllibs::metaparse::lit_c<C> >
    {
      typedef to_stream type;
      
      static std::ostream& run(std::ostream& o_)
      {
        return o_ << "lit_c<" << C << ">";
      }
    };
  }
}

#endif


