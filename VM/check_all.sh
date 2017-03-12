#!/bin/bash

ARGS="-d $1 champions/basic_test.cor"
echo "=============================="
echo $ARGS
diff <(./corewar -h $ARGS) <(../resources/corewar $ARGS)

ARGS="-d $1 champions/zjmp_test.cor"
echo "=============================="
echo $ARGS
diff <(./corewar -h $ARGS) <(../resources/corewar $ARGS)

ARGS="-d $1 champions/zjmp_logical.cor"
echo "=============================="
echo $ARGS
diff <(./corewar -h $ARGS) <(../resources/corewar $ARGS)

ARGS="-d $1 Asombra.cor big_feet.cor"
echo "=============================="
echo $ARGS
diff <(./corewar -h $ARGS) <(../resources/corewar $ARGS)

ARGS="-d $1 youforkmytralala.cor big_feet.cor"
echo "=============================="
echo $ARGS
diff <(./corewar -h $ARGS) <(../resources/corewar $ARGS)

ARGS="-d $1 Rainbow_dash.cor doge.cor sam_2.0.cor youforkmytralala.cor"
echo "=============================="
echo $ARGS
diff <(./corewar -h $ARGS) <(../resources/corewar $ARGS)


ARGS="-d $1 fluttershy.cor helltrain.cor"
echo "=============================="
echo $ARGS
diff <(./corewar -h $ARGS) <(../resources/corewar $ARGS)


ARGS="-d $1 helltrain.cor fluttershy.cor"
echo "=============================="
echo $ARGS
diff <(./corewar -h $ARGS) <(../resources/corewar $ARGS)
