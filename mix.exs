defmodule TidyEx.MixProject do
  use Mix.Project

  def project do
    [
      app: :tidy_ex,
      version: "0.1.0-dev",
      elixir: "~> 1.5",
      compilers: [:tidy_ex_compile] ++ Mix.compilers(),
      build_embedded: Mix.env() == :prod,
      start_permanent: Mix.env() == :prod,
      name: "TidyEx",
      description: """
        TidyEx corrects and cleans up HTML content by fixing markup errors. Elixir binding to the granddaddy of HTML tools (http://www.html-tidy.org/). Binding implemented as a C-Node based on the excellent example of Lukas Rieder's nodex.
      """,
      docs: docs(),
      deps: deps(),
      package: package()
    ]
  end

  defp docs do
    [
      main: "TidyEx"
    ]
  end

  def package do
    [
      maintainers: ["Frank Eickhoff"],
      licenses: ["GNU LGPL"],
      links: %{
        "Github" => "https://github.com/f34nk/tidy_ex",
        "Issues" => "https://github.com/f34nk/tidy_ex/issues",
        "nodex" => "https://github.com/Overbryd/nodex",
        "tidy-html5" => "https://github.com/htacg/tidy-html5"
      },
      files: [
        "lib",
        "target",
        "test",
        "priv/compile.sh",
        "priv/clean.sh",
        "priv/test.sh",
        "mix.exs",
        "README.md",
        "LICENSE"
      ]
    ]
  end

  def application do
    [
      extra_applications: [:logger],
      mod: {TidyEx.Safe, []},
      # used to detect conflicts with other applications named processes
      registered: [TidyEx.Safe.Cnode, TidyEx.Safe.Supervisor],
      env: [
        mode: TidyEx.Safe
      ]
    ]
  end

  defp deps do
    [
      # documentation helpers
      {:ex_doc, ">= 0.0.0", only: :dev},
      # cnode helpers
      {:nodex, "~> 0.1.1"}
    ]
  end
end

defmodule Shell do
  def exec(exe, args, opts \\ [:stream]) when is_list(args) do
    port =
      Port.open(
        {:spawn_executable, exe},
        opts ++ [{:args, args}, :binary, :exit_status, :hide, :use_stdio, :stderr_to_stdout]
      )

    handle_output(port)
  end

  def handle_output(port) do
    receive do
      {^port, {:data, data}} ->
        # Replace this with the appropriate broadcast
        IO.binwrite(data)
        handle_output(port)

      {^port, {:exit_status, status}} ->
        status
    end
  end
end

defmodule Mix.Tasks.Compile.TidyExCompile do
  def run(_) do
    if match?({:win32, _}, :os.type()) do
      IO.warn("Windows is not supported yet.")
      exit(1)
    else
      Shell.exec("priv/compile.sh", [])
    end

    :ok
  end

  def clean() do
    Shell.exec("priv/clean.sh", [])
    :ok
  end
end

defmodule Mix.Tasks.Test.Target do
  def run(_) do
    if match?({:win32, _}, :os.type()) do
      IO.warn("Windows is not supported yet.")
      exit(1)
    else
      Shell.exec("priv/test.sh", [])
    end

    :ok
  end
end
