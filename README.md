# *Under development...*

[![Build status](https://travis-ci.org/f34nk/tidy_ex.svg?branch=master)](https://travis-ci.org/f34nk/tidy_ex)
[![ModestEx version](https://img.shields.io/hexpm/v/tidy_ex.svg)](https://hex.pm/packages/tidy_ex)
[![Hex.pm](https://img.shields.io/hexpm/dt/tidy_ex.svg)](https://hex.pm/packages/tidy_ex)

![Broom by faisalovers from the Noun Project](https://github.com/f34nk/tidy_ex/blob/master/tidy_ex_icon.png)

# TidyEx

TidyEx corrects and cleans up HTML content by fixing markup errors.

Elixir/Erlang bindings for htacg's **tidy-html5**

>The granddaddy of HTML tools, with support for modern standards [http://www.html-tidy.org](http://www.html-tidy.org)

- [tidy-html5](https://github.com/htacg/tidy-html5)

The binding is implemented as a **C-Node** following the excellent example in Overbryd's package **nodex**. If you want to learn how to set up bindings to C/C++, you should definitely check it out.

- [nodex](https://github.com/Overbryd/nodex)
  - distributed Elixir
  - save binding with C-Nodes

>C-Nodes are external os-processes that communicate with the Erlang VM through erlang messaging. That way you can implement native code and call into it from Elixir in a safe predictable way. The Erlang VM stays unaffected by crashes of the external process.

## Example
For more examples please checkout [tests](https://github.com/f34nk/tidy_ex/tree/master/test).
```elixir
test "can parse broken html" do
  result = TidyEx.parse("<div>Hello<span>World")
  assert result == "<div>Hello<span>World</span></div>"
end
```

## Installation

Not yet published

## Target dependencies
```
cmake 3.x
erlang-dev
erlang-xmerl
erlang-parsetools
```
## Compile and test
```
mix deps.get
mix compile
mix test
```
## Cloning
```
git clone git@github.com:f34nk/tidy_ex.git
cd tidy_ex
```
All binding targets are added as submodules in the `target/` folder.
```
git submodule update --init --recursive --remote
mix deps.get
mix compile
mix test
mix test.target
```
Cleanup
```
mix clean
```
## Roadmap

See [CHANGELOG](https://github.com/f34nk/tidy_ex/blob/master/CHANGELOG.md).

- [ ] Bindings
  - [x] Call as C-Node
  - [ ] Call as dirty-nif
- [ ] Tests
  - [ ] Call as C-Node
  - [ ] Call as dirty-nif
  - [ ] Target tests
  - [ ] Feature tests
  - [ ] Package test
- [ ] Features
  - [x] Set tidy-html5 options
  - [x] Serialize any string with valid or broken html
  - [ ] Clean and repair
  - [ ] Run diagnostics
- [ ] Documentation
- [ ] Publish as hex package

## Icon Credit

Broom by faisalovers from the Noun Project