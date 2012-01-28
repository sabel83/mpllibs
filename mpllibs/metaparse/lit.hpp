#ifndef MPLLIBS_METAPARSE_LIT_HPP
#define MPLLIBS_METAPARSE_LIT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/accept_when.hpp>
#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/error.hpp>

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/lambda.hpp>

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
        typedef mpllibs::metaparse::error_tag tag;

        struct to_stream
        {
          static std::ostream& run(std::ostream& o)
          {
            return o << "'" << C::type::value << "' literal expected.";
          }
        };
      };
    }
  
    template <class C>
    struct lit :
      accept_when<
        one_char,
        boost::mpl::equal_to<boost::mpl::_1, C>,
        mpllibs::metaparse::errors::literal_expected<C>
      >
    {
      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "lit<";
          mpllibs::metatest::to_stream_argument_list<C>::run(o);
          return o << ">";
        }
      };
    };
  }
}

#endif


