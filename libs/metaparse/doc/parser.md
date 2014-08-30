# Parser

A _parser_ is a [template metafunction class](metafunction_class.html) that
takes the following arguments:

* a suffix of the input text, a [`string`](string.html)
* a [source position](source_position.html) describing at which position of the
  entire input text the suffix begins at

The function parses a prefix of the input string.
When the parsing is successful, it returns an [`accept`](accept.html) value.
When there is a parsing error, the parser returns a [`reject`](reject.html)
value. The [`is_error`](is_error.html) metafunction can be used to determine
about the result of a parser if it succeeded or failed.

The documentation refers often to the _result of a parser_. This means that the
parser accepts the input and refers to what `get_result` returns for the value
returned by the parser.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

