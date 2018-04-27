#!/bin/bash

current=`pwd`

echo "Clean TidyEx target from $current"

check=`find target \( -name libtidy_html.a \)`
if [ ! -z "$check" ]
then
	echo "Clean tidy_html..."
	cd target/tidy_html/build
	make clean
	cd $current
	rm -rf target/tidy_html/build
	echo "done"
fi

check=`find target \( -name libtidys.a \)`
if [ ! -z "$check" ]
then
	echo "Clean tidy-html5..."
	cd target/tidy_html/libs/tidy-html5/build/cmake
	make clean
	cd $current
	echo "done"
fi

check=`find priv -name tidy_worker`
if [ ! -z "$check" ]
then
	echo "Clean tidy_worker..."
	cd target/tidy_worker/build
	make clean
	cd $current
	rm -rf target/tidy_worker/build
	echo "remove tidy_worker..."
	cd priv
	rm tidy_worker
	cd $current
	echo "done"
fi