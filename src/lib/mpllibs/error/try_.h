#ifndef MPLLIBS_ERROR_TRY_H
#define MPLLIBS_ERROR_TRY_H

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/do_.h>
#include <mpllibs/error/let.h>
#include <mpllibs/error/exception.h>
#include <mpllibs/error/get_data.h>

#include <boost/mpl/tag.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/or.hpp>

#include <boost/type_traits/is_same.hpp>

namespace mpllibs
{
  namespace error
  {
    #ifdef TRY
      #error TRY already defined
    #endif
    #define TRY mpllibs::error::try_

    struct catch_any
    {
      typedef catch_any type;
    };

    namespace impl
    {
      // evaluates result lazily
      template <class Result>
      struct skip_further_catches : Result
      {
        template <class ExceptionTag, class Name, class Body>
        struct catch_ : skip_further_catches {};
      };
      
      template <class Exception>
      struct was_exception
      {
      private:
        typedef mpllibs::error::get_data<Exception> _exception_data;
        
      public:
        typedef Exception type;
        
        template <class ExceptionTag, class Name, class Body>
        struct catch_ :
          boost::mpl::if_<
            boost::mpl::or_<
              boost::is_same<
                ExceptionTag,
                typename boost::mpl::tag<typename _exception_data::type>::type
              >,
              boost::is_same<ExceptionTag, mpllibs::error::catch_any>
            >,
            mpllibs::error::impl::skip_further_catches<
              typename mpllibs::error::let<
                Name, typename _exception_data::type,
                Body
              >::type
            >,
            mpllibs::error::impl::was_exception<Exception>
          >::type
        {};
      };
    }

    template <
      BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
        DO_MAX_ARGUMENT,
        class E,
        unused_do_argument
      )
    >
    struct try_ :
      boost::mpl::if_<
        typename boost::is_same<
          exception_tag,
          typename boost::mpl::tag<
            typename
              DO<exception_monad>::template apply<
                BOOST_PP_ENUM_PARAMS(DO_MAX_ARGUMENT, E)
              >::type
          >::type
        >::type,
        mpllibs::error::impl::was_exception<
          typename
            DO<exception_monad>::template apply<
              BOOST_PP_ENUM_PARAMS(DO_MAX_ARGUMENT, E)
            >::type
        >,
        mpllibs::error::impl::skip_further_catches<
          // NoException evaluates to the wrapped value
          typename
            DO<exception_monad>::template apply<
              BOOST_PP_ENUM_PARAMS(DO_MAX_ARGUMENT, E)
            >::type
        >
      >::type
    {};
  }
}

#endif

