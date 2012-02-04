// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_MPL_LIMIT_STRING_SIZE 64
#define BOOST_TEST_DYN_LINK

#include <mpllibs/metaparse/grammar.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include <mpllibs/metatest/boost_test.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/char.hpp>

using boost::mpl::char_;

namespace
{
  struct next_char
  {
    typedef next_char type;

    template <class C>
    struct apply
    {
      typedef char_<C::type::value + 1> type;
    };
  };
}

BOOST_AUTO_TEST_CASE(test_grammar)
{
  using mpllibs::metatest::has_type;
  using mpllibs::metatest::meta_require;

  using mpllibs::metaparse::grammar;
  using mpllibs::metaparse::lit_c;
  using mpllibs::metaparse::get_result;
  using mpllibs::metaparse::start;
  using mpllibs::metaparse::is_error;

  using boost::mpl::string;
  using boost::mpl::apply_wrap2;
  using boost::mpl::equal_to;
  using boost::mpl::equal;
  using boost::mpl::vector;

  meta_require<
    has_type<grammar<> >
  >(MPLLIBS_HERE, "grammar_has_type");

  meta_require<
    equal_to<
      char_<'x'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::import<string<'S'>, lit_c<'x'> >::type,
          string<'x'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "import");

  meta_require<
    equal_to<
      char_<'x'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::import<string<'I'>, lit_c<'x'> >::type
            ::rule<string<'S',' ',':',':','=',' ','I'> >::type,
          string<'x'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "rename_import");

  meta_require<
    equal_to<
      char_<'x'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'S',' ',':',':','=',' ','\'','x','\''> >::type,
          string<'x'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "char");

  meta_require<
    is_error<
      apply_wrap2<
        grammar<>
          ::rule<string<'S',' ',':',':','=',' ','\'','x','\''> >::type,
        string<'y'>,
        start
      >
    >
  >(MPLLIBS_HERE, "char_failure");

  meta_require<
    equal_to<
      char_<'\n'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'S',' ',':',':','=',' ','\'','\\','n','\''> >::type,
          string<'\n'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "char_n");

  meta_require<
    equal_to<
      char_<'\r'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'S',' ',':',':','=',' ','\'','\\','r','\''> >::type,
          string<'\r'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "char_r");

  meta_require<
    equal_to<
      char_<'\t'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'S',' ',':',':','=',' ','\'','\\','t','\''> >::type,
          string<'\t'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "char_t");

  meta_require<
    equal_to<
      char_<'\\'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'S',' ',':',':','=',' ','\'','\\','\\','\''> >::type,
          string<'\\'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "char_\\");

  meta_require<
    equal_to<
      char_<'\''>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'S',' ',':',':','=',' ','\'','\\','\'','\''> >::type,
          string<'\''>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "char_\'");

  meta_require<
    equal_to<
      char_<'x'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'R',' ',':',':','=',' ','\'','x','\''> >::type
            ::rule<string<'S',' ',':',':','=',' ','R'> >::type,
          string<'x'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "rename_rule");

  meta_require<
    equal<
      vector<char_<'x'>, char_<'x'> >,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'R',' ',':',':','=',' ','\'','x','\''> >::type
            ::rule<string<'S',' ',':',':','=',' ','R',' ','R'> >::type,
          string<'x','x'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "sequence");

  meta_require<
    is_error<
      apply_wrap2<
        grammar<>
          ::rule<string<'R',' ',':',':','=',' ','\'','x','\''> >::type
          ::rule<string<'S',' ',':',':','=',' ','R',' ','R'> >::type,
        string<'y','x'>,
        start
      >
    >
  >(MPLLIBS_HERE, "sequence_first_fail");

  meta_require<
    is_error<
      apply_wrap2<
        grammar<>
          ::rule<string<'R',' ',':',':','=',' ','\'','x','\''> >::type
          ::rule<string<'S',' ',':',':','=',' ','R',' ','R'> >::type,
        string<'x','y'>,
        start
      >
    >
  >(MPLLIBS_HERE, "sequence_second_fail");

  meta_require<
    equal_to<
      char_<'x'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'Y',' ',':',':','=',' ','\'','y','\''> >::type
            ::rule<string<'X',' ',':',':','=',' ','\'','x','\''> >::type
            ::rule<string<'S',' ',':',':','=',' ','X','|','Y'> >::type,
          string<'x'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "selection 1");

  meta_require<
    equal_to<
      char_<'y'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'Y',' ',':',':','=',' ','\'','y','\''> >::type
            ::rule<string<'X',' ',':',':','=',' ','\'','x','\''> >::type
            ::rule<string<'S',' ',':',':','=',' ','X','|','Y'> >::type,
          string<'y'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "selection 2");

  meta_require<
    is_error<
      apply_wrap2<
        grammar<>
          ::rule<string<'Y',' ',':',':','=',' ','\'','y','\''> >::type
          ::rule<string<'X',' ',':',':','=',' ','\'','x','\''> >::type
          ::rule<string<'S',' ',':',':','=',' ','X','|','Y'> >::type,
        string<'z'>,
        start
      >
    >
  >(MPLLIBS_HERE, "selection_fail");

  meta_require<
    equal<
      vector<>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'X',' ',':',':','=',' ','\'','x','\''> >::type
            ::rule<string<'S',' ',':',':','=',' ','X','*'> >::type,
          string<'y'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "repeat_0");

  meta_require<
    equal<
      vector<char_<'x'> >,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'X',' ',':',':','=',' ','\'','x','\''> >::type
            ::rule<string<'S',' ',':',':','=',' ','X','*'> >::type,
          string<'x','y'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "repeat_1");

  meta_require<
    equal<
      vector<char_<'x'>, char_<'x'> >,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'X',' ',':',':','=',' ','\'','x','\''> >::type
            ::rule<string<'S',' ',':',':','=',' ','X','*'> >::type,
          string<'x','x','y'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "repeat_2");

  meta_require<
    equal_to<
      char_<'x'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'S',' ',':',':','=',' ','(','\'','x','\'',')'> >::type,
          string<'x'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "bracket");

  meta_require<
    equal_to<
      char_<'y'>,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<
              string<'S',' ',':',':','=',' ','\'','x','\''>,
              next_char
            >::type,
          string<'x'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "semantic_action");

  meta_require<
    is_error<
      apply_wrap2<
        grammar<>
          ::rule<string<'X',' ',':',':','=',' ','\'','x','\''> >::type
          ::rule<string<'S',' ',':',':','=',' ','X','+'> >::type,
        string<'y'>,
        start
      >
    >
  >(MPLLIBS_HERE, "repeat+_0");

  meta_require<
    equal<
      vector<char_<'x'> >,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'X',' ',':',':','=',' ','\'','x','\''> >::type
            ::rule<string<'S',' ',':',':','=',' ','X','+'> >::type,
          string<'x','y'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "repeat+_1");

  meta_require<
    equal<
      vector<char_<'x'>, char_<'x'> >,
      get_result<
        apply_wrap2<
          grammar<>
            ::rule<string<'X',' ',':',':','=',' ','\'','x','\''> >::type
            ::rule<string<'S',' ',':',':','=',' ','X','+'> >::type,
          string<'x','x','y'>,
          start
        >
      >::type
    >
  >(MPLLIBS_HERE, "repeat+_2");
}


