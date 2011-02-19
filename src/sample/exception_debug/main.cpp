// Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/error/try_.h>
#include <mpllibs/error/throw.h>
#include <mpllibs/error/Exception.h>
#include <mpllibs/error/debug.h>

#include <mpllibs/metatest/to_stream.h>

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/divides.hpp>

struct division_by_zero;
DEFINE_TO_STREAM_FOR_TYPE(division_by_zero, "division by zero")

template <class a, class b>
struct safe_divides :
  TRY<
    boost::mpl::eval_if<
      typename boost::mpl::equal_to<b, boost::mpl::int_<0> >::type,
      THROW<division_by_zero>,
      RETURN<boost::mpl::divides<a, b> >
    >
  >
{};

typedef boost::mpl::int_<0> int0;
typedef boost::mpl::int_<13> int13;

mpllibs::metatest::debug<safe_divides<int13, int0> > d;

int main()
{
  // some other code
}


