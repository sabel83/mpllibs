#ifndef MPLLIBS_METAPARSE_V2_IMPL_NTH_OF_C_IMPL_HPP
#define MPLLIBS_METAPARSE_V2_IMPL_NTH_OF_C_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/impl/skip_seq.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/fold.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace impl
      {
        template <int N, class Seq>
        struct nth_of_c_impl
        {
        private:
          template <class NextResult>
          struct apply_unchecked :
            boost::mpl::apply_wrap2<
              nth_of_c_impl<
                N - 1,
                typename boost::mpl::pop_front<Seq>::type
              >,
              typename get_remaining<NextResult>::type,
              typename get_position<NextResult>::type
            >
          {};
        public:
          typedef nth_of_c_impl type;
          
          template <class S, class Pos>
          struct apply :
            boost::mpl::eval_if<
              typename is_error<
                boost::mpl::apply<typename boost::mpl::front<Seq>::type, S, Pos>
              >::type,
              boost::mpl::apply<typename boost::mpl::front<Seq>::type, S, Pos>,
              apply_unchecked<
                boost::mpl::apply<typename boost::mpl::front<Seq>::type, S, Pos>
              >
            >
          {};
        };
        
        template <class Seq>
        struct nth_of_c_impl<0, Seq>
        {
          typedef nth_of_c_impl type;
          
          template <class S, class Pos>
          struct apply :
            boost::mpl::fold<
              typename boost::mpl::pop_front<Seq>::type,
              typename boost::mpl::apply<
                typename boost::mpl::front<Seq>::type,
                S,
                Pos
              >::type,
              skip_seq
            >
          {};
        };
      }
    }
  }
}

#endif

