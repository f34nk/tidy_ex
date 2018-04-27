#!/bin/bash

mix_env=$1
current=`pwd`
echo "Compiling ModestEx target from $current $mix_env"

tidy_worker="tidy_worker"

check=`find target \( -name libtidy_html.a \)`
if [ -z "$check" ]
then
	echo "Compiling tidy_html..."
	
	cd target/tidy_html
	./configure && cd build && make
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