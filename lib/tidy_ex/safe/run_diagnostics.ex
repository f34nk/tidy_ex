defmodule TidyEx.Safe.RunDiagnostics do
  @moduledoc false

  def run_diagnostics(bin) do
    case Nodex.Cnode.call(TidyEx.Safe.Cnode, {:run_diagnostics, bin <> "\0", TidyEx.options()}) do
      {:ok, {:run_diagnostics, result}} -> TidyEx.resolve(result)
      _ -> {:error, bin}
    end
  end
end
