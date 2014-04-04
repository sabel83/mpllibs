#ifndef MPLLIBS_METAPARSE_V1_SOURCE_POSITION_HPP
#define MPLLIBS_METAPARSE_V1_SOURCE_POSITION_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/fwd/source_position.hpp>
#include <mpllibs/metaparse/v1/source_position_tag.hpp>

#include <mpllibs/boost.hpp>

#include <boost/mpl/bool.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      template <class Line, class Col, class PrevChar>
      struct source_position
      {
        typedef source_position_tag tag;
        typedef source_position type;
        
        typedef Line line;
        typedef Col col;
        typedef PrevChar prev_char;
      };
    }
  }
}

namespace MPLLIBS_BOOST_NAMESPACE
{
  namespace mpl
  {
    template <class TagA, class TagB>
    struct equal_to_impl;

    template <>
    struct equal_to_impl<
      mpllibs::metaparse::v1::source_position_tag,
      mpllibs::metaparse::v1::source_position_tag
    >
    {
      typedef equal_to_impl type;

      template <class A, class B>
      struct apply :
        bool_<
          A::type::line::value == B::type::line::value
          && A::type::col::value == B::type::col::value
        >
      {};
    };

    template <class TagA, class TagB>
    struct not_equal_to_impl;

    template <>
    struct not_equal_to_impl<
      mpllibs::metaparse::v1::source_position_tag,
      mpllibs::metaparse::v1::source_position_tag
    >
    {
      typedef not_equal_to_impl type;

      template <class A, class B>
      struct apply : bool_<!equal_to<A, B>::type::value> {};
    };
  }
}

#endif

