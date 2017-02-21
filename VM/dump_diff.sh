#!/bin/bash

cycle=$1

./corewar -d $cycle ../resources/champions/examples/fluttershy.cor ../resources/champions/examples/fluttershy.cor ../resources/champions/examples/fluttershy.cor ../resources/champions/examples/fluttershy.cor > dump1.tmp
../resources/corewar -d $cycle ../resources/champions/examples/fluttershy.cor ../resources/champions/examples/fluttershy.cor ../resources/champions/examples/fluttershy.cor ../resources/champions/examples/fluttershy.cor > dump2.tmp
#./corewar -d $cycle ../resources/champions/examples/fluttershy.cor ../resources/champions/examples/fluttershy.cor ../resources/champions/examples/fluttershy.cor > dump1.tmp
#../resources/corewar -d $cycle ../resources/champions/examples/fluttershy.cor ../resources/champions/examples/fluttershy.cor ../resources/champions/examples/fluttershy.cor > dump2.tmp

diff dump1.tmp dump2.tmp
rm dump1.tmp dump2.tmp
