#ifndef MPLLIBS_METAPARSE_V1_SOURCE_POSITION_TAG_HPP
#define MPLLIBS_METAPARSE_V1_SOURCE_POSITION_TAG_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v1/fwd/source_position.hpp>
#include <mpllibs/metaparse/v1/fwd/get_prev_char.hpp>
#include <mpllibs/metaparse/v1/fwd/next_line.hpp>
#include <mpllibs/metaparse/v1/fwd/next_char.hpp>
#include <mpllibs/metaparse/v1/get_col.hpp>
#include <mpllibs/metaparse/v1/get_line.hpp>

#include <mpllibs/metamonad/tmp_tag.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/plus.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v1
    {
      struct source_position_tag : metamonad::tmp_tag<source_position_tag> {};
      
      template <>
      struct get_col_impl<source_position_tag>
      {
        template <class P>
        struct apply : P::col {};
      };

      template <>
      struct get_line_impl<source_position_tag>
      {
        template <class P>
        struct apply : P::line {};
      };

      
      template <>
      struct get_prev_char_impl<source_position_tag>
      {
        template <class P>
        struct apply : P::prev_char {};
      };
      
      
      template <>
      struct next_char_impl<source_position_tag>
      {
        template <class P, class Ch>
        struct apply :
          source_position<
            typename get_line<P>::type,
            typename boost::mpl::plus<
              typename get_col<P>::type,
              boost::mpl::int_<1>
            >::type,
            Ch
          >
        {};
      };

      template <>
      struct next_line_impl<source_position_tag>
      {
        template <class P, class Ch>
        struct apply :
          source_position<
            typename boost::mpl::plus<
              typename get_line<P>::type,
              boost::mpl::int_<1>
            >::type,
            boost::mpl::int_<1>,
            Ch
          >
        {};
      };
    }
  }
}

#endif

