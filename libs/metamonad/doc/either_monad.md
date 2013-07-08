# either monad

This is the C++ template metaprogramming equivalent of Haskell's Either monad.
The purpose of this monad is to provide basic error handling for pure code. The
either monad is similar to the [exception monad](exception_monad.html), but it
is more difficult to use because of treating every non-exception value as a
result instead of introducing a new type, `left` for it. Compile-time exception
handling is built on top of the exception monad.

Monadic values consist of `left<T>` and `right<T>`, where `T` is a nullary
metafunction. Both `left` and `right` evaluate its argument. `left` represents
error, `right` represents normal result.

## General information

* header: `<mpllibs/metamonad/either.hpp>`
* tag of monad: `either_tag`
* `return`'s logic: pass the argument to `right`
* `bind`'s logic: when the first argument is `left`, `bind` returns it as it is.
  When it is `right`, `bind` passes the wrapped value to the continuation, the
  last argument of `bind`.
* `fail`'s logic: wrap its argument with `left`

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](.reference.html)


