defmodule TidyEx.CleanAndRepair do
  @moduledoc false

  def clean_and_repair([bin | rest]) do
    clean_and_repair(bin) ++ clean_and_repair(rest)
  end

  def clean_and_repair([], _), do: []

  def clean_and_repair(bin) when is_bitstring(bin) do
    TidyEx.Safe.CleanAndRepair.clean_and_repair(bin)
  end
end