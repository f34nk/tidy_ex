#!/bin/bash

mix_env=$1
current=`pwd`
echo "Compiling ModestEx target from $current $mix_env"

tidy_worker="tidy_worker"

check=`find target/tidy-html5 \( -name libtidys.a \)`
if [ -z "$check" ]
then
  echo "Compiling tidy-html5..."
  # tidy-html5
  # https://github.com/htacg/tidy-html5/blob/next/README/BUILD.md
  cd target/tidy-html5/build/cmake

  cmake ../.. -DCMAKE_BUILD_TYPE=Release -DSUPPORT_CONSOLE_APP=OFF -DBUILD_SHARED_LIB=OFF
  make

  cd $current
  echo "done"
fi

function compile_tidy_worker()
{
	echo "Compiling tidy_worker..."
	rm priv/tidy_worker
	mkdir -p target/$tidy_worker/build
	cd target/$tidy_worker/build
	rm -rf *
	cmake -DERLANG_PATH=`erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version)])]), halt()' -s init stop -noshell` ..
	make
	mv tidy_worker $current/priv
	cd $current
	echo "done"
}

if [ "$mix_env" = "dev" ] || [ "$mix_env" = "test" ]
then
	echo $mix_env
	compile_tidy_worker
else
	check=`find priv -name tidy_worker`
	if [ -z "$check" ]
	then
		compile_tidy_worker
	fi
fi