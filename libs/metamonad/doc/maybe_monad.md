# maybe monad

This is the C++ template metaprogramming equivalent of Haskell's Maybe monad.
The purpose of this monad is to provide basic error handling for pure code.
Note that metamonad offers a higher level error handling monad, the
[exception monad](exception_monad.html).

Monadic values comprise `nothing` and `just<T>`, where `T` is a nullary
metafunction. `just` evaluates its argument. `nothing` represents error,
`just` represents normal result.

## General information

* header: `<mpllibs/metamonad/maybe.hpp>`
* tag of monad: `maybe_tag<T>` where `T` is the tag of the value wrapped by
  `just`.
* `return`'s logic: pass the argument to `just`
* `bind`'s logic: when the first argument is `nothing`, `bind` returns it as it
  is. When it is `just`, `bind` passes the wrapped value to the continuation,
  the last argument of `bind`.
* `fail`'s logic: return `nothing`

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


