#!/bin/bash

clear

function match
{
	echo "=============================="
	echo $1
	diff <(./corewar -h $1) <(../resources/corewar $1)
}

match "-d $1 champions/basic_test.cor"
match "-d $1 champions/zjmp_test.cor"
match "-d $1 champions/zjmp_logical.cor"
match "-d $1 champions/Asombra.cor champions/big_feet.cor"
#match "-d $1 champions/youforkmytralala.cor champions/big_feet.cor"
#match "-d $1 champions/Rainbow_dash.cor champions/doge.cor champions/sam_2.0.cor champions/youforkmytralala.cor"
match "-d $1 champions/fluttershy.cor champions/helltrain.cor"
match "-d $1 champions/THUNDER.cor champions/Asombra.cor champions/doge.cor"
match "-d $1 champions/helltrain.cor"
match "-d $1 champions/Asombra.cor champions/jinx.cor"
match "-d $1 champions/bigzork.cor champions/terminator.cor champions/big_feet.cor"
match "-d $1 champions/casimir.cor champions/champ.cor"
match "-d $1 champions/darksasuke.cor champions/littlepuppy.cor"
match "-d $1 champions/doge.cor champions/corelol.cor"
match "-d $1 champions/fluttershy.cor champions/basic_test.cor champions/MarineKing.cor"
match "-d $1 champions/helltrain.cor champions/Machine-gun.cor champions/justin_bee.cor"
match "-d $1 champions/Kappa.cor champions/gedeon.cor champions/invalid_zjmp.cor"
match "-d $1 champions/lolo.cor champions/Wall.cor champions/Varimathras.cor champions/salamahenagalabadoun.cor"
match "-d $1 champions/loose.cor champions/dubo.cor"
#match "-d $1 champions/mandragore.cor champions/live.cor champions/bee_gees.cor"
match "-d $1 champions/Misaka_Mikoto.cor champions/sam_2.0.cor champions/skynet.cor"
match "-d $1 champions/THUNDER.cor champions/turtle.cor"
match "-d $1 champions/youforkmytralala.cor champions/zjmp_logical.cor champions/zork.cor"
match "-d $1 champions/zjmp_test.cor champions/meowluigi.cor champions/ultimate-surrender.cor champions/Rainbow_dash.cor"
