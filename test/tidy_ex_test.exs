defmodule TidyExTest do
  use ExUnit.Case
  doctest TidyEx

  test "greets the world" do
    assert TidyEx.hello() == :world
  end
end
