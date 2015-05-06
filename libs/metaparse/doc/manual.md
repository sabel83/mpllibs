# mpllibs::metaparse user manual

## Table of contents

## What is a parser

See the [parser](parser.html) section of the [reference](refernce.html) for the
explanation of what a parser is.

### The input of the parsers

Parsers take a [`string`](string.html) as input, which represents a string
for template metaprograms. For example the string `"Hello World!"` can be
defined the following way:

```cpp
string<'H','e','l','l','o',' ','W','o','r','l','d','!'>
```

This syntax makes the input of the parsers difficult to read. Metaparse works
with compilers using C++98, but the input of the parsers has to be defined the
way it is described above.

Based on `constexpr`, a feature provided by C++11, Metaparse provides a macro,
[`MPLLIBS_STRING`](MPLLIBS_STRING.html) for defining strings:

```cpp
MPLLIBS_STRING("Hello World!")
```

This defines a [`string`](string.html) as well, however, it is easier to
read. The maximum length of the string that can be defined this way is limited,
however, this limit is configurable. It is specified by the 
`MPLLIBS_LIMIT_STRING_SIZE` macro.

### Source positions

A source position is described using a compile-time data structure. The
following functions can be used to query it:

* [`get_col`](get_col.html)
* [`get_line`](get_line.html)

The beginning of the input is [`start`](start.html) which requires
`<mpllibs/metaparse/start.hpp>` to be included.

### Error handling

An error is described using a compile-time data structure. It contains
information about the source position where the error was detected and some
[description](parsing_error_message.html) about the error.
[`debug_parsing_error`](debug_parsing_error.html) can be used to display the
error message. Metaparse provides the [`MPLLIBS_DEFINE_ERROR`](
MPLLIBS_DEFINE_ERROR.html) macro for defining simple [parsing error message](
parsing_error_message.html)s.

### Some examples of simple parsers

* A parser that parses nothing and always succeeds is
  [`return_`](return_.html).
* A parser that always fails is [`fail`](fail.html).
* A parser that parses one character and returns the parsed character as the
  result is [`one_char`](one_char.html).

## Combining parsers

Complex parsers can be built by combining simple parsers. The parser library
contains a number of parser combinators that build new parsers from already
existing ones.

For example
[`accept_when`](accept_when.html)`<Parser, Predicate, RejectErrorMsg>` is a
parser. It uses `Parser` to parse the input. When `Parser` rejects the input,
the combinator returns the error `Parser` failed with. When `Parser` is
successful, the combinator validates the result using `Predicate`. If the
predicate returns true, the combinator accepts the input, otherwise it generates
an error with the message `RejectErrorMsg`.

Having [`accept_when`](accept_when.html), [`one_char`](one_char.html) can be
used to build parsers that accept only digit characters, only whitespaces, etc.
For example [`digit`](digit.html) accepts only digit characters:

```cpp
typedef
  mpllibs::metaparse::accept_when<
    mpllibs::metaparse::one_char,
    mpllibs::metaparse::util::is_digit,
    mpllibs::metaparse::errors::digit_expected
  >
  digit;
```

### Sequence

The result of a successful parsing is some value and the remaining string that
was not parsed. The remaining string can be processed by another parser. The
parser library provides a parser combinator, [`sequence`](sequence.html),
that takes a number of parsers as arguments and builds a new parser from them
that:

* Parses the input using the first parser
* If parsing succeeds, it parses the remaining string with the second parser
* It continues applying the parsers in order as long as they succeed
* If all of them succeed, it returns the list of results
* If any of the parsers fails, the combinator fails as well and returns the
  error the first failing parser returned with

### Repetition

It is a common thing to parse a list of things of unknown length. As an example
let's start with something simple: the text is a list of numbers. For example:

```cpp
11 13 3 21
```

We want the result of parsing to be the sum of these values. Metaparse provides
the [`int_`](int.html) parser we can use to parse one of these numbers.
Metaparse provides the [`token`](token.html) combinator to consume the
whitespaces after the number. So the following parser parses one number and the
whitespaces after it:

```cpp
using int_token = token<int_>;
```

The result of parsing is a boxed integer value: the value of the parsed number.
For example parsing [`MPLLIBS_STRING`](MPLLIBS_STRING.html)`("13  ")` gives
`boost::mpl::int_<13>` as the result.

Our example input is a list of numbers. Each number can be parsed by
`int_token`:

<p align="center">
  <a href="any_diag0.png"><img src="any_diag0.png" style="width:70%" /></a>
</p>

This diagram shows how the repeated application of `int_token` can parse the
example input. Metaparse provides the [`any`](any.html) parser to easily
implement this. The result of parsing is a typelist: the list of the individual
numbers.

<p align="center">
  <a href="any_diag1.png"><img src="any_diag1.png" style="width:70%" /></a>
</p>

This diagram shows how [`any`](any.html)`<int_token>` works. It uses the
`int_token` parser repeatedly and builds a `boost::mpl::vector` from the results
it provides.

But we need the sum of these, so we need to summarise the result. We can do this
by wrapping our parser, [`any`](any.html)`<int_token>` with
[`transform`](transform.html). That gives us the opportunity to specify a
function transforming this typelist to some other value - the sum of the
elements in our case. Initially let's ignore how to summarise the elements in
the vector. Let's assume that it can be implemented by a lambda expression and
use `boost::mpl::lambda<...>::type` representing that lambda expression. Here is
an example using [`transform`](transform.html) and this lambda expression:

```cpp
using sum_parser =
  transform<
    any<int_token>,
    boost::mpl::lambda<...>::type
  >;
```

The  [`transform`](transform.html)`<>` parser combinator wraps the
[`any`](any.html)`<int_token>` to build the parser we need. Here is a diagram
showing how it works:

<p align="center">
  <a href="any_diag2.png"><img src="any_diag2.png" style="width:70%" /></a>
</p>

As the diagram shows, the
[`transform`](transform.html)`<`[`any`](any.html)`<int_token>, ...>` parser
parses the input using [`any`](any.html)`<int_token>` and then does some
processing on the result of parsing.

Let's implement the missing lambda expression that tells
[`transform`](transform.html) how to change the result coming from
[`any`](any.html)`<int_token>`. We can summarise the numbers in a typelist by
using Boost.MPL's `fold` or `accumulate`. Here is an example doing that:

```cpp
using sum_op = mpl::lambda<mpl::plus<mpl::_1, mpl::_2>>::type;

using sum_parser =
  transform<
    any<int_token>,
    mpl::lambda<
      mpl::fold<mpl::_1, mpl::int_<0>, sum_op>
    >::type
  >;
```

Here is an extended version of the above diagram showing what happens here:

<p align="center">
  <a href="any_diag3.png"><img src="any_diag3.png" style="width:70%" /></a>
</p>

This example parses the input, builds the list of numbers and then loops over it
and summarises the values. It starts with the second argument of `fold`,
`int_<0>` and adds every item of the list of numbers (which is the result of
the parser [`any`](any.html)`<int_token>`) one by one.

> Note that [`transform`](transform.html) wraps another parser,
> [`any`](any.html)`<int_token>` here. It parses the input with that parser,
> gets the result of that parsing and changes that result.
> [`transfrom`](transform.html) itself will be a parser returning that updated
> result.

#### Introducing foldl

It works, however, this is rather inefficient: it has a loop parsing the
integers one by one, building a typlist and then it loops over this typelist to
summarise the result. Using template metaprograms in your applications can have
a serious impact on the compiler's memory usage and the speed of the
compilation, therefore I recommend being careful with these things.

Metaparse offers more efficient ways of achieving the same result. You don't
need two loops: you can merge them together and add every number to your summary
right after parsing it. Metaparse offers the [`foldl`](foldl.html) for this.

With [`foldl`](foldl.html) you specify:

* the parser to parse the individual elements of the list
  (which is `int_token` in our example)
* the initial value used for folding (which is `int_<0>` in our example)
* the forward operation merging the sub-result we have so far and the value
  coming from the last application of the parser (this was `sum_op` in our
  example)

Our parser can be implemented this way:

```cpp
using better_sum_parser = foldl<int_token, mpl::int_<0>, sum_op>;
```

As you can see the implementation of the parser is more compact.
Here is a diagram showing what happens when you use this parser to parse some
input:

<p align="center">
  <a href="foldl_diag1.png"><img src="foldl_diag1.png" style="width:70%" /></a>
</p>

As you can see, not only the implementation of the parser is more compact, but
it achieves the same result by doing less as well. It parses the input by
applying `int_token` repeatedly, just like the previous solution. But it
produces the final result without buliding a typelist as an internal step. Here
is how it works internally:

<p align="center">
  <a href="foldl_diag2.png"><img src="foldl_diag2.png" style="width:70%" /></a>
</p>

It summarises the results of the repeated `int_token` application using
`sum_op`. This implementation is more efficient. It accepts an empty string as a
valid input: the sum of it is `0`. It may be good for you, in which case you are
done. If you don't wan to accept it, you can use [`foldl1`](foldl1.html) instead
of [`foldl`](foldl.html). This is the same, but it rejects empty input.
(Metaparse offers [`any1`](any1.html) as well if you choose the first approach
and would like to reject empty string)

#### Introducing foldr

> Note that if you are reading this manual for the first time, you probably want
> to skip this section and proceed with [Introducing
> foldlp](manual.html#introducing-foldlp)

You might have noticed that Metaparse offers [`foldr`](foldr.html) as well. The
difference between [`foldl`](foldl.html) and [`foldr`](foldr.html) is the
direction in which the results are summarised. (`l` stands for _from the Left_
and `r` stands for _from the Right_) Here is a diagram showing how
`better_sum_parser` works if it is implemented using [`foldr`](foldr.html):

<p align="center">
  <a href="foldr_diag1.png"><img src="foldr_diag1.png" style="width:70%" /></a>
</p>

As you can see this is very similar to using [`foldl`](foldl.html), but the
results coming out of the individual applications of `int_token` are summarised
in a right-to-left order. As `sum_op` is addition, it does not affect the end
result, but in other cases it might.

> Note that the implementation of [`foldl`](foldl.html) is more efficient than
> [`foldr`](foldr.html). Prefer [`foldl`](foldl.html) whenever possible.

As you might expect it, Metaparse offers [`foldr1`](foldr1.html) as well, which
folds from the right and rejects empty input.

#### Introducing foldlp

Let's change the grammar of our little language. Instead of a list of numbers,
let's expect numbers separated by a `+` symbol. Our example input becomes the
following:

```cpp
MPLLIBS_STRING("11 + 13 + 3 + 21")
```

Parsing it with [`foldl`](foldl.html) or [`any`](any.html) is difficult: there
has to be a `+` symbol before every element _except_ the first one. None of the
already introduced repetition constructs offer a way of treating the first
element in a different way.

If we forget about the first number for a moment, the rest of the input is
`"+ 13 + 3 + 21"`. This can easily be parsed by [`foldl`](foldl.html) (or
[`any`](any.html)):

```cpp
using plus_token = token<lit_c<'+'>>;
using plus_int = last_of<plus_token, int_token>;

using sum_parser2 = foldl<plus_int, int_<0>, sum_op>;
```

It uses `plus_int`, that is [`last_of`](last_of.html)`<plus_token, int_token>`
as the parser that is used repeatedly to get the numbers. It does the following:

* Uses `plus_token` to parse the `+` symbol and any whitespace that might follow
  it.
* Uses then `int_token` to parse the number
* Combines the above two with [`last_of`](last_of.html) to use both parsers in
  order and keep only the result of using the second one (the result of parsing
  the `+` symbol is thrown away - we don't care about it).

This way [`last_of`](last_of.html)`<plus_token, int_token>` returns the value of
the number as the result of parsing, just like our previous parser, `int_token`
did. Because of this, it can be used as a drop-in replacement of `int_token` in
the previous example and we get a parser for our updated language. Or at least
for all number except the first one.

This [`foldl`](foldl.html) can not parse the first element, because it expects a
`+` symbol before every number. You might think of making the `+` symbol
optional in the above approach - don't do that. It makes the parser accept
`"11 + 13 3 21"` as well as the `+` symbol is now optional _everywhere_.

What you could do is parsing the first element with `int_token`, the rest of
the elements with the above [`foldl`](foldl.html)-based solution and add the
result of the two. This is left as an exercise to the reader.

Metaparse offers [`foldlp`](foldlp.html) to implement this.
[`foldlp`](foldlp.html) is the same as [`foldl`](foldl.html). The difference is
that instead of an initial value to combine the list elements with it takes an
_initial parser_:

```cpp
using plus_token = token<lit_c<'+'>>;
using plus_int = last_of<plus_token, int_token>;

using sum_parser3 = foldlp<plus_int, int_token, sum_op>;
```

[`foldlp`](foldlp.html) starts with applying that initial parser and uses the
result it returns as the initial value for folding. It does the same as
[`foldl`](foldl.html) after that. The following diagram shows how it can be used
to parse a list of numbers separated by `+` symbols:

<p align="center">
  <a href="foldlp_diag1.png"><img src="foldlp_diag1.png" style="width:70%" /></a>
</p>

As the diagram shows, it start parsing the list of numbers with `int_token`,
uses its value as the starting value for folding (earlier approaches were using
the value `int_<0>` as this starting value). Then it parses all elements of the
list by using `plus_int` multiple times.

#### Introducing foldrp

> Note that if you are reading this manual for the first time, you probably want
> to skip this section and try creating some parsers using
> [`foldlp`](foldlp.html) instead.

[`foldlp`](foldlp.hpp) has its _from the right_ pair, [`foldrp`](foldrp.html).
It uses the same elements as [`foldlp`](foldlp.html) but in a different order.
Here is a parser for our example language implemented with
[`foldrp`](foldrp.html):

```cpp
using plus_token = token<lit_c<'+'>>;
using int_plus = first_of<int_token, plus_token>;

using sum_parser4 = foldrp<int_plus, int_token, sum_op>;
```

Note that it uses `int_plus` instead of `plus_int`. This is because the parser
the initial value for folding comes from is used after `int_plus` has parsed the
input as many times as it could. It might sound strange for the first time, but
the following diagram should help you understand how it works:

<p align="center">
  <a href="foldrp_diag1.png"><img src="foldrp_diag1.png" style="width:70%" /></a>
</p>

As you can see, it starts with the parser that is applied repeatedly on the
input, thus instead of parsing `plus_token int_token` repeatedly, we need to
parse `int_token plus_token` repeatedly. The last number is not followed by `+`,
thus `int_plus` fails to parse it and it stops the iteration.
[`foldrp`](foldrp.html) then uses the other parser, `int_token` to parse the
input. It succeeds and the result it returns is used as the starting value for
folding from the right.

> Note that as the above description also suggests, the implementation of
> [`foldlp`](foldlp.html) is more efficient than [`foldrp`](foldrp.html). Prefer
> [`foldlp`](foldlp.html) whenever possible.

#### Introducing foldlfp

Using a parser built with [`foldlp`](foldlp.html) we can parse the input when
the input is correct. However, it is not always the case. Consider the following
input for example:

```cpp
MPLLIBS_STRING("11 + 13 + 3 + 21 +")
```

This is an ivalid expression. However, if we parse it using the
`foldlp`](foldlp.html)-based parser presented earlier (`sum_parser3`), it
accepts the input and the result is `48`. This is because
[`foldlp`](foldlp.html) parses the input _as long as it can_. It parses the
first`int_token` (`11`) and then it starts parsing the `plus_int` elements
(`+ 13`, `+ 3`, `+ 21`). After parsing all of these, it tries to parse the
remaining `" +"` input using `plus_int` which fails and therefore
[`foldlp`](foldlp.html) stops after `+ 21`.

The problem is that the parser parses the longest sub-expression starting from
the beginning, that represents a valid expression. The rest is ignored. The
parser can be wrapped by [`entire_input`](entire_input.html) to make sure to
reject expressions with invalid extra characters at the end, however, that
won't make the error message useful. ([`entire_input`](entire_input.html) can
only tell the author of the invalid expression that after `+ 21` is something
wrong).

Metaparse provides [`foldlfp`](foldlfp.html), which does the same as
[`foldlp`](foldlp.html), except that once no further repetitions are found, it
checks _where_ the repeated parser (in our example `plus_int`) fails. When it
can make any progress (eg. it finds a `+` symbol), then
[`foldlfp`](foldlfp.html) assumes, that the expression's author intended to make
the repetition longer, but made a mistake and propagates the error message
coming from that last broken expression.

<p align="center">
  <a href="foldlfp_diag1.png"><img src="foldlfp_diag1.png" style="width:70%" /></a>
</p>

The above diagram shows how [`foldlfp`](foldlfp.html) parses the example
invalid input and how it fails. This can be used for better error reporting
from the parsers.

Other folding parsers also have their `f` version. (eg. [`foldrf`](foldrf.html),
[`foldlf1`](foldlf1.html), etc).

#### Finding the right folding parser combinator

As you might have noticed, there are a lot of different folding parser
combinators. To help you find the right one, the following naming convention is
used:

<p align="center">
  <a href="folds.png"><img src="folds.png" style="width:70%" /></a>
</p>

> Note that there is no `foldrfp`. The `p` version of the right-folding parsers
> applies the special parser, whose result is the initial value, after the
> repeated elements. Therefore, when the parser parsing one repeated element
> fails, `foldrp` would apply that special final parser instead of checking how
> the repeated element's parser failed.

### Grammars

Metaparse provides a way to define grammars in a syntax that resembles EBNF. The
[`grammar`](grammar.html) template can be used to define a grammar. It can be
used the following way:

```cpp
grammar<MPLLIBS_STRING("plus_exp")>
  ::import<MPLLIBS_STRING("int_token"), token<int_>>::type

  ::rule<MPLLIBS_STRING("ws ::= (' ' | '\n' | '\r' | '\t')*")>::type
  ::rule<MPLLIBS_STRING("plus_token ::= '+' ws"), front<_1>>::type
  ::rule<MPLLIBS_STRING("plus_exp ::= int_token (plus_token int_token)*"), plus_action>::type
```

The code above defines a parser from a grammar definition. The start symbol of
the grammar is `plus_exp`. The lines beginning with `::rule` define rules.
Rules optionally have a semantic action, which is a metafunction class that
transforms the result of parsing after the rule has been applied.
Existing parsers can be bound to names and be used in the rules by importing
them. Lines beginning with `::import` bind existing parsers to names.

The result of a grammar definition is a parser which can be given to other
parser combinators or be used directly. Given that grammars can import existing
parsers and build new ones, they are parser combinators as well.

## Parsing based on `constexpr`

Metaparse is based on template metaprogramming, however, C++11 provides
`constexpr`, which can be used for parsing at compile-time as well. While
implementing parsers based on `constexpr` is easier for a C++ developer, since
its syntax resembles the regular syntax of the language, the result of parsing
has to be a `constexpr` value. Parsers based on template metaprogramming can
build types as the result of parsing. These types may be boxed `constexpr`
values but can be metafunction classes, classes with static functions which can
be called at runtime, etc.

When a parser built with Metaparse needs a sub-parser for processing a part of
the input text and generating a `constexpr` value as the result of parsing, one
can implement the sub-parser based on `constexpr` functions. Metaparse
can be integrated with them and lift their results into C++ template
metaprogramming. An example demonstrating this feature can be found among the
examples (`constexpr_parser`). This capability makes it possible to integrate
Metaparse with parsing libraries based on `constexpr`.

## Monadic parsing

Metaparse provides a parsing monad implementation based on Metamonad's monadic
framework. The overloads of `bind` and `return_` can be loaded by including
`mpllibs/metaparse/parser_monad.hpp`.

Monadic values are parsers. The monadic `return_` operation constructs a
`return_` parser. The arguments of the monadic `bind` are a parser `P` and a
function `F`, taking a value and buliding a parser. `bind` constructs the
following parser:

* It parses the input using `P`.
* When `P` fails, the error is propagated.
* When `P` succeeds, the result is passed to `F` and the remaining input is
  parsed using the parser returned by `F`.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)


