# parser monad

This monad can be used for building parsers. Monadic values are parsers.

## General information

* header: `<mpllibs/metaparse/parser_monad.hpp>`
* tag of monad: [`parser_tag`](parser_tag.html).
* `return`'s logic: construct a [`return_`](return_.html) parser
* `bind`'s logic:
  Construct a parser parsing the input with the first argument of `bind`. When
  parsing fails, the error is propagated. When it succeeds, the result is passed
  to the second argument of `bind`, which returns a new parser. The remaining
  input is parsed using this parser.
* `fail`'s logic: wrap the argument of `fail` with the [`fail`](fail.html)
  parser

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


