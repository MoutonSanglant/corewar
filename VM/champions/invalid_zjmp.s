.name "invalid_zjmp_tests"
.comment "ld, st"

###############
##  INVALID  ##
###############

ld		%-1, r2
st		r2, 6

#invalid aff (-1)
aff		r99
aff		r20

ld		%150, r2
st		r2, 6

#invalid aff (> 100)
aff		r99
aff		r20

###################
##  INVALID OCP  ##
###################

ld		%-1, r2

#invalid live
st		r2, 6
live	%0

#invalid ld
st		r2, 6
ld		%-1, r2

#invalid st
st		r2, 6
st		r5, 0

#invalid add
st		r2, 6
add		r3, r3, r3

#invalid sub
st		r2, 6
sub		r3, r3, r3

#invalid and
st		r2, 6
and		r3, r3, r3

#invalid or
st		r2, 6
or		r3, r3, r3

#invalid xor
st		r2, 6
xor		r3, r3, r3

aff		r3

#invalid zjmp
st		r2, 6
zjmp	%0

#invalid ldi
st		r2, 6
ldi		:start, %0, r3

#invalid sti
st		r2, 6
sti		r3, :start, %1
