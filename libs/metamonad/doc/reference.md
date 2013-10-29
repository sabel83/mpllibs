# mpllibs::metamonad reference

## Table of contents

## Language elements

### Syntax

* [eval_syntax](eval_syntax.html)
* [make_syntax](make_syntax.html)
* [name](name.html)
* [syntax](syntax.html)
* [var](var.html)

### Control structure

* [case_](case_.html)
* [eval_case](eval_case.html)
* [if_](if_.html)

### Pattern matching

* [match](match.html)
* [match_c](match_c.html)

### Let expression

* [eval_let](eval_let.html)
* [eval_let_c](eval_let_c.html)
* [eval_letrec](eval_letrec.html)
* [eval_letrec_c](eval_letrec_c.html)
* [eval_match_let](eval_match_let.html)
* [eval_match_let_c](eval_match_let_c.html)
* [eval_multi_let](eval_multi_let.html)
* [eval_multi_let_c](eval_multi_let_c.html)
* [let](let.html)
* [let_c](let_c.html)
* [letrec](letrec.html)
* [letrec_c](letrec_c.html)
* [match_let](match_let.html)
* [match_let_c](match_let_c.html)
* [multi_let](multi_let.html)
* [multi_let_c](multi_let_c.html)

### Lazy evaluation

* [already_lazy](already_lazy.html)
* [eval](eval.html)
* [lazy](lazy.html)
* [lazy_argument](lazy_argument.html)
* [lazy_protect_args](lazy_protect_args.html)

### Lambda expression

* [apply](apply.html)
* [lambda](lambda.html)
* [lambda_c](lambda_c.html)

### Typeclass

* [MPLLIBS_TYPECLASS_EXPECT](MPLLIBS_TYPECLASS_EXPECT.html)

### Do notation

* [do_](do_.html)
* [do_c](do_c.html)
* [set](set.html)
* [do_return](do_return.html)

### Monadic conversion

* [already_monadic](already_monadic.html)
* [make_monadic](make_monadic.html)
* [make_monadic_c](make_monadic_c.html)

### Compile-time exception

* [catch_all](catch_all.html)
* [catch_just](catch_just.html)
* [exception](exception.html)
* [is_exception](is_exception.html)
* [try_](try_.html)
* [try_c](try_c.html)

### Algebraic data-type

* [MPLLIBS_DATA](MPLLIBS_DATA.html)

### Metafunction definition

* [MPLLIBS_DEFINE_TAG_DISPATCHING_METAFUNCTION](
    MPLLIBS_DEFINE_TD_METAFUNCTION.html
  )
* [MPLLIBS_LAZY_METAFUNCTION](MPLLIBS_LAZY_METAFUNCTION.html)
* [MPLLIBS_METAFUNCTION](MPLLIBS_METAFUNCTION.html)
* [calculated_value](calculated_value.html)
* [make_tmp_value](make_tmp_value.html)
* [returns](returns.html)
* [tmp_tag](tmp_tag.html)
* [tmp_value](tmp_value.html)

## Data types

### Boxing

* [box](box.html)
* [eval_guard](eval_guard.html)
* [unbox](unbox.html)

### Either

* [either](either.html)

### Maybe

* [maybe](maybe.html)

### Pair

* [first](first.html)
* [pair](pair.html)
* [second](second.html)

### Tag

* [tag_tag](tag_tag.html)
* [overloading_error_tag](overloading_error_tag.html)

### Sequences

* [concat](concat.html)
* [concat_map](concat_map.html)

## Typeclasses

### Monoid

* [mappend](mappend.html)
* [mconcat](mconcat.html)
* [mempty](mempty.html)
* [monoid](monoid.html)

#### Instances of Monoid

* [list monoid](list_monoid.html)
* [maybe monoid](maybe_monoid.html)

### Monad

* [bind_](bind_.html)
* [bind](bind.html)
* [fail](fail.html)
* [monad](monad.html)
* [return_](return_.html)

#### Instances of Monad

* [either monad](either_monad.html)
* [exception monad](exception_monad.html)
* [list monad](list_monad.html)
* [maybe monad](maybe_monad.html)
* [reader monad](reader_monad.html)
* [state monad](state_monad.html)
* [writer monad](writer_monad.html)

### MonadPlus

* [monad_plus](monad_plus.html)
* [mplus](mplus.html)
* [mzero](mzero.html)

#### Instances of MonadPlus

* [list monad plus](list_monad_plus.html)
* [maybe monad plus](maybe_monad_plus.html)

## Miscellaneous

* [fail_with_type](fail_with_type.html)
* [guard](guard.html)
* [has_get_value](has_get_value.html)
* [has_value](has_value.html)
* [instantiate](instantiate.html)
* [is_same](is_same.html)
* [is_tag](is_tag.html)
* [value_to_stream](value_to_stream.html)

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)


