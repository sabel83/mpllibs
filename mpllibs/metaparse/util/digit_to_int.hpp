#ifndef MPLLIBS_METAPARSE_UTIL_DIGIT_TO_INT_HPP
#define MPLLIBS_METAPARSE_UTIL_DIGIT_TO_INT_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/error.hpp>

#include <mpllibs/metamonad/throw.hpp>
#include <mpllibs/metamonad/meta_atom.hpp>

#include <boost/mpl/int.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace errors
    {
      MPLLIBS_DEFINE_META_ATOM(mpllibs::metaparse::error_tag, invalid_digit)
    }
    
    namespace util
    {
      namespace impl
      {
        template <char C>
        struct digit_to_int :
          MPLLIBS_THROW<mpllibs::metaparse::errors::invalid_digit>
        {};
      }

      struct digit_to_int
      {
        typedef digit_to_int type;
        
        template <class D>
        struct apply :
          mpllibs::metaparse::util::impl::digit_to_int<D::type::value>
        {};
        
        struct to_stream
        {
          static std::ostream& run(std::ostream& o)
          {
            return o << "digit_to_int";
          }
        };
      };
    
      namespace impl
      {
        #ifdef MPLLIBS_UTIL_DIGIT_TO_INT_IMPL
          #error MPLLIBS_UTIL_DIGIT_TO_INT_IMPL is defined
        #endif
        #define MPLLIBS_UTIL_DIGIT_TO_INT_IMPL(c, n) \
          template <> struct digit_to_int<c> \
          { \
            typedef boost::mpl::int_<n> type; \
          }
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('0', 0);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('1', 1);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('2', 2);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('3', 3);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('4', 4);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('5', 5);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('6', 6);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('7', 7);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('8', 8);
        MPLLIBS_UTIL_DIGIT_TO_INT_IMPL('9', 9);
        #undef MPLLIBS_UTIL_DIGIT_TO_INT_IMPL
      }
    }
  }
}

#endif

