#!/bin/bash

current=`pwd`

echo "Test TidyEx target from $current"

check=`find target/tidy-html5/build/cmake \( -name tidy \)`
if [ -z "$check" ]
then
  echo "Compiling tidy-html5..."
  # tidy-html5
  # https://github.com/htacg/tidy-html5/blob/next/README/BUILD.md
  cd target/tidy-html5/build/cmake

  # cmake ../.. -DCMAKE_BUILD_TYPE=Release -DSUPPORT_CONSOLE_APP=OFF -DBUILD_SHARED_LIB=OFF
  cmake ../.. -DCMAKE_BUILD_TYPE=Release -DSUPPORT_CONSOLE_APP=ON -DBUILD_SHARED_LIB=OFF
  make

  cd $current
  echo "done"
fi

check=`find target/tidy-html5/build/cmake \( -name tidy \)`
if [ ! -z "$check" ]
then

  echo "Test tidy-html5..."

  cd target/tidy-html5-tests/tools-sh
  ./run-tests.sh
  cd $current
  echo "done"
fi

check=`find priv -name tidy_worker`
if [ ! -z "$check" ]
then
  echo "Test tidy_worker..."
  cd target/tidy_worker/build
  make test
  cd $current
  echo "done"

  logs=( `find target/tidy_worker -name LastTest.log` )
  for i in "${logs[@]}"
  do
    echo $i
    if [ ! -z `which subl` ]
    then
      subl $i
    fi
  done

  logs=( `find target/tidy_worker -name LastTestsFailed.log` )
  for i in "${logs[@]}"
  do
    echo $i
    if [ ! -z `which subl` ]
    then
      subl $i
    fi
  done
fi