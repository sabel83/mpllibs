#ifndef MPLLIBS_METAPARSE_FAIL_HPP
#define MPLLIBS_METAPARSE_FAIL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metatest/to_stream_argument_list.hpp>

#include <mpllibs/metamonad/tag_tag.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    MPLLIBS_DEFINE_TAG(fail_tag)

    template <class Msg>
    struct fail
    {
      typedef fail type;
      
      template <class S, class Pos>
      struct apply
      {
        typedef fail_tag tag;
        typedef apply type;

        typedef Pos source_position;
        typedef Msg message;
      };

      struct to_stream
      {
        static std::ostream& run(std::ostream& o)
        {
          o << "fail<";
          mpllibs::metatest::to_stream_argument_list<Msg>::run(o);
          return o << ">";
        }
      };
    };
  }

  namespace metatest
  {
    template <>
    struct to_stream_impl<mpllibs::metaparse::fail_tag>
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

