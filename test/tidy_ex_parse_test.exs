defmodule TidyExParseTest do
  use ExUnit.Case
  doctest TidyEx

  # use only: "capture_io(fun)" to silence the IO output (so only assert the return value)
  import ExUnit.CaptureIO

  # test "can parse an empty string" do
  #   result = TidyEx.parse("")
  #   assert result == ""
  # end

  test "can parse broken html" do
    result = TidyEx.parse("<div>Hello<span>World")
    assert result == "<div>Hello<span>World</span></div>"
  end

  # test "capture IO" do
  #   fun = fn ->
  #     IO.puts TidyEx.parse("<div>Hello<span>World")
  #   end
  #   IO.puts capture_io(fun)
  # end

end
