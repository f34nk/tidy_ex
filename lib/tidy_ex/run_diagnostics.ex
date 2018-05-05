defmodule TidyEx.RunDiagnostics do
  @moduledoc false

  def run_diagnostics([bin | rest]) do
    run_diagnostics(bin) ++ run_diagnostics(rest)
  end

  def run_diagnostics([], _), do: []

  def run_diagnostics(bin) when is_bitstring(bin) do
    TidyEx.Safe.RunDiagnostics.run_diagnostics(bin)
  end
end