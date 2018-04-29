defmodule TidyExParseTest do
  use ExUnit.Case
  doctest TidyEx

  test "can parse an empty string" do
    result = TidyEx.parse("")
    assert result == ""
  end

  test "can parse broken html" do
    result = TidyEx.parse("<div>Hello<span>World")
    assert result == "<div>Hello<span>World</span></div>"
  end
end
