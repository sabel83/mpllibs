#ifndef MPLLIBS_METAPARSE_FAIL_HPP
#define MPLLIBS_METAPARSE_FAIL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    struct error_tag
    {
      typedef error_tag type;
    };
    
    template <class Msg>
    struct fail
    {
      template <class S, class Pos>
      struct apply
      {
        typedef error_tag tag;
        typedef apply type;

        typedef Pos source_position;
        typedef Msg message;
      };
    };
  }

  namespace metatest
  {
    template <class T>
    struct to_stream_impl;
    
    template <class T>
    struct to_stream;
    
    template <>
    struct to_stream_impl<mpllibs::metaparse::error_tag>
    {
      template <class E>
      struct apply
      {
        typedef apply type;
      
        static std::ostream& run(std::ostream& o_)
        {
          o_ << "Error at ";
          to_stream<typename E::source_position::type>::run(o_);
          o_ << ": ";
          to_stream<typename E::message::type>::run(o_);
          return o_;
        }
      };
    };
  }
}

#endif

