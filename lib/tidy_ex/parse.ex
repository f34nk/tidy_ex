defmodule TidyEx.Parse do
  @moduledoc false

  def parse([bin | rest]) do
    parse(bin) ++ parse(rest)
  end

  def parse([], _), do: []

  def parse(bin) when is_bitstring(bin) do
    TidyEx.Safe.Parse.parse(bin)
  end
end