.name "L'effaceur"
.comment "Comment has been erased"

ld		%42, r11
ld		%5, r2   		# Juste pour que le sti plus tard ecrive autre chose que des 00
ld		6, r3    		# Ici on load ce qui va ecraser le sti. Une valeur direct si on veut faire un test particulier, 6 pour prendre l'octet de codage du XOR en dessous (1 pour prendre son propre octet de codage)
xor		20, 20, r4	# Juste pour avoir des octets de codage a voler par le ld au dessus, c'est plutot pratique pour tester divers octets de coadge
fork	%8			# Obligatoire pour avoir 2 procs pour les tests d'ecrasement
sti		r2, r2, r2          # Le fameux STI qui se sacrifie pour la science
st		r3, -4               # -4 Ecrase le sti à partir de l'octet de codage, -5 pour recouvrir a partir de l'opcode, -8 pour ne recouvrir que l'opcode
