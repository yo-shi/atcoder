#/bin/bash
pushd ~/work/atcoder
mkdir $1
cd $1
cp ../templete.cpp $2.cpp
code $2.cpp
popd