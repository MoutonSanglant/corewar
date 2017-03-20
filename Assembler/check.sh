#!/bin/bash

function match
{
	echo "=============================="
	echo $1
	str=$1
	pattern=".cor"
	corfile="${str/\.s/$pattern}"
	rm $corfile
	echo ":our"
	./asm $1
	hexdump -C $corfile > test1.tmp
	echo ":zaz"
	../resources/asm $1
	hexdump -C $corfile > test2.tmp
	diff test1.tmp test2.tmp
}

match "$1"
