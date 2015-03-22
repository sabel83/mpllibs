# Getting started with mpllibs::metaparse

## Table of contents

## 1. Introduction

This tutorial shows you how to build a parser for a small calculator language
from the ground up. The goal is not to have a complete calculator, but to show
you the most common situations one can face while building a parser using
Metaparse. This tutorial assumes, that you have some template metaprogramming
experience.

### 1.1. Testing environment

While you are using Metaparse, you will be writing parsers turning an input text
into a type. These types can later be processed by further template
metaprograms. While you are working on your parsers, you'll probably want to
look at the result of parsing a test input. This tutorial assumes that you can
use [Metashell](https://github.com/sabel83/metashell). Since the
[online demo](http://abel.web.elte.hu/shell/metashell.html) makes the Mpllibs
headers available, you can use that in the tutorial as well.

This tutorial is long and therefore you might want to make shorter or longer
breaks while reading it. To make it easy for you to stop at a certain point and
continue later (or to start in the middle if you are already familiar with the
basics) Metaparse has a `getting_started` directory in the `example`s. This
contains the definitions for each section of this tutorial.

If you're about to start (or continue) this guide from section 5.2.1, you can
include `5_2_1.hpp`. This will define everything you need to start with that
section.

> You have access to these headers in the online Metashell demo as well. For
> example you can include the `<mpllibs/metaparase/getting_started/5_2_1.hpp>`
> header to start from section 5.2.1.

## 2. The text to parse

With Metaparse you can create template metaprograms parsing an input text. To
pass the input text to the metaprograms, you need to represent them as types.
For example let's represent the text `"Hello world"` as a type. The most
straightforward way of doing it would be creating a variadic template class
taking the characters of the text as template arguments:

```cpp
template <char... Cs>
struct string;
```

The text `"11 + 2"` can be represented the following way:

```cpp
string<'1', '1', ' ', '+', ' ', '2'>
```

Metaparse provides this type for you. Run the following command in Metashell:

```cpp
> #include <mpllibs/metaparse/string.hpp>
```

> Note that in the [online-demo](http://abel.web.elte.hu/shell/metashell.html)
> of Metashell you can paste code into the shell by right-clicking on the shell
> somewhere and choosing _Paste from browser_ in the context menu.

This will make this type available for you. Now you can try running the
following command:

```cpp
> mpllibs::metaparse::string<'1', '1', ' ', '+', ' ', '2'>
```

The shell will echo (almost) the same type back to you. The only difference is
that it is in a sub-namespace indicating the version of Metaparse being used.

The nice thing about this representation is that metaprograms can easily access
the individual characters of the text. The not so nice thing about this
representation is that if you want to write the text `"Hello world"` in your
source code, you have to type a lot.

Metaparse provides a macro that can turn a string literal into an instance of
[`mpllibs::metaparse::string`](string.html). This is the [`MPLLIBS_STRING`](
MPLLIBS_STRING.html) macro. You get it by including
`<mpllibs/metaparse/string.hpp>`. Let's try it by running the following command
in Metashell:

```cpp
> MPLLIBS_STRING("11 + 2")
```

You will get the same result as you got by instantiating
[`mpllibs::metaparse::string`](string.html) yourself.

## 3. Creating a simple parser

Let's try creating a parser. We will start with creating a parser for something
simple: we will be parsing integer numbers, such as the text `"13"`. You can
think of this first parsing exercise as a _template metaprogramming
string-to-int conversion_ because we expect to get the value `13` as the result
of parsing.

> You know the difference between `"13"` and `13` in C++. One of them is a
> character array, the other one is an integral value. But what is the
> difference between them in template metaprogramming? They are represented by
> different types. For example `"13"` is represented by
> [`string`](string.html)`<'1', '3'>` while `13` is represented by
> `std::integral_constant<int, 13>`.

To build a parser, we need to specify the grammar to use. Metaparse provides
building blocks (called parsers) we can use to do this and one of them is the
[`int_`](int_.html) parser which does exactly what we need: it parses integers.
To make it available, we need to include it:

```cpp
> #include <mpllibs/metaparse/int_.hpp>
```

Our grammar is simple: [`int_`](int_.html). (Don't worry, we'll parse more
complicated languages later).

A parser is a [template metafunction class](metafunction_class.html). It can be
used directly, but its interface is designed for completeness and not for ease
of use. Metaparse provides the [`build_parser`](build_parser.html)
[metafunction](metafunction.html) that adds a wrapper to parsers with a simple
interface.

> In this tutorial, we will always be wrapping our parsers with this. We will
> call these wrapped parsers parsers as well. If you are interested in it, you
> can learn about the complete interface of parsers [here](parser.html).

Let's create a parser using [`int_`](int_.html) and [`build_parser`](
build_parser.html):

```cpp
> #include <mpllibs/metaparse/build_parser.hpp>
> using namespace mpllibs::metaparse;
> using exp_parser1 = build_parser<int_>;
```

First we need to include `build_parser.hpp` to make [`build_parser`](
build_parser.html) available. Then we make our lives easier by running
`using namespace mpllibs::metaparse;`. The third command defines the parser:
we need to instantiate the [`build_parser`](build_parser.html) template class
with our parser ([`int_`](int_.html) in this case) as argument.

Now that we have a parser, let's parse some text with it (if you haven't done it
yet, include `mpllibs/metaparse/string.hpp`):

```cpp
> exp_parser1::apply<MPLLIBS_STRING("13")>::type
mpl_::integral_c<int, 13>
```

`exp_parser1` is a [template metafunction class](metafunction_class.html) taking
the input text as it's argument and it returns the integral representation of
the number in the string. Try it with different numbers and see how it converts
them.

### 3.1. Dealing with invalid input

Have you tried parsing an invalid input? Something that is not a number, such
as:

```cpp
> exp_parser1::apply<MPLLIBS_STRING("thirteen")>::type
<< compilation error >>
```

Well, `"thirteen"` _is_ a number, but our parser does not speak English, so it
is considered as invalid input. As a result of this, compilation fails and you
get a compilation error from Metashell.

In the [Dealing with invalid input](#dealing-with-invalid-input-1) section we
will go into further details on error handling.

### 3.2. Dealing with input containing more than what is needed

Let's try to give the parser two numbers instead of one:

```cpp
> exp_parser1::apply<MPLLIBS_STRING("11 13")>::type
mpl_::integral_c<int, 11>
```

You might be surprised by this: the parser did not return an error. It parsed
the first number, `11` and ignored `13`. The way [`int_`](int_.html) works is
that it parses the number at the beginning of the input text and ignores the
rest of the input.

So `exp_parser1` has a bug: our little language consists of _one_ number, not a
_list of numbers_. Let's fix our parser to treat more than one numbers as an
invalid input:

```cpp
> #include <mpllibs/metaparse/entire_input.hpp>
```

This gives us the [`entire_input`](entire_input.html) template class. We can
wrap [`int_`](int_.html) with [`entire_input`](entire_input.html) indicating
that the number we parse with [`int_`](int_.html) should be the entire input.
Anything that comes after that is an error. So our parser is
[`entire_input`](entire_input.html)`<`[`int_`](int_.html)`>` now. Let's wrap it
with [`build_parser`](build_parser.html):

```cpp
> using exp_parser2 = build_parser<entire_input<int_>>;
```

Let's try this new parser out:

```cpp
> exp_parser2::apply<MPLLIBS_STRING("13")>::type
mpl_::integral_c<int, 13>
```

It can still parse numbers. Let's try to give it two numbers:

```cpp
> exp_parser2::apply<MPLLIBS_STRING("11 13")>::type
<< compilation error >>
```

This generates a compilation error, since the parser failed.

### 3.3. Accepting optional whitespaces at the end of the input

Our parser became a bit too
restrictive now. It doesn't allow _anything_ after the number, not even
whitespaces:

```cpp
> exp_parser2::apply<MPLLIBS_STRING("11 ")>::type
<< compilation error >>
```

Let's allow whitespaces after the number:

```cpp
> #include <mpllibs/metaparse/token.hpp>
```

This makes the [`token`](token.html) template class available. It takes a parser
as its argument and allows optional whitespaces after that. Let's create a third
parser allowing whitespaces after the number:

```cpp
> using exp_parser3 = build_parser<entire_input<token<int_>>>;
```

We expect [`token`](token.html)`<`[`int_`](int_.html)`>` to be the entire input
in this case. We allow optional whitespaces after [`int_`](int_.html) but
nothing else:

```cpp
> exp_parser3::apply<MPLLIBS_STRING("11 ")>::type
mpl_::integral_c<int, 11>
```

## 4. Parsing simple expressions

We can parse numbers. Let's try parsing something more complicated, such as
`"11 + 2"`. This is a number followed by a `+` symbol followed by another
number. [`int_`](int_.html) (or [`token`](token.html)`<`[`int_`](int_.html)`>`)
implements the parser for one number.

First, let's write a parser for the `+` symbol. We can use the following:

```cpp
> #include <mpllibs/metaparse/lit_c.hpp>
```

This gives us [`lit_c`](lit_c.html) which we can use to parse specific
characters, such as `+`. The grammar parsing the `+` character can be
represented by [`lit_c`](lit_c.html)`<'+'>`. To allow optional whitespaces after
it, we should use [`token`](token.html)`<`[`lit_c`](lit_c.html)`<'+'>>`.

So to parse `"11 + 2"` we need the following sequence of parsers:

```cpp
token<int_>    token<lit_c<'+'>>    token<int_>
```

Metaparse provides [`sequence`](sequence.html) for parsing the sequence of
things:

```cpp
> #include <mpllibs/metaparse/sequence.hpp>
```

We can implement the parser for our expressions using [`sequence`](
sequence.html):

```cpp
sequence<token<int_>, token<lit_c<'+'>>, token<int_>>
```

Let's create a parser using it:

```cpp
> using exp_parser4 = build_parser<sequence<token<int_>, token<lit_c<'+'>>, token<int_>>>;
```

Try parsing a simple expression using it:

```cpp
> exp_parser4::apply<MPLLIBS_STRING("11 + 2")>::type
boost::mpl::v_item<mpl_::integral_c<int, 2>, boost::mpl::v_item<mpl_::char_<'+'>
, boost::mpl::v_item<mpl_::integral_c<int, 11>, boost::mpl::vector0<mpl_::na>, 0
>, 0>, 0>
```

What you get might look strange to you. It is a `vector` from [Boost.MPL](
http://boost.org/libs/mpl). What you can see in the shell is the way this vector
is represented. Metashell offers [pretty printing](
https://github.com/sabel83/metashell#data-structures-of-boostmpl) for
[Boost.MPL](http://boost.org/libs/mpl) containers:

```cpp
> #include <metashell/formatter.hpp>
```

After including this header, try parsing again:

```cpp
> exp_parser4::apply<MPLLIBS_STRING("11 + 2")>::type
boost_::mpl::vector<mpl_::integral_c<int, 11>, mpl_::char_<'+'>, mpl_::integral_c<int, 2> >
```

What you get now looks more simple: this is a vector of three elements:

* `mpl_::integral_c<int, 11>` This is the result of parsing with
  [`token`](token.html)`<`[`int_`](int_.html)`>`.
* `mpl_::char_<'+'>` This is the result of parsing with
  [`token`](token.html)`<`[`lit_c`](lit_c.html)`<'+'>>`.
* `mpl_::integral_c<int, 2> >` This is the result of parsing with
  [`token`](token.html)`<`[`int_`](int_.html)`>`.

The result of parsing with a [`sequence`](sequence.html) is the `vector` of the
individual parsing results.

### 4.1. Tokeniser

You might have noticed that our parsers have no separate tokenisers.
Tokenisation is part of the parsing process. However, it makes the code of the
parsers cleaner if we separate the two layers. The previous example has two
types of tokens:

* a number (eg. `13`)
* a `+` symbol

In our last solution we parsed them by using the
[`token`](token.html)`<`[`int_`](int_html)`>` and
[`token`](token.html)`<`[`lit_c`](lit_c.html)`<'+'>>` parsers. Have you noticed
a pattern? We wrap the parsers of the tokens with [`token`](token.html)`<...>`.
It is not just syntactic sugar. Our tokens might be followed (separated) by
whitespaces, which can be ignored. That is what [`token`](token.html)`<...>`
implements.

So let's make the implementation of `exp_parser` cleaner by separating the
tokenisation from the rest of the parser:

```cpp
> using int_token = token<int_>;
> using plus_token = token<lit_c<'+'>>;
```

These two definitions create type aliases for the parsers of our tokens. For the
compiler it doesn't matter if we use `plus_token` or
[`token`](token.html)`<`[`lit_c`](lit_c.html)`<'+'>>`, since they refer to the
same type. But it makes the code of the parser easier to understand.

We can now define our expression parser using these tokens:

```cpp
> using exp_parser5 = build_parser<sequence<int_token, plus_token, int_token>>;
```

We can use it the same way as `exp_parser4`:

```cpp
> exp_parser5::apply<MPLLIBS_STRING("11 + 2")>::type
boost_::mpl::vector<mpl_::integral_c<int, 11>, mpl_::char_<'+'>, mpl_::integral_c<int, 2> >
```

### 4.2. Evaluating the expression

It would be nice if we could evaluate the expression as well. Instead of
returning a `vector` as the result of parsing, we should return the evaluated
expression. For example the result of parsing `"11 + 2"` should be
`mpl_::integral_c<int, 13>`.

Metaparse provides [`transform`](transform.html) which we can use to implement
this:

```cpp
> #include <mpllibs/metaparse/transform.hpp>
```

This can be used to transform the result of a parser. For example we have the
[`sequence`](sequence.html)`<int_token, plus_token, int_token>` parser which
returns a `vector`. We want to transform this `vector` into a number, which is
the result of evaluating the expression. We need to pass
[`transform`](transform.html) the [`sequence`](sequence.html)`<...>` parser and
a function which turns the `vector` into the result we need. First let's create
this [metafunction](metafunction.html):

```cpp
> #include <boost/mpl/plus.hpp>
> #include <boost/mpl/at.hpp>
> template <class Vector> \
...> struct eval_plus : \
...>   boost::mpl::plus< \
...>     typename boost::mpl::at_c<Vector, 0>::type, \
...>     typename boost::mpl::at_c<Vector, 2>::type \
...>   > {};
```

What it does is that using [`at_c`](at_c.html) it takes the first (index 0) and
the third (index 2) elements of the `vector` that is the result of parsing with
[`sequence`](sequence.html)`<...>` and adds them. We can try it out with an
example `vector`:

```cpp
> eval_plus< \
...>  boost::mpl::vector< \
...>    mpl_::integral_c<int, 11>, \
...>    mpl_::char_<'+'>, \
...>    mpl_::integral_c<int, 2> \
...>  >>::type
mpl_::integral_c<int, 13>
```

We can use `eval_plus` to build a parser that evaluates the expression it
parses:

```cpp
> #include <boost/mpl/quote.hpp>
> using exp_parser6 = \
...> build_parser< \
...>   transform< \
...>     sequence<int_token, plus_token, int_token>, \
...>     boost::mpl::quote1<eval_plus> \
...>   > \
...> >;
```

> Note that we have to use `boost::mpl::quote1` to turn our `eval_plus`
> [metafunction](metafunction.html) into a [metafunction
> class](metafunction_class.html).

[`transform`](transform.html) parses the input using
[`sequence`](sequence.html)`<int_token, plus_token, int_token>` and transforms
the result of that using `eval_plus`. Let's try it out:

```cpp
> exp_parser6::apply<MPLLIBS_STRING("11 + 2")>::type
mpl_::integral_c<int, 13>
```

We have created a simple expression parser. The following diagram shows how it
works:

<p align="center">
  <a href="tutorial_diag0.png"><img src="tutorial_diag0.png" style="width:50%" /></a>
</p>

The rounded boxes in the diagram are the parsers parsing the input, which are
functions ([template metafunction class](metafunction_class.html)es). The arrows
represent how the results are passed around between these parsers (they are the
return values of the function calls).

It uses [`sequence`](sequence.html) to parse the different elements (the first
number, the `+` symbol and the second number) and builds a `vector`. The final
result is calculated from that `vector` by the [`transform`](transform.html)
parser.

## 5. Parsing longer expressions

We can parse simple expressions adding two numbers together. But we can't parse
expressions adding three, four or maybe more numbers together. In this section
we will implement a parser for expressions adding lots of numbers together.

### 5.1. Parsing a subexpression repeatedly

We can't solve this problem with [`sequence`](sequence.html), since we don't
know how many numbers the input will have. We need a parser that:

* parses the first number
* keeps parsing `+ <number>` elements until the end of the input

Parsing the first number is something we can already do: the `int_token` parser
does it for us. Parsing the `+ <number>` elements is more tricky. Metaparse
offers different tools for approaching this. The most simple is
[`any`](any.html):

```cpp
> #include <mpllibs/metaparse/any.hpp>
```

[`any`](any.html) needs a parser (which parses one `+ <number>` element) and it
keeps parsing the input with it as long as it can. This will parse the entire
input for us. Let's create a parser for our expressions using it:

```cpp
> using exp_parser7 = \
...> build_parser< \
...>   sequence< \
...>     int_token,                           /* The first <number> */ \
...>     any<sequence<plus_token, int_token>> /* The "+ <number>" elements */ \
...>   > \
...> >;
```

We have a [`sequence`](sequence.html) with two elements:

* The first number (`int_token`)
* The `+ <number>` parts

The second part is an [`any`](any.html), which parses the `+ <number>` elements.
One such element is parsed by
[`sequence`](sequence.html)`<plus_token, int_token>`. This is just a sequence of
the `+` symbol and the number.

Let's try parsing an expression using this:

```cpp
> exp_parser7::apply<MPLLIBS_STRING("1 + 2 + 3 + 4")>::type
```

Here is a formatted version of the result which is easier to read:

```cpp
boost_::mpl::vector<
  // The result of int_token
  mpl_::integral_c<int, 1>,

  // The result of any< sequence<plus_token, int_token> >
  boost_::mpl::vector<
    boost_::mpl::vector<mpl_::char_<'+'>, mpl_::integral_c<int, 2> >,
    boost_::mpl::vector<mpl_::char_<'+'>, mpl_::integral_c<int, 3> >,
    boost_::mpl::vector<mpl_::char_<'+'>, mpl_::integral_c<int, 4> >
  >
> 
```

The result is a `vector` of two elements. The first element of this `vector` is
the result of parsing the input with `int_token`, the second element of this
`vector` is the result of parsing the input with
[`any`](any.html)`< `[`sequence`](sequence.html)`<plus_token, int_token>>`.
This second element is also a `vector`. Each element of this `vector` is the
result of parsing the input with
[`sequence`](sequence.html)`<plus_token, int_token>` once. Here is a diagram
showing how `exp_parser7` parses the input `1 + 2 + 3 + 4`:

<p align="center">
  <a href="tutorial_diag1.png"><img src="tutorial_diag1.png" style="width:90%" /></a>
</p>

The diagram shows that the `+ <number>` elements are parsed by
[`sequence`](sequence.html)`<plus_token, int_token>` elements and their results
are collected by [`any`](any.html), which constructs a `vector` of these
results. The value of the first `<number>` and this `vector` are placed in
another `vector`, which is the result of parsing.

### 5.2. Evaluating the parsed expression

The final result here is a pair of the first number and the `vector` of the rest
of the values. To calculate the result we need to process that data structure.
Let's give the example output we have just parsed a name. This will make it
easier to test the code calculating the final result from this structure:

```cpp
> using temp_result = exp_parser7::apply<MPLLIBS_STRING("1 + 2 + 3 + 4")>::type;
```

Now we can write a [template metafunction](metafunction.html) turning this
structure into the result of the calculation this structure represents.

#### 5.2.1. Learning about `boost::mpl::fold`

We have a `vector` containing
another `vector`. Therefore, we will need to be able to summarise the elements
of different `vector`s. We can use the `boost::mpl::fold` [metafunction](
metafunction.html) to do this:

```cpp
> #include <boost/mpl/fold.hpp>
```

With this [metafunction](metafunction.html), we can iterate over a `vector` of
parsed numbers and summarise them. We can provide it a [metafunction](
metafunction.html) taking two arguments: the sum we have so far and the next
element of the `vector`. This [metafunction](metafunction.html) will be called
for every element of the `vector`.

> Note that this is very similar to the `std::accumulate` algorithm.
> [Boost.MPL](http://boost.org/libs/mpl) provides `boost::mpl::accumulate` as
> well, which is a synonym for `boost::mpl::fold`. This tutorial (and Metaparse)
> uses the name `fold`.

Let's start with a simple case: a `vector` of numbers. For example let's
summarise the elements of the following `vector`:

```cpp
> using vector_of_numbers = \
...> boost::mpl::vector< \
...>   boost::mpl::int_<2>, \
...>   boost::mpl::int_<5>, \
...>   boost::mpl::int_<6> \
...> >;
```

We will write a [template metafunction](metafunction.html), `sum_vector` for
summarising the elements of a `vector` of numbers:

```cpp
> template <class Vector> \
...> struct sum_vector : \
...>    boost::mpl::fold< \
...>      Vector, \
...>      boost::mpl::int_<0>, \
...>      boost::mpl::lambda< \
...>        boost::mpl::plus<boost::mpl::_1, boost::mpl::_2> \
...>      >::type \
...>    > \
...>  {};
```

This [metafunction](metafunction.html) takes the `vector` to summarise the
elements of as its argument and uses `boost::mpl::fold` to calculate the sum.
`boost::mpl::fold` takes three arguments:

* The container to summarise. This is `Vector`.
* The starting value for _the sum we have so far_. Using `0` means that we want
  to start the sum from `0`.
* The function to call in every iteration while looping over the container. We
  are using a [lambda
  expression](http://www.boost.org/libs/mpl/doc/refmanual/lambda-expression.html)
  in our example, which is the expression wrapped by `boost::mpl::lambda`. This
  expression adds its two arguments together using `boost::mpl::plus`. The
  lambda expression refers to its arguments by `boost::mpl::_1` and
  `boost::mpl::_2`.

Let's try this [metafunction](metafunction.html) out:

```cpp
> sum_vector<vector_of_numbers>::type
mpl_::integral_c<int, 13>
```

It works as expected. Here is a diagram showing how it works:

<p align="center">
  <a href="tutorial_diag2.png"><img src="tutorial_diag2.png" style="width:50%" /></a>
</p>

As the diagram shows, `boost::mpl::fold` evaluates the lambda expression for
each element of the `vector` and passes the result of the previous evaluation to
the next lambda expression invocation.

We have a [metafunction](metafunction.html) that can summarise a `vector` of
numbers. The result of parsing the `+ <number>` elements is a `vector` of
`vector`s. As a recap, here is `temp_result`:

```cpp
boost_::mpl::vector<
  // The result of int_token
  mpl_::integral_c<int, 1>,

  // The result of any< sequence<plus_token, int_token> >
  boost_::mpl::vector<
    boost_::mpl::vector<mpl_::char_<'+'>, mpl_::integral_c<int, 2> >,
    boost_::mpl::vector<mpl_::char_<'+'>, mpl_::integral_c<int, 3> >,
    boost_::mpl::vector<mpl_::char_<'+'>, mpl_::integral_c<int, 4> >
  >
> 
```

First let's summarise the result of [`any`](any.html)`<...>` using
`boost::mpl::fold`. This is a `vector` of `vector`s, but that's fine.
`boost::mpl::fold` doesn't care about what the elements of the `vector` are.
They can be numbers, `vector`s or something else as well. The function we use to
add two numbers together (which was a lambda expression in our previous example)
gets these elements as its argument and has to deal with them. So to summarise
the elements of the `vector`s we get as the result of parsing with
[`any`](any.html)`<...>`, we need to write a [metafunction](metafunction.html)
that can deal with these elements. One such element is
`boost_::mpl::vector<mpl_::char<'+'>, mpl_::integral_c<int, 2>>`. Here is a
[metafunction](metafunction.html) that can be used in a `boost::mpl::fold`:

```cpp
> template <class Sum, class Item> \
...>   struct sum_items : \
...>     boost::mpl::plus< \
...>       Sum, \
...>       typename boost::mpl::at_c<Item, 1>::type \
...>     > \
...> {};
```

This function takes two arguments:

* `Sum`, which is a number. This is the summary of the already processed
  elements.
* `Item`, the next item of the `vector`. These items are `vector`s of size two:
  the result of parsing the `+` symbol and the number.

The [metafunction](metafunction.html) adds the sum we have so far and the next
number together using the `boost::mpl::plus` [metafunction](metafunction.html).
To get the next number out of `Item`, it uses `boost::mpl::at_c`. Let's try
`sum_items` out:

```cpp
> sum_items< \
...>   mpl_::integral_c<int, 1>, \
...>   boost::mpl::vector<mpl_::char_<'+'>, mpl_::integral_c<int, 2>> \
...> >::type
mpl_::integral_c<int, 3>
```

We have called `sum_items` with values from `temp_result` and saw that it works
as expected: it added the partial sum (`mpl_::integral_c<int, 1>`) to the next
number (`mpl_::integral_c<int, 2>`).

`boost::mpl::fold` can summarise the list we get as the result of parsing the
`+ <number>` elements of the input, so we need to extract this list from
`temp_result` first:

```cpp
> boost::mpl::at_c<temp_result, 1>::type
```

Here is the formatted version of the result:

```cpp
boost_::mpl::vector<
  boost_::mpl::vector<mpl_::char_<'+'>, mpl_::integral_c<int, 2>>,
  boost_::mpl::vector<mpl_::char_<'+'>, mpl_::integral_c<int, 3>>,
  boost_::mpl::vector<mpl_::char_<'+'>, mpl_::integral_c<int, 4>>
>
```

This is the second element of the `temp_result` vector (the first one is the
value of the first `<number>` element). Let's try fold out for this:

```cpp
> \
...> boost::mpl::fold< \
...>   boost::mpl::at_c<temp_result, 1>::type, /* The vector to summarise */ \
...>   boost::mpl::int_<0>, /* The value to start the sum from */ \
...>   boost::mpl::quote2<sum_items> /* The function to call in each iteration */ \
...> >::type
mpl_::integral_c<int, 9>
```

> We are using `sum_items` as the function to call in each iteration. We are
> passing a [metafunction](metafunction.html) (`sum_items`) to another
> [metafunction](metafunction.html) (`boost::mpl::fold`) as an argument. To be
> able to do this, we need to turn it into a
> [template metafunction class](metafunction_class.html) using
> `boost::mpl::quote2` (`2` means that it takes two arguments).

As we have seen, the result of this is the sum of the elements, which was `9` in
our case. Here is a diagram showing how `boost::mpl::fold` works:

<p align="center">
  <a href="tutorial_diag3.png"><img src="tutorial_diag3.png" style="width:50%" /></a>
</p>

It starts with the value `boost::mpl::int_<0>` and adds the elements of the
`boost_::mpl::vector` containing the parsing results one by one. The diagram
shows how the subresults are calculated and then used for further calculations.

#### 5.2.2. Evaluating the expression using `boost::mpl::fold`

Let's use `sum_items` with `boost::mpl::fold` to build the parser that
summarises the values coming from the `+ <number>` elements. We can extend the
parser we were using in `exp_parser7` by wrapping the [`any`](any.html)`<...>`
part with [`transform`](transform.html), which transforms the result of
[`any`](any.html)`<...>` with the folding expression we have just created:

```cpp
> using exp_parser8 = \
...> build_parser< \
...>   sequence< \
...>     int_token, /* parse the first <number> */ \
...>     transform< \
...>       any<sequence<plus_token, int_token>>, /* parse the "+ <number>" elements */ \
...> \
...>       /* lambda expression summarising the "+ <number>" elements using fold */ \
...>       boost::mpl::lambda< \
...>         /* The folding expression we have just created */ \
...>         boost::mpl::fold< \
...>           boost::mpl::_1, /* the argument of the lambda expression, the result */ \
...>                           /* of the any<...> parser */ \
...>           boost::mpl::int_<0>, \
...>           boost::mpl::quote2<sum_items> \
...>         > \
...>       >::type \
...>     > \
...>   > \
...> >;
```

It uses [`transform`](transform.html) to turn the result of the previous version
of our parser into one that summarises the `+ <number>` elements. Let's try it
out:

```cpp
> exp_parser8::apply<MPLLIBS_STRING("1 + 2 + 3 + 4")>::type
boost_::mpl::vector<mpl_::integral_c<int, 1>, mpl_::integral_c<int, 9> >
```

This returns a pair of numbers as the result of parsing: the first number and
the sum of the rest. To get the value of the entire expression we need to add
these two numbers together. We can extend our parser to do this final addition
as well:

```cpp
> using exp_parser9 = \
...> build_parser< \
...>   transform< \
...>     /* What we had so far */ \
...>     sequence< \
...>       int_token, \
...>       transform< \
...>         any<sequence<plus_token, int_token>>, \
...>         boost::mpl::lambda< \
...>           boost::mpl::fold< \
...>             boost::mpl::_1, \
...>             boost::mpl::int_<0>, \
...>             boost::mpl::quote2<sum_items> \
...>           > \
...>         >::type \
...>       > \
...>     >, \
...>     boost::mpl::quote1<sum_vector> /* summarise the vector of numbers */ \
...>   > \
...> >;
```

`exp_parser9` wraps the parser we had so far (which gives us the two element
`vector` as the result) with [`transform`](transform.html) to add the elements
of that two element `vector` together. Since that two element `vector` is a
`vector` of numbers, we can (re)use the `sum_vector` [metafunction](
metafunction.html) for this. Let's try it out:

```cpp
> exp_parser9::apply<MPLLIBS_STRING("1 + 2 + 3 + 4")>::type
│mpl_::integral_c<int, 10>
```

It gives us the correct result, but it is very inefficient. Let's see why:

<p align="center">
  <a href="tutorial_diag4.png"><img src="tutorial_diag4.png" style="width:90%" /></a>
</p>

There are two loops in this process:

* first [`any`](any.html) loops over the input to parse all of the `+ <number>`
  elements. It builds a `vector` during this. (`Loop 1` on the diagram)
* then `boost::mpl::fold` loops over this `vector` to summarise the elements.
  (`Loop 2` on the diagram)

> Note that we have been talking about _loop_s while there is no such thing as a
> loop in template metaprogramming. Loops can be implemented using _recursion_:
> every recursive call is one iteration of the loop. The loop is stopped at the
> bottom of the recursive chain.

#### 5.2.3. Using a folding parser combinator

It would be nice, if the two loops could be merged together and the temporary
`vector` wouldn't have to be built in the middle (don't forget: there is no
such thing as a _garbage collector_ for template metaprogramming. Once you
instantiate a template, it will be available until the end of ... the
compilation).

Metaparse provides the [`foldl`](foldl.html) parser combinator:

```cpp
> #include <mpllibs/metaparse/foldl.hpp>
```

It is almost the same as `boost::mpl::fold`, but instead of taking the `vector`
as its first argument, which was coming from the repeated application of a
parser ([`sequence`](sequence.html)`<plus_token, int_token>`) on the input, it
takes the parser itself. [`foldl`](foldl.html) parses the input and calculates
the summary on the fly. Here is how we can write our parser using it:

```cpp
> using exp_parser10 = \
...> build_parser< \
...>   transform< \
...>     sequence< \
...>       int_token, \
...>       foldl< \
...>         sequence<plus_token, int_token>, \
...>         boost::mpl::int_<0>, \
...>         boost::mpl::quote2<sum_items> \
...>       > \
...>     >, \
...>     boost::mpl::quote1<sum_vector>> \
...> >;
```

Here are the formatted versions of `exp_parser9` and `exp_parser10` side-by-side:

```cpp
//            exp_parser9                                       exp_parser10

build_parser<                                       build_parser<
  transform<                                          transform<
    sequence<                                           sequence<
      int_token,                                          int_token,


      transform<                                          foldl<
        any<sequence<plus_token, int_token>>,               sequence<plus_token, int_token>,
        boost::mpl::lambda<
          boost::mpl::fold<
            boost::mpl::_1,
            boost::mpl::int_<0>,                            boost::mpl::int_<0>,
            boost::mpl::quote2<sum_items>                   boost::mpl::quote2<sum_items>
          >
        >::type
      >                                                   >


    >,                                                  >,
    boost::mpl::quote1<sum_vector>                      boost::mpl::quote1<sum_vector>
  >                                                   >
>                                                   >
```

In `exp_parser10` the "_[`any`](any.html) and then [`transform`](transform.html)
with `boost::mpl::fold`_" part (the middle block of `exp_parser9`) has been
replaced by one [`foldl`](foldl.html) parser that does the same thing but
without building a `vector` in the middle. The same starting value
(`boost::mpl::int_<0>`) and callback function (`sum_items`) could be used.

Here is a diagram showing how `exp_parser10` works:

<p align="center">
  <a href="tutorial_diag5.png"><img src="tutorial_diag5.png" style="width:90%" /></a>
</p>

In this case, the results of the
[`sequence`](sequence.html)`<plus_token, int_token>` parsers are passed directly
to a folding algorithm without an intermediate `vector`. Here is a diagram
showing `exp_parser9` and `exp_parser10` side-by-side to make it easier to see
the difference:

<p align="center">
  <a href="tutorial_diag6.png"><img src="tutorial_diag6.png" style="width:100%" /></a>
</p>

#### 5.2.4. Processing the initial element with the folding parser combinator

This solution can still be improved. The [`foldl`](foldl.html) summarising the
`+ <number>` elements starts from `0` and once this is done, we add the value of
the first `<number>` of the input to it in the first iteration. It would be more
straightforward if [`foldl`](foldl.html) could use the value of the first
`<number>` as the initial value of the "_sum we have so far_". Metaparse provides
[`foldlp`](foldlp.html) for this:

```cpp
> #include <mpllibs/metaparse/foldlp.hpp>
```

[`foldlp`](foldlp.html) is almost the same as [`foldl`](foldl.html). The
difference is that instead of taking a starting _value_ for the sum it takes a
_parser_. First it parses the input with this parser and uses the value it
returns as the starting value. Here is how we can implement our parser using it:

```cpp
> using exp_parser11 = \
...> build_parser< \
...>   foldlp< \
...>     sequence<plus_token, int_token>, /* apply this parser repeatedly */ \
...>     int_token, /* use this parser to get the initial value */ \
...>     boost::mpl::quote2<sum_items> /* use this function to add a new value to the summary */ \
...>   > \
...> >;
```

This version of `exp_parser` uses [`foldlp`](foldlp.html). This implementation
is more compact than the earlier versions. There is no [`sequence`](
sequence.html) element in this: the first `<number>` is parsed by `int_token`
and its value is used as the initial value for the summary. Let's try it out:

```cpp
> exp_parser11::apply<MPLLIBS_STRING("1 + 2 + 3 + 4")>::type
mpl_::integral_c<int, 10>
```

It returns the same result as the earlier version but works differently. Here is
a diagram showing how this implementation works:

<p align="center">
  <a href="tutorial_diag7.png"><img src="tutorial_diag7.png" style="width:90%" /></a>
</p>

## 6. Adding support for other operators

Our parsers now support expressions adding numbers together. In this section we
will add support for the `-` operator, so expressions like `1 + 2 - 3` can be
evaluated.

### 6.1. Parsing expressions containing `-` operators

Currently we use the `plus_token` for parsing "the" operator, which has to be
`+`. We can define a new token for parsing the `-` symbol:

```cpp
> using minus_token = token<lit_c<'-'>>;
```

We need to build a parser that accepts either a `+` or a `-` symbol. This can be
implemented using [`one_of`](one_of.html):

```cpp
> #include <mpllibs/metaparse/one_of.hpp>
```

[`one_of`](one_of.html)`<plus_token, minus_token>` is a parser which accepts
either a `+` (using `plus_token`) or a `-` (using `minus_token`) symbol. The
result of parsing is the result of the parser that succeeded.

> You can give any parser to [`one_of`](one_of.html), therefore it is possible
> that more than one of them can parse the input. In those cases the order
> matters: [`one_of`](one_of.html) tries parsing the input with the parsers from
> left to right and the first one that succeeds, wins.

Using this, we can make our parser accept subtractions as well:

```cpp
> using exp_parser12 = \
...> build_parser< \
...>   foldlp< \
...>     sequence<one_of<plus_token, minus_token>, int_token>, \
...>     int_token, \
...>     boost::mpl::quote2<sum_items> \
...>   > \
...> >;
```

It uses [`one_of`](one_of.html)`<plus_token, minus_token>` as the separator for
the numbers. Let's try it out:

```cpp
> exp_parser12::apply<MPLLIBS_STRING("1 + 2 - 3")>::type
mpl_::integral_c<int, 6>
```

The result is not correct. The reason for this is that `sum_items`, the function
we summarise with ignores which operator was used and assumes that it is always
`+`.

### 6.2. Evaluating expressions containing `-` operators

To fix the evaluation of expressions containing subtractions, we need to fix
the function we use for summarising. We need to write a version that takes the
operator being used into account.

First of all we will need the `boost::mpl::minus` [metafunction](
metafunction.html) for implementing subtraction:

```cpp
> #include <boost/mpl/minus.hpp>
```

Let's write a helper metafunction that takes three arguments: the left operand,
the operator and the right operand:

```cpp
> template <class L, char Op, class R> struct eval_binary_op;
> template <class L, class R> struct eval_binary_op<L, '+', R> : boost::mpl::plus<L, R>::type {};
> template <class L, class R> struct eval_binary_op<L, '-', R> : boost::mpl::minus<L, R>::type {};
```

The first command declares the `eval_binary_op` metafunction. The first and
third arguments are the left and right operands and the second argument is the
operator.

> Note that it does not satisfy the expectations of a [template
> metafunction](metafunction.html) since it takes the operator as a `char` and
> not as a `class` (or `typename`) argument. For simplicity, we will still call
> it a metafunction.

The second and third commands define the operation for the cases when the
operator is `+` and `-`. When the `eval_binary_op` metafunction is called,
the C++ compiler chooses one of the definitions based on the operator. If you
have functional programming experience this approach (pattern matching) might be
familiar to you. Let's try `eval_binary_op` out:

```cpp
> eval_binary_op<boost::mpl::int_<11>, '+', boost::mpl::int_<2>>::type
mpl_::integral_c<int, 13>
> eval_binary_op<boost::mpl::int_<13>, '-', boost::mpl::int_<2>>::type                                
mpl_::integral_c<int, 11>
```

You might also try to use it with an operator it does not expect (yet). For
example `'*'`. You will see the C++ compiler complaining about that the
requested version of the `eval_binary_op` template has not been defined. This
solution can be extended and support for the `'*'` operator can always be added
later.

Let's write the [metafunction](metafunction.html) we can use from the folding
parser to evaluate the expressions using `+` and `-` operators. This takes two
arguments:

* The partial result we have evaluated so far. (This used to be the summary we
  have evaluated so far, but we are making it a more general evaluation now).
  This is the left operand, a number.
* The result of parsing `(+|-) <number>`. This a `vector` containing two
  elements: a character representing the operator (`+` or `-`) and the value of
  the `<number>`. The number is the right operand.

Let's write the [metafunction](metafunction.html) `binary_op` that takes these
arguments and calls `eval_binary_op`:

```cpp
> template <class S, class Item> \
...> struct binary_op : \
...>   eval_binary_op< \
...>     S, \
...>     boost::mpl::at_c<Item, 0>::type::value, \
...>     typename boost::mpl::at_c<Item, 1>::type \
...>   > \
...>   {};
```

This [metafunction](metafunction.html) takes the operator (the first element)
and the right operand (the second element) from `Item`. The operator is a class
representing a character, such as `mpl_::char_<'+'>`. To get the character value
out of it, one has to access its `::value`. For example `mpl_::char<'+'>::value`
is `'+'`. Since `eval_binary_op` takes this character value as its second
argument, we had to pass `boost::mpl::at_c<Item, 0>::type::value` to it. Let's
try it out:

```cpp
> binary_op<boost::mpl::int_<11>, boost::mpl::vector<boost::mpl::char_<'+'>, boost::mpl::int_<2>>>::type
mpl_::integral_c<int, 13>
```

We passed it a number (`11`) and a `vector` of a character (`+`) and another
number (`2`). It added the two numbers as expected. Let's use this function as
the third argument of [`foldlp`](foldlp.html):

```cpp
> using exp_parser13 = \
...> build_parser< \
...>   foldlp< \
...>     sequence<one_of<plus_token, minus_token>, int_token>, \
...>     int_token, \
...>     boost::mpl::quote2<binary_op> \
...>   > \
...> >;
```

It uses `binary_op` instead of `sum_items`. Let's try it out:

```cpp
> exp_parser13::apply<MPLLIBS_STRING("1 + 2 - 3")>::type
mpl_::integral_c<int, 0>
```

It returns the correct result.

## 7. Dealing with precedence

We support addition and subtraction. Let's support multiplication as well.

### 7.1. Adding support for the `*` operator

We can extend the solution we have built for addition and subtraction. To do
that, we need to add support for multiplication to `eval_binary_op`:

```cpp
> #include <boost/mpl/times.hpp>
> template <class L, class R> struct eval_binary_op<L, '*', R> : boost::mpl::times<L, R>::type {};
```

We had to include `<boost/mpl/times.hpp>` to get the `boost::mpl::times`
[metafunction](metafunction.html) and then we could extend `eval_binary_op` to
support the `*` operator as well. We can try it out:

```cpp
> eval_binary_op<boost::mpl::int_<3>, '*', boost::mpl::int_<4>>::type
mpl_::integral_c<int, 12>
```

This works as expected. Let's create a token for parsing the `*` symbol:

```cpp
> using times_token = token<lit_c<'*'>>;
```

Now we can extend our parser to accept the `*` symbol as an operator:

```cpp
> using exp_parser14 = \
...> build_parser< \
...>   foldlp< \
...>     sequence<one_of<plus_token, minus_token, times_token>, int_token>, \
...>     int_token, \
...>     boost::mpl::quote2<binary_op> \
...>   > \
...> >;
```

This version accepts either a `+`, a `-` or a `*` symbol as the operator. Let's
try this out:

```cpp
> exp_parser14::apply<MPLLIBS_STRING("2 * 3")>::type
mpl_::integral_c<int, 6>
``` 

This works as expected. Let's try another, slightly more complicated expression:

```cpp
> exp_parser14::apply<MPLLIBS_STRING("1 + 2 * 3")>::type
mpl_::integral_c<int, 9>
``` 

This returns a wrong result. The value of this expression should be `7`, not
`9`. The problem with this is that our current implementation does not take
operator precedence into account. It treats this expression as `(1 + 2) * 3`
while we expect it to be `1 + (2 * 3)` since addition has higher precedence than
multiplication.

### 7.2. Adding support for precedence of operators

Let's make it possible for different operators to have different precedence. To
do this, we define a new parser for parsing expressions containing only `*`
operators (that is the operator with the lowest precedence):

```cpp
> using mult_exp1 = foldlp<sequence<times_token, int_token>, int_token, boost::mpl::quote2<binary_op>>;
```

`mult_exp1` can parse expressions containing only `*` operator. For example
`3 * 2` or `6 * 7 * 8`. Now we can create a parser supporting only the `+` and
`-` operators but instead of separating _numbers_ with these operators we will
separate  _expressions containing only `*` operators_. This means that the
expression `1 * 2 + 3 * 4` is interpreted as the expressions `1 * 2` and `3 * 4`
separated by a `+` operator. A number (eg. `13`) is the special case of an
_expression containing only `*` operators_.

Here is the parser implementing this:

```cpp
> using exp_parser15 = \
...> build_parser< \
...>   foldlp< \
...>     sequence<one_of<plus_token, minus_token>, mult_exp1>, \
...>     mult_exp1, \
...>     boost::mpl::quote2<binary_op> \
...>   > \
...> >;
```

Note that this is almost the same as `exp_parser13`. The only difference is that
it uses `mult_exp1` everywhere, where `exp_parser13` was using `int_token`.
Let's try it out:

```cpp
> exp_parser15::apply<MPLLIBS_STRING("1 + 2 * 3")>::type                                              
mpl_::integral_c<int, 7>
```

This takes the precedence rules into account. The following diagram shows how it
works:

<p align="center">
  <a href="tutorial_diag8.png"><img src="tutorial_diag8.png" style="width:80%" /></a>
</p>

Subexpressions using `*` operators only are evaluated (by `mult_exp1`) and
treated as single units while interpreting expressions using `+` and `-`
operators. Numbers not surrounded by `*` operators are treated also as operators
using `*` only (containing no operations but a number).

If you need more layers (eg. introducing the `^` operator) you can extend this
solution with further layers. The order of the layers determine the precedence
of the operators.

## 8. Dealing with associativity

Let's add division to our calculator language. Since it has the same precedence
as multiplication, it should be added to that layer:

```cpp
> #include <boost/mpl/divides.hpp>
> template <class L, class R> struct eval_binary_op<L, '/', R> : boost::mpl::divides<L, R>::type {};
> using divides_token = token<lit_c<'/'>>;
> using mult_exp2 = \
...> foldlp< \
...>   sequence<one_of<times_token, divides_token>, int_token>, \
...>   int_token, \
...>   boost::mpl::quote2<binary_op> \
...> >;
> using exp_parser16 = \
...> build_parser< \
...>   foldlp< \
...>     sequence<one_of<plus_token, minus_token>, mult_exp2>, \
...>     mult_exp2, \
...>     boost::mpl::quote2<binary_op> \
...>   > \
...> >;
```

We have to include `<boost/mpl/divides.hpp>` to get a [metafunction](
metafunction.html) for doing a division. We need to extend the `eval_binary_op`
[metafunction](metafunction.html) to support division as well. We had to
introduce a new token, `divides_token` that can parse the `/` symbol.

We have extended `mult_exp1` to accept either a `times_token` or a
`divides_token` as the operator. This extended parser is called `mult_exp2`.

We have written a new parser, `exp_parser16` which is the same as `exp_parser15`
but uses `mult_exp2` instead of `mult_exp1`. This can parse expressions using
division as well (and this new operator has the right precedence). Let's try it
out:

```cpp
> exp_parser16::apply<MPLLIBS_STRING("8 / 4")>::type                                                  
mpl_::integral_c<int, 2>
```

This works as expected. But what should be the value of `8 / 4 / 2`? The answer
can be either `1` or `4` depending on the associativity of the division
operator. If it is left associative, then this expressions is interpreted as
`(8 / 4) / 2` and the result is `1`. If it is right associative, this
expression is interpreted as `8 / (4 / 2)` and the result is `4`.

Try to guess which result our current implementation gives before trying it
out. Once you have verified the current behaviour, continue reading.

### 8.1. Understanding the current implementation

Here is a diagram showing how our current parser processes the expression
`8 / 4 / 2`:

<p align="center">
  <a href="tutorial_diag9.png"><img src="tutorial_diag9.png" style="width:70%" /></a>
</p>

It takes the first number, `8`, divides it by the second one, `4` and then it
divides the result with the third one, `2`. This means, that in our current
implementation, division is left associative: `8 / 4 / 2` means `(8 / 4) / 2`.

Another thing to note is that the initial value is `8` and the list of values
[`foldl`](foldl.html) iterates over is "`/ 4`", "`/ 2`".

### 8.2. Folding in reverse order

[`foldl`](foldl.html) applies a parser repeatedly and iterates over the parsing
results from _left_ to right. (This is where the `l` in the name comes from).
Metaparse provides another folding parser combinator, [`foldr`](foldr.html). It
applies a parser on the input as well but it iterates from _right_ to left over
the results.

Similarly to [`foldlp`](foldlp.html), Metaparse provides [`foldrp`](foldrp.html)
as well. A major difference between the two ([`foldlp`](foldlp.html) and
[`foldrp`](foldrp.html)) solutions is that while [`foldlp`](foldlp.html) treats
the _first_ number as a special one, [`foldrp`](foldrp.html) treats the _last_
number as a special one. This might sound strange, but think about it: if you
want to summarise the elements from right to left, your starting value should be
the last element, not the first one, as the first one is the one you visit last.

Due to the above difference [`foldrp`](foldrp.html) is not a drop-in replacement
of [`foldlp`](foldlp.html). While the list of values [`foldl`](foldl.html) was
iterating over is "`8`", "`/ 4`", "`/ 2`", the list of values [`foldlr`](
foldr.html) has to iterate over is "`2`", "`4 /`", "`8 /`".

This means that the function we use to _"add"_ a new value to the already
evaluated part of the expression (this has been `binary_op` so far) has to be
prepared for taking the next operator and operand in a reverse order (eg. by
taking "`4 /`" instead of "`/ 4`"). We write another [metafunction](
metafunction.html) for this purpose:

```cpp
> template <class S, class Item> \
...> struct reverse_binary_op : \
...>   eval_binary_op< \
...>     typename boost::mpl::at_c<Item, 0>::type, \
...>     boost::mpl::at_c<Item, 1>::type::value, \
...>     S \
...>   > \
...>   {};
```

There are multiple differences between `binary_op` and `reverse_binary_op`:

* The `Item` argument, which is a `vector` is expected to be
  `[operator, operand]` in `binary_op` and `[operand, operator]` in
  `reverse_binary_op`.
* Both versions use `eval_binary_op` to evaluate the subexpression, but
  `binary_op` treats `S`, the value representing the already evaluated part of
  the expression as the left operand, while `reverse_binary_op` treats it as the
  right operand. This is because in the first case we are going from left to
  right while in the second case we are going from right to left.

We need to include [`foldrp`](foldrp.html):

```cpp
> #include <mpllibs/metaparse/foldrp.hpp>
```

We can rewrite `mult_exp` using [`foldrp`](foldrp.html):

```cpp
> using mult_exp3 = \
...> foldrp< \
...>   sequence<int_token, one_of<times_token, divides_token>>, /* The parser applied repeatedly */ \
...>   int_token, /* The parser parsing the last number */ \
...>   boost::mpl::quote2<reverse_binary_op> /* The function called for every result */ \
...>                                         /* of applying the above parser */ \
...> >;
```

It is almost the same as `mult_exp2`, but ...

* ... the parser applied repeatedly parses `<number> <operator>` elements
  instead of `<operator> <number>` elements (what `mult_exp2` did).
* ... this version uses `reverse_binary_op` instead of `binary_op` as the
  function that is called for every result of applying the above parser.

We can create a new version of `exp_parser` that uses `mult_exp3` instead of
`mult_exp2`:

```cpp
> using exp_parser17 = \
...> build_parser< \
...>   foldlp< \
...>     sequence<one_of<plus_token, minus_token>, mult_exp3>, \
...>     mult_exp3, \
...>     boost::mpl::quote2<binary_op> \
...>   > \
...> >;
```

The only difference between `exp_parser17` and the previous version,
`exp_parser16` is that it uses the updated version of `mult_exp`. Let's try this
parser out:

```cpp
> exp_parser17::apply<MPLLIBS_STRING("8 / 4 / 2")>::type
mpl_::integral_c<int, 4>
```

This version of the parser gives _the other_ possible result. The one you get
when division is right associative, which means that the above expression is
evaluated as `8 / (4 / 2)`. Here is a diagram showing how the
[`foldrp`](foldrp.html)-based solution works:

<p align="center">
  <a href="tutorial_diag10.png"><img src="tutorial_diag10.png" style="width:70%" /></a>
</p>

To make it easier to compare the two solutions, here is a diagram showing the
two approaches side-by-side:

<p align="center">
  <a href="tutorial_diag11.png"><img src="tutorial_diag11.png" style="width:100%" /></a>
</p>

As we have seen, the associativity of the operators can be controlled by
choosing between folding solutions. The folding solutions going from left to
right implement left associativity, while the solutions going from right to left
implement right associativity.

> Note that folding solutions going from left to right is implemented in a more
> efficient way than folding from right to left. Therefore when both solutions
> can be used you should prefer folding from left to right.

## 9. Dealing with unary operators

Our calculator language provides no direct support for negative numbers. To get
a negative number, we need to do a subtraction. For example to get the number
`-13` we need to evaluate the expression `0 - 13`.

We will implement `-` as an unary operator. Therefore the expression `-13` won't
be a _negative number_. It will be the unary `-` operator applied on the number
`13`.

Since `-` is an operator, it might be used multiple times. So the expression
`---13` is also valid and gives the same result as `-13`. This means that any
number of `-` symbols are valid before a number.

Our parser can be extended to support the unary `-` operator by adding a new
layer to the list of precedence layers. This should have the lowest precedence,
which means that we should use this new layer where we have been using
`int_token`. Let's write a new parser:

```cpp
> #include <boost/mpl/negate.hpp>
> using unary_exp1 = \
...> foldrp< \
...>   minus_token, \
...>   int_token, \
...>   boost::mpl::lambda<boost::mpl::negate<boost::mpl::_1>>::type \
...> >;
```

We had to include `<boost/mpl/negate.hpp>` to get a [metafunction](
metafunction.html) we can negate a value with.

`unary_exp1` is implemented with right to left folding: it starts from the
number (parsed by `int_token`) and processes the `-` symbols one by one. The
function to be called for each `-` symbol is a lambda expression that negates
the number. So the number is negated for every `-` symbol.

We can implement a new version of `mult_exp` and `exp_parser`. They are the same
as `mult_exp2` and `exp_parser16`. The only difference is that they (directly
only `exp_parser18`) use `unary_exp1` instead of `int_token`.

```cpp
> using mult_exp4 = \
...> foldlp< \
...>   sequence<one_of<times_token, divides_token>, unary_exp1>, \
...>   unary_exp1, \
...>   boost::mpl::quote2<binary_op> \
...> >;
> using exp_parser18 = \
...> build_parser< \
...>   foldlp< \
...>     sequence<one_of<plus_token, minus_token>, mult_exp4>, \
...>     mult_exp4, \
...>     boost::mpl::quote2<binary_op> \
...>   > \
...> >;
```

Let's try these new parsers out:

```cpp
> exp_parser18::apply<MPLLIBS_STRING("---13")>::type                                                  
mpl_::integral_c<int, -13>
> exp_parser18::apply<MPLLIBS_STRING("13")>::type                                                     
mpl_::integral_c<int, 13>
```

It can deal with negative numbers correctly.

## 10. Dealing with parens

Our parsers already support the precedence of the different operators. Let's add
support for parens as well, so users can override the precedence rules when they
need to.

We can add a new parser for parsing (and evaluating) expressions in parens.
First we introduce tokens for parsing the `(` and `)` symbols:

```cpp
> using lparen_token = token<lit_c<'('>>;
> using rparen_token = token<lit_c<')'>>;
```

A paren can contain an expression with any operators in it, so we add a parser
for parsing (and evaluating) an expression containing operators of the highest
precedence:

```cpp
> using plus_exp1 = \
...> foldlp< \
...>   sequence<one_of<plus_token, minus_token>, mult_exp4>, \
...>   mult_exp4, \
...>   boost::mpl::quote2<binary_op> \
...> >;
```

This was just a refactoring of our last parser for the calculator language. We
can build the parser for our calculator language by using
[`build_parser`](build_parser.html)`<plus_exp1>` now. Let's write a parser for a
paren expression:

```cpp
> using paren_exp1 = sequence<lparen_token, plus_exp1, rparen_token>;
```

This definition parses a left paren, then a complete expression followed by a
right paren. The result of parsing a paren expression is a `vector` of three
elements: the `(` character, the value of the expression and the `)` character.
We only need the value of the expression, which is the middle element. We could
wrap the whole thing with a [`transform`](transform.html) that gets the middle
element and throws the rest away, but we don't need to. This is such a common
pattern, that Metaparse provides [`middle_of`](middle_of.html) for this:

```cpp
> #include <mpllibs/metaparse/middle_of.hpp>
> using paren_exp2 = middle_of<lparen_token, plus_exp1, rparen_token>;
```

This implementation is almost the same as `paren_exp1`. The difference is that
the result of parsing will be the value of the wrapped expression (the result of
the `plus_exp1` parser).

Let's define a parser for a primary expression which is either a number or an
expression in parens:

```cpp
> using primary_exp1 = one_of<int_token, paren_exp2>;
```

This parser accepts either a number using `int_token` or an expression in parens
using `paren_exp1`.

Everywhere, where one can write a number (parsed by `int_token`), one can write
a complete expression in parens as well. Our current parser implementation
parses `int_token`s in `unary_exp`, therefore we need to change that to use
`primary_exp` instead of `int_token`.

There is a problem here: this makes the definitions of our parsers _recursive_.
Think about it:

* `plus_exp` uses `mult_exp`
* `mult_exp` uses `unary_exp`
* `unary_exp` uses `primary_exp`
* `primary_exp` uses `paren_exp`
* `paren_exp` uses `plus_exp`

> Since we are versioning the different parser implementations in Metashell
> (`paren_exp1`, `paren_exp2`, etc) you might try to define these recursive
> parsers and it might seem to work for the first time. In that case, when you
> later try creating a parser as part of a library (save your Metashell
> environment to a file or re-implement the important/successful elements) you
> face this issue.

We have been using type aliases (`typedef` and `using`) for defining the
parsers. We can do it as long as their definition is not recursive. We can not
refer to a type alias until we have defined it and type aliases can not be
forward declared, so we can't find a point in the recursive cycle where we could
start defining things.

A solution for this is making one of the parsers a new class instead of a type
alias. Classes can be forward declared, therefore we can declare the class,
implement the rest of the parsers as they can refer to that class and then
define the class at the end.

Let's make `plus_exp` a class. So as a first step, let's forward declare it:

```cpp
> struct plus_exp2;
```

Now we can write the rest of the parsers and they can refer to `plus_exp2`:

```cpp
> using paren_exp3 = middle_of<lparen_token, plus_exp2, rparen_token>;
> using primary_exp2 = one_of<int_token, paren_exp2>;
> using unary_exp2 = \
...> foldrp< \
...>   minus_token, \
...>   primary_exp2, \
...>   boost::mpl::lambda<boost::mpl::negate<boost::mpl::_1>>::type \
...> >;
> using mult_exp5 = \
...> foldlp< \
...>   sequence<one_of<times_token, divides_token>, unary_exp2>, \
...>   unary_exp2, \
...>   boost::mpl::quote2<binary_op> \
...> >;
```

There is nothing new in the definition of these parsers. They build up the
hierarchy we have worked out in the earlier sections of this tutorial. The only
element missing is `plus_exp2`:

```cpp
> struct plus_exp2 : \
...> foldlp< \
...>   sequence<one_of<plus_token, minus_token>, mult_exp5>, \
...>   mult_exp5, \
...>   boost::mpl::quote2<binary_op> \
...> > {};
```

This definition makes use of inheritance instead of type aliasing. Now we can
write the parser for the calculator that supports parens as well:

```cpp
> using exp_parser19 = build_parser<plus_exp2>;
```

Let's try this parser out:

```cpp
> exp_parser19::apply<MPLLIBS_STRING("(1 + 2) * 3")>::type
mpl_::integral_c<int, 9>
```

Our parser accepts and can deal with parens in the expressions.

## 11. Dealing with invalid input

So far we have been focusing on parsing valid user input. However, users of our
parsers will make mistakes and we should help them finding the source of the
problem. And we should make this process not too painful.

The major difficulty in error reporting is that we have no direct way of showing
error messages to the user. The parsers are template metaprograms. When they
detect that the input is invalid, they can make the compilation fail and the
compiler (running the metaprogram) display an error message. What we can do is
making those error messages short and contain all information about the parsing
error. We should make it easy to find this information in whatever the compiler
displays.

So let's try to parse some invalid expression and let's see what happens:

```cpp
> exp_parser19::apply<MPLLIBS_STRING("hello")>::type
<< compilation error >>
```

You will get a lot (if you have seen error messages coming from template
metaprograms you know: this is _not_ a lot.) of error messages. Take a closer
look. It contains this:

```cpp
x__________________PARSING_FAILED__________________x<
  1, 1,
  mpllibs::metaparse::v2::error::literal_expected<'('>
>
```

You can see a formatted version above. There are no line breaks in the real
output. This is relatively easy to spot (thanks to the `____________` part) and
contains answers to the main questions one has when parsing fails:

* _where_ is the error? It is column `1` in line `1` (inside [`MPLLIBS_STRING`](
  MPLLIBS_STRING.html)). This is the `1, 1` part.
* _what_ is the problem? `literal_expected<'('>`. This is a bit misleading, as
  it contains only a part of the problem. An open paren is not the only
  acceptable token here, a number would also be fine. This misleading error
  message is _our_ fault: _we_ (the parser authors) need to make the parsing
  errors more descriptive.

### 11.1. Improving the error messages

So how can we improve the error messages? Let's look at what went wrong in the
previous case:

* The input was `hello`.
* `plus_exp2` tried to parse it.
* `plus_exp2` tried to parse it using `mult_exp5` (assuming that this is the
  initial `mult_exp` in the list of `+`/`-` separated `mult_exp`s).
* so `mult_exp5` tried to parse it.
* `mult_exp5` tried to parse it using `unary_exp2` (assuming that this is the
  initial `unary_exp` in the list of `*`/`/` separated `unary_exp`s).
* so `unary_exp2` tried to parse it.
* `unary_exp2` parsed all of the `-` symbols using `minus_token`. There were
  none of them (the input started with an `h` character).
* so `unary_exp2` tried to parse it using `primary_exp2`.
* `primary_exp2` is: [`one_of`](one_of.html)`<int_token, paren_exp2>`. It tried
  parsing the input with `int_token` (which failed) and then with `paren_exp2`
  (which failed as well). So [`one_of`](one_of.html) could not parse the input
  with any of the choices and therefore it failed as well. In such situations
  `one_of` checks which parser made the most progress (consumed the most
  characters of the input) before failing and assumes, that that is the parser
  the user intended to use, thus it returns the error message coming from that
  parser. In this example none of the parsers could make any progress, in which
  case `one_of` returns the error coming from the last parser in the list. This
  was `paren_exp2`, and it expects the expression to start with an open paren.
  This is where the error message came from. The rest of the layers did not
  change or improve this error message so this was the error message displayed
  to the user.

We, the parser authors know: we expect a primary expression there. When
[`one_of`](one_of.html) fails, it means that none was found.

### 11.2. Defining custom errors

To be able to return custom error messages (like `missing_primary_expression`)
to the user, we need to define those error messages first. The error messages
are represented by classes with some requriements:

* It should have a static method called `get_value()` returning a `std::string`
  containing the description of the error.
* It should be a [template metaprogramming value](metaprogramming_value.html).

These classes are called [parsing error message](parsing_error_message.html)s.
To make it easy to implement such classes and to make it difficult (if not
impossible) to forget to fulfill a requirement, Metaparse provides a macro for
defining these classes. To get this macro, include the following header:

```cpp
> #include <mpllibs/metaparse/define_error.hpp>
```

Let's define the [parsing error message](parsing_error_message.html):

```cpp
> MPLLIBS_DEFINE_ERROR(missing_primary_expression, "Missing primary expression");
```

This defines a class called `missing_primary_expression` representing this error
message. What we need to do is making our parser return this error message when
[`one_of`](one_of.html) fails.

Let's define `plus_exp` and `paren_exp` first. Their definition does not change:

```cpp
> struct plus_exp3;
> using paren_exp4 = middle_of<lparen_token, plus_exp3, rparen_token>;
```

When the input contains no number (parsed by `int_token`) and no paren
expression (parsed by `paren_exp4`), we should return the
`missing_primary_expression` error message. We can do it by adding a third
parser to `one_of<int_token, paren_exp4, ...>` which always fails with this
error message. Metaparse provides [`fail`](fail.html) for this:

```cpp
> #include <mpllibs/metaparse/fail.hpp>
```

Now we can define the `primary_exp` parser using it:

```cpp
> using primary_exp3 = one_of<int_token, paren_exp4, fail<missing_primary_expression>>;
```

It adds [`fail`](fail.html)`<missing_primary_expression>` to `one_of` as the
last element. Therefore if none of the "real" cases parse the input _and_ none
of them makes any progress before failing, the error message will be
`missing_primary_expression`.

We need to define the rest of the parsers. Their definition is the same as
before:

```cpp
> using unary_exp3 = \
...> foldrp< \
...>   minus_token, \
...>   primary_exp3, \
...>   boost::mpl::lambda<boost::mpl::negate<boost::mpl::_1>>::type \
...> >;
> using mult_exp6 = \
...> foldlp< \
...>   sequence<one_of<times_token, divides_token>, unary_exp3>, \
...>   unary_exp3, \
...>   boost::mpl::quote2<binary_op> \
...> >;
> struct plus_exp3 : \
...> foldlp< \
...>   sequence<one_of<plus_token, minus_token>, mult_exp6>, \
...>   mult_exp6, \
...>   boost::mpl::quote2<binary_op> \
...> > {};
> using exp_parser20 = build_parser<plus_exp3>;
```

We can can try to give our new parser an invalid input:

```cpp
> exp_parser20::apply<MPLLIBS_STRING("hello")>::type
<< compilation error >>
..... x__________________PARSING_FAILED__________________x<1, 1, missing_primary_expression> ....
<< compilation error >>
```

The error message is now more specific to the calculator language. This covers
only one case, where the error messages can be improved. Other cases (eg.
missing closing parens, missing operators, etc) can be covered in a similar way.

## 12. Summary

This tutorial showed you how to build a parser for a calculator language. Now
that you understand how to do this, you should be able to use the same
techniques and building blocks presented here to build a parser for your own
language. You should start building the parser and once you face a problem (eg.
you need to add parens or you need better error messages) you can always return
to this tutorial and read the section showing you how to deal with those
situations.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2015.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)

