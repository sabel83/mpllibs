#ifndef MPLLIBS_PARSER_FAIL_H
#define MPLLIBS_PARSER_FAIL_H

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
    
    template <class msg>
    struct fail
    {
      template <class s, class pos>
      struct apply
      {
        typedef mpllibs::metaparse::error_tag tag;
        typedef apply type;

        typedef pos source_position;
        typedef msg message;
      };
    };
  }

  namespace metatest
  {
    template <class t>
    struct to_stream_impl;
    
    template <class t>
    struct to_stream;
    
    template <>
    struct to_stream_impl<mpllibs::metaparse::error_tag>
    {
      template <class e>
      struct apply
      {
        typedef apply type;
      
        static std::ostream& run(std::ostream& o_)
        {
          using mpllibs::metatest::to_stream;
        
          o_ << "Error at ";
          to_stream<typename e::source_position::type>::run(o_);
          o_ << ": ";
          to_stream<typename e::message::type>::run(o_);
          return o_;
        }
      };
    };
  }
}

#endif

