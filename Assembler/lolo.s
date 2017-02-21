#by zaz, it's not very good, but what did you expect, rainbowdash is way better


	.name       ""
	.comment    "oh, my, what a scary project"

	live    %12
	live    %:toto
	ld		6, r2
toto:
	st		r1, r2
	add		r1, r2, r3
	sub		r1, r1, r1
	and		r1, %12, r3
	or		r1, -8, r3
	xor		%-2, 13, r8
	zjmp	%-24
	ldi		12, %5, r6
	sti		r1, r2, r3
	fork	%0
	lld		4, r2
	lldi	4, %20, r0
	lfork	%2000
	aff		r20
	live    %12
