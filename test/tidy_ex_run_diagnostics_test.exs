defmodule TidyExRunDiagnosticsTest do
  use ExUnit.Case
  doctest TidyEx

  # test "can run diagnostics an empty string" do
  #   result = TidyEx.run_diagnostics("")
  #   assert result == ""
  # end

  # test "can run diagnostics invalud html" do
  #   result = TidyEx.run_diagnostics("<pp>Hello World</p>")
  #   assert result == "line 1 column 1 - Error: <pp> is not recognized!\nThis document has errors that must be fixed before\nusing HTML Tidy to generate a tidied up version."
  # end
end
