defmodule TidyHtml5Test do
  use ExUnit.Case
  doctest TidyEx

  test "sdasd" do
    content = File.read!("target/tidy-html5-tests/cases/testbase/case-1002509.html")
    |> IO.inspect

    # result = TidyEx.parse(content)
    # result = TidyEx.clean_and_repair(content)
    # result = TidyEx.run_diagnostics(content)
    result = TidyEx.run_diagnostics("<div>Hello<span>World")
    |> IO.inspect
    # assert result == ""

  end
end