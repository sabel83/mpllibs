#ifndef MPLLIBS_SAFE_PRINTF_IMPL_GRAMMAR_HPP
#define MPLLIBS_SAFE_PRINTF_IMPL_GRAMMAR_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/safe_printf/v1/impl/any_type.hpp>
#include <mpllibs/safe_printf/v1/impl/expected_arg.hpp>
#include <mpllibs/safe_printf/v1/error.hpp>

#include <boost/metaparse/always.hpp>
#include <boost/metaparse/always_c.hpp>
#include <boost/metaparse/repeated.hpp>
#include <boost/metaparse/repeated_reject_incomplete.hpp>
#include <boost/metaparse/repeated_one_of.hpp>
#include <boost/metaparse/repeated1.hpp>
#include <boost/metaparse/digit.hpp>
#include <boost/metaparse/except.hpp>
#include <boost/metaparse/first_of.hpp>
#include <boost/metaparse/last_of.hpp>
#include <boost/metaparse/lit_c.hpp>
#include <boost/metaparse/one_char.hpp>
#include <boost/metaparse/one_of.hpp>
#include <boost/metaparse/one_of_c.hpp>
#include <boost/metaparse/transform.hpp>
#include <boost/metaparse/return_.hpp>
#include <boost/metaparse/sequence.hpp>

#include <mpllibs/metamonad/box.hpp>
#include <mpllibs/metamonad/instantiate.hpp>

#include <string>

namespace mpllibs
{
  namespace safe_printf
  {
    namespace v1
    {
      namespace impl
      {
        namespace grammar
        {
          using boost::metaparse::repeated;
          using boost::metaparse::repeated1;
          using boost::metaparse::repeated_reject_incomplete;
          using boost::metaparse::repeated_one_of;
          using boost::metaparse::always;
          using boost::metaparse::always_c;
          using boost::metaparse::digit;
          using boost::metaparse::except;
          using boost::metaparse::first_of;
          using boost::metaparse::last_of;
          using boost::metaparse::lit_c;
          using boost::metaparse::one_char;
          using boost::metaparse::one_of;
          using boost::metaparse::one_of_c;
          using boost::metaparse::return_;
          using boost::metaparse::sequence;
          using boost::metaparse::transform;

          using mpllibs::metamonad::box;
          using mpllibs::metamonad::instantiate3;

          using boost::mpl::true_;
          using boost::mpl::false_;

          typedef
            repeated_one_of<
              last_of<lit_c<'%'>, lit_c<'%'> >,
              last_of<
                except<
                  lit_c<'%'>,
                  boost::mpl::void_,
                  error::no_percentage_char_expected
                >,
                one_char
              >
            >
            normal_chars;

          typedef one_of_c<'-', '+', ' ', '#', '0'> flag;

          typedef repeated1<digit> integer;
        
          // Returns true_ or false_
          typedef
            one_of<
              always<integer, false_>,
              always_c<'*', true_>,
              return_<false_>
            >
            width;

          // Returns true_ or false_
          typedef one_of<last_of<lit_c<'.'>, width>, return_<false_> > precision;

          typedef
            one_of<
              always_c<'c', box<char> >,
              always<one_of_c<'d', 'i'>, box<int> >,
              always<one_of_c<'e', 'E', 'f', 'g', 'G'>, box<double> >,
              always_c<'o', box<int> >,
              always_c<'s', box<char*> >,
              always<one_of_c<'u', 'x', 'X'>, box<unsigned int> >,
              always_c<'p', box<any_type*> >,
              always_c<'n', box<int*> >
            >
            format_no_flag;

          typedef
            one_of<
              always<one_of_c<'d', 'i', 'o'>, box<short int> >,
              always<one_of_c<'u', 'x', 'X'>, box<short unsigned int> >
            >
            format_h_flag;

          typedef
            one_of<
              always_c<'c', box<wchar_t> >,
              always<one_of_c<'d', 'i', 'o'>, box<long int> >,
              always_c<'s', box<wchar_t*> >,
              always<one_of_c<'u', 'x', 'X'>, box<long unsigned int> >
            >
            format_l_flag;

          typedef
            always<one_of_c<'e', 'E', 'f', 'g', 'G'>, box<long double> >
            format_capital_l_flag;

          typedef
            one_of<
              last_of<lit_c<'h'>, format_h_flag>,
              last_of<lit_c<'l'>, format_l_flag>,
              last_of<lit_c<'L'>, format_capital_l_flag>,
              format_no_flag
            >
            format;

          // returns deque<defined extra int, defined extra int, format>
          typedef
            last_of<
              lit_c<'%'>,
              repeated<flag>,
              transform<
                sequence<width, precision, format>,
                instantiate3<expected_arg>
              >
            >
            parameter;

          typedef
            last_of<
              normal_chars,
              repeated_reject_incomplete<first_of<parameter, normal_chars> >
            >
            S;
        }
      }
    }
  }
}

#endif

