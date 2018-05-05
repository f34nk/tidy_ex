defmodule TidyEx do
  @moduledoc """
  Elixir binding to the granddaddy of HTML tools [http://www.html-tidy.org/](http://www.html-tidy.org/).
  TidyEx corrects and cleans up HTML content by fixing markup errors.

  ## Credits:

  The package implements bindings to [htacg's tidy-html5](https://github.com/htacg/tidy-html5). All tidy related features are implemeted in `C` using my wrapper library [tidy_html](https://github.com/f34nk/tidy_html). The `Elixir` binding is implemented as a C-Node based on the excellent example of [Lukas Rieder's nodex](https://github.com/Overbryd/nodex).

  ## Example

      iex> TidyEx.parse("<p>Hello World")
      "<p>Hello World</p>"

  """

  @type success() :: String.t() | [String.t()]
  @type error() :: {:error, String.t()}
  @type input() :: String.t() | [String.t()]

  @doc """
  Internal use
  """
  def resolve(list) when is_list(list) do
    cond do
      Enum.count(list) == 1 -> List.first(list)
      true -> list
    end
  end

  @doc """
  Internal use
  """
  def resolve(bin), do: bin

  def options() do
    Application.get_env(:tidyt_ex, :options, [{"TidyShowWarnings", "no"}, {"TidyBodyOnly", "yes"}, {"TidyQuiet", "yes"}, {"TidyVertSpace", "auto"}, {"TidyIndentSpaces", "0"}])
  end

  @doc """
  Serialize any string with valid or broken html.
  Returns valid html string.

  ## Examples

      iex> TidyEx.parse("<div>Hello<span>World")
      "<div>Hello<span>World</span></div>"

  """
  @spec parse(input()) :: success() | error()
  def parse(bin) do
    TidyEx.Parse.parse(bin)
  end

  @doc """
  Clean and repair any string with valid or broken html.
  Returns valid html string.

  ## Examples

      iex> TidyEx.clean_and_repair("<div>Hello<span>World")
      "<div>Hello<span>World</span></div>"

  """
  @spec clean_and_repair(input()) :: success() | error()
  def clean_and_repair(bin) do
    TidyEx.CleanAndRepair.clean_and_repair(bin)
  end

  @doc """
  Run diagnostics on string with valid or broken html.
  Returns diagnostics string.

  ## Examples

      iex> TidyEx.run_diagnostics("<pp>Hello World</p>")
      "line 1 column 1 - Error: <pp> is not recognized!\\nThis document has errors that must be fixed before\\nusing HTML Tidy to generate a tidied up version."

  """
  @spec clean_and_repair(input()) :: success() | error()
  def run_diagnostics(bin) do
    TidyEx.RunDiagnostics.run_diagnostics(bin)
  end

end
