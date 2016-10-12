#!/bin/bash

pushd Dependencies

echo "gtest"
git clone git@github.com:google/googletest.git --depth=1
pushd googletest
	pushd googletest
		cmake .
		make 
	popd
	pushd googlemock
		cmake .
		make
	popd
popd

echo "FredLib"
git clone git@github.com:CodogoFreddie/FredLib.git --depth=1
