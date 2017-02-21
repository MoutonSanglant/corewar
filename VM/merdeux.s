.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"

ld		%104857600, r1
fork	%:toto
sti		r1, %:fork, %0

toto:
live	%43
fork:
fork	%64
sti		r1, %:live, %1

live:
live	%0
