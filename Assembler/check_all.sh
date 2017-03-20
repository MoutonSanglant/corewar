#!/bin/bash

function match
{
	echo "=============================="
	echo $1
	str=$1
	pattern=".cor"
	corfile="${str/\.s/$pattern}"
	./asm $1
	hexdump -C $corfile > test1.tmp
	../resources/asm $1
	hexdump -C $corfile > test2.tmp
	diff test1.tmp test2.tmp
}

for file in $(ls ./champions)
do
	match "./champions/$file"
done
