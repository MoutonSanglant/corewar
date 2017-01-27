.name "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam ac nibh elit. Nulla feugiat risus vitae lacus luctus orci aliquamaBY"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"

ld 30, r3
ld 50, r6
#While (r2 < 10)
forks:
add	r2, r3, r2		;increment r2
xor	r2, %15, r4		;if (r4) {carry = 0}
live2:
	live 	%4
zjmp	%:endwhile		;if (carry)
fork	%:forks
ld	%0, r4			;carry = 1
zjmp	%:forks
#EndWhile
endwhile:
ld	%0, r4			;carry = 1

live:
live %4
zjmp %:live
