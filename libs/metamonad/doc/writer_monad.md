# writer monad

This is the C++ template metaprogramming equivalent of Haskell's Writer monad.
Monadic values are (value, state) pairs. The monadic actions take values as
input, they can only produce state. State is has to be a [monoid](monoid.html),
the states are appended to each other.

## General information

* header: `<mpllibs/metamonad/writer.hpp>`
* tag of monad: [`writer_tag`](writer_tag.html)`<M>`, where `M` is the tag of
  the state. `monoid<M>` is expected to be defined
* `return`'s logic: construct a pair of return's argument and the empty value of
  the state monoid
* `bind`'s logic: pass the value element of the (value, state) pairs to the
  monadic actions and append the states together

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


