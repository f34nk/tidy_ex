#!/bin/bash

current=`pwd`

echo "Test TidyEx target from $current"

# check=`find target \( -name libmodest_static.a -o -name libmodest.so \)`
# if [ ! -z "$check" ]
# then

#   echo "Test Modest..."

#   cd target/Modest
#   make test
#   cd $current
#   echo "done"
# fi

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