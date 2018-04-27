#!/bin/bash

current=`pwd`

echo "Running TidyEx package test from $current"

test -d package_test || mkdir package_test
rm -rf package_test/*

mkdir package_test/tidy_ex

mix hex.build
mv tidy_ex-*.tar package_test/tidy_ex

cd package_test/tidy_ex
tar -xf *.tar
tar -xzf *.tar.gz

cd ..
rm -rf foo
mkdir foo
cd foo
cat > mix.exs <<EOF
defmodule Foo.MixProject do
  use Mix.Project

  def project() do
    [
      app: :foo,
      version: "1.0.0",
      package: [
        links: %{},
        licenses: ["Apache 2.0"],
        description: "test",
        maintainers: ["me"]
      ],
      deps: deps()
    ]
  end

  defp deps do
    [
      {:tidy_ex, path: "../tidy_ex"}
    ]
  end
end
EOF

mix deps.get
mix compile

mix run -e 'IO.inspect "<a>Hello</a>" == TidyEx.parse("<p><a>Hello</a> World</p>")'

cd $current
rm -rf package_test

echo "ok"