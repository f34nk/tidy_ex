defmodule TidyEx.Safe.CleanAndRepair do
  @moduledoc false

  def clean_and_repair(bin) do
    case Nodex.Cnode.call(TidyEx.Safe.Cnode, {:clean_and_repair, bin <> "\0", TidyEx.options()}) do
      {:ok, {:clean_and_repair, result}} -> TidyEx.resolve(result)
      _ -> {:error, bin}
    end
  end
end
