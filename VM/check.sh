#!/bin/bash

clear

function match
{
	echo "=============================="
	echo $1
	diff <(./corewar -h $1) <(../resources/corewar $1)
}

match "-d 0 $1 $2 $3 $4"
match "-d 1 $1 $2 $3 $4"
match "-d 5 $1 $2 $3 $4"
match "-d 10 $1 $2 $3 $4"
match "-d 25 $1 $2 $3 $4"
match "-d 200 $1 $2 $3 $4"
match "-d 1000 $1 $2 $3 $4"
match "-d 2800 $1 $2 $3 $4"
match "-d 7600 $1 $2 $3 $4"
match "-d 13400 $1 $2 $3 $4"
match "-d 24300 $1 $2 $3 $4"
match "-d 36500 $1 $2 $3 $4"
