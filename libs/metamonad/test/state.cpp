// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/state.hpp>

#include <mpllibs/metatest/test.hpp>
#include <mpllibs/metatest/to_stream.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/quote.hpp>

#include "common.hpp"

using mpllibs::metatest::suite_path;

using mpllibs::metamonad::state_tag;
using mpllibs::metamonad::monad;

using boost::mpl::equal_to;
using boost::mpl::apply;
using boost::mpl::plus;
using boost::mpl::int_;
using boost::mpl::quote1;

namespace
{
  const suite_path suite("state");
  
  typedef int_<24> int24;
  typedef int_<14> int14;
  typedef apply<monad<state_tag>::return_, int11>::type return11;
  
  template <class N>
  struct plusn
  {
    typedef plusn type;

    template <class A>
    struct apply
    {
    private:
      struct impl
      {
        typedef impl type;
  
        struct to_stream
        {
          static std::ostream& run(std::ostream& o_)
          {
            mpllibs::metatest::to_stream<plusn<N> >::run(o_);
            o_ << "::apply<";
            mpllibs::metatest::to_stream<A>::run(o_);
            return o_ << ">";
          }
        };
  
        template <class S>
        struct apply :
          boost::mpl::pair<typename plus<A, N>::type, typename plus<S, N>::type>
        {};
      };
    public:
      typedef impl type;
    };

    struct to_stream
    {
      static std::ostream& run(std::ostream& o_)
      {
        o_ << "plusn<";
        mpllibs::metatest::to_stream<N>::run(o_);
        return o_ << ">";
      }
    };
  };

  typedef
    equal_to<int11, apply<return11, int13>::type::first>
    test_return_value;
  
  typedef
    equal_to<int13, apply<return11, int13>::type::second>
    test_return_state;

  typedef
    equal_to<
      int24,
      apply<
        apply<monad<state_tag>::bind, return11, plusn<int13> >::type,
        int1
      >::type::first
    >
    test_bind_value;

  typedef
    equal_to<
      int14,
      apply<
        apply<monad<state_tag>::bind, return11, plusn<int13> >::type,
        int1
      >::type::second
    >
    test_bind_state;
}

MPLLIBS_ADD_TEST(suite, test_return_value)
MPLLIBS_ADD_TEST(suite, test_return_state)
MPLLIBS_ADD_TEST(suite, test_bind_state)
MPLLIBS_ADD_TEST(suite, test_bind_value)




