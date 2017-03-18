CHAMPS=ls *.s

for CHAMP in $(ls *.s)
do
	../../resources/asm $CHAMP
done

