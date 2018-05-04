defmodule TidyEx.Safe.Parse do
  @moduledoc false

  def parse(bin) do
    case Nodex.Cnode.call(TidyEx.Safe.Cnode, {:parse, bin <> "\0", TidyEx.options()}) do
      {:ok, {:parse, result}} -> TidyEx.resolve(result)
      _ -> {:error, bin}
    end
  end
end
