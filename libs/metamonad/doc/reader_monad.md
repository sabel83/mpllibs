# reader monad

This is the C++ template metaprogramming equivalent of Haskell's Reader monad.
Monadic values are metafunctions classes taking the state as argument and
returning some value. The purpose of this monad is to combine such functions.

## General information

* header: `<mpllibs/metamonad/reader.hpp>`
* tag of monad: [`reader_tag`](reader_tag.html)
* `return`'s logic: construct a constant function, returning always return's
  argument regardless of the state
* `bind`'s logic: construct a function that gets a value by passing the state to
  bind's first argument (which is a function mapping state to some value). The
  resulting value is passed to bind's second argument as input to construct a
  new monadic value (a new function expecting a state). This new monadic value
  is the result of bind.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


