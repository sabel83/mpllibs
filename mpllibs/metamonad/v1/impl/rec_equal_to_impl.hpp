#ifndef MPLLIBS_METAMONAD_V1_IMPL_REC_EQUAL_TO_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_REC_EQUAL_TO_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/impl/data_args.hpp>
#include <mpllibs/metamonad/limit_data_size.hpp>

#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

#include <boost/mpl/bool.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/equal_to.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class A, class B>
        struct rec_equal_to_impl : boost::mpl::false_ {};

        #ifdef REC_EQUAL_TO_CASE
        #  error REC_EQUAL_TO_CASE already defined
        #endif
        #define REC_EQUAL_TO_CASE(z, n, unused) \
          template < \
            MPLLIBS_V1_DATA_ARGS(n) class T, \
            BOOST_PP_ENUM_PARAMS(n, class A), \
            BOOST_PP_ENUM_PARAMS(n, class B) \
          > \
          struct \
            rec_equal_to_impl< \
              T<BOOST_PP_ENUM_PARAMS(n, A)>, \
              T<BOOST_PP_ENUM_PARAMS(n, B)> \
            > : \
            boost::mpl::equal< \
              boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, A)>, \
              boost::mpl::vector<BOOST_PP_ENUM_PARAMS(n, B)>, \
              boost::mpl::equal_to<boost::mpl::_1, boost::mpl::_2> \
            > \
          {};
        
        BOOST_PP_REPEAT_FROM_TO(1, MPLLIBS_LIMIT_DATA_SIZE, REC_EQUAL_TO_CASE,~)
        
        #undef REC_EQUAL_TO_CASE
      }
    }
  }
}

#endif

