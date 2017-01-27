#by zaz, it's not very good, but what did you expect, rainbowdash is way better
#2013

.name		"fluttershy"
.comment	"oh, my, what a scary project"

	fork	%14
	st		r1, 6
	live	%42
	fork	%14
	st		r1, 6
	live	%42
	fork	%1


	st 		r1, 6

	live 	%213904
	fork 	%14

	sti		r1, %12, %1
	st		r1, 6
	live	%43123
	sti		r1, %12, %1
	ld		%-6, r2
	ld		%-6, r3
	ld		%150994953, r4
	ld		%-186, r5

	live	%295423
	sti		r4, %54, r2
	add		r2, r3, r2
	sti		r4, %5, r2
	add		r2, r3, r2
	live	%3940641
	xor		r2, r5, r15
	zjmp	%2
	ld		%0, r16
	zjmp	%6


	st		r1, 6

	live	%123012
	fork	%5

	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	st		r1, 58
	ld		%0, r16

	live	%985341
	live	%985341
	live	%985341
	live	%985341
	live	%985341
	live	%985341
	live	%985341
	live	%985341
	live	%985341
	live	%985341
	zjmp	%6

	st 		r1, 6

	live 	%213904
	fork 	%6

	sti		r1, %7, %1
	st		r1, 6
	live	%43123
	sti		r1, %8, %1
	ld		%0, r2
	ld		%6, r3
	ld		%150994953, r4
	ld		%180, r5

	live	%295423
	sti		r4, %6, r2
	add		r2, r3, r2
	sti		r4, %9, r2
	add		r2, r3, r2
	live	%3940641
	xor		r2, r5, r15
	zjmp	%8
	ld		%0, r16
	zjmp	%6

	st		r1, 6

	live	%96824
	fork	%6

	ld		%0, r2
	ld		%4, r3
	ld		%96, r5
	sti		r1, %8, %1
	st		r1, 6

	live	%8008135
	ldi		%6, r2, r4
	sti		r4, %400, r2
	add		r2, r3, r2
	ldi		%6, r2, r4
	sti		r4, %383, r2
	add		r2, r3, r2
	live	%89523
	xor		r2, r5, r15
	zjmp	%362
	ld		%0, r15
	zjmp	%6
