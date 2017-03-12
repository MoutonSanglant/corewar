.name "zjmp_logical"
.comment "add, sub, and, or, xor"

zero:
live	%0

ld		%0, r2
st		r2, -12

one:
live	%0

ld		%1, r2
st		r2, -12

two:
live	%0

ld		%2, r2
st		r2, -12

three:
live	%0

ld		%3, r2
st		r2, -12

ld		%42, r2
ld		%-21, r3
ld		%21, r4

#############
###  ADD  ###
#############

add		r2, r3, r7
aff		r7
zjmp	%200
add		r7, r3, r7
aff		r7
zjmp	%6
zjmp	%200
zjmp	%6
zjmp	%200

ld		%1594033936, r8
st		r8, 7 

add		r20, r3, r7
aff		r7
zjmp	%200

#############
###  SUB  ###
#############

sub		r2, r4, r7
aff		r7
zjmp	%200
sub		r7, r4, r7
aff		r7
zjmp	%6
zjmp	%200
zjmp	%6
zjmp	%200

ld		%1594033936, r8
st		r8, 7 

sub		r20, r3, r7
aff		r7
zjmp	%200

#####################
ld		%1, r2
ld		%2, r3
ld		%3, r4
#####################

#############
###  AND  ###
#############

# r / r
and		r2, r4, r7
aff		r7
zjmp	%200
and		r2, r3, r7
aff		r7
zjmp	%6
zjmp	%200
zjmp	%6
zjmp	%200

# r / d
and		r2, %3, r7
aff		r7
zjmp	%200
and		r2, %2, r7
aff		r7
zjmp	%6
zjmp	%200
zjmp	%6
zjmp	%200

# r / i
and		r2, :three, r7
aff		r7
zjmp	%200
and		r2, :two, r7
aff		r7
zjmp	%6
zjmp	%200
zjmp	%6
zjmp	%200

# d / r
and		%1, r4, r7
aff		r7
zjmp	%200
and		%1, r3, r7
aff		r7
zjmp	%6
zjmp	%200
zjmp	%6
zjmp	%200

# d / d
and		%1, %3, r7
aff		r7
zjmp	%200
and		%1, %2, r7
aff		r7
zjmp	%6
zjmp	%200
zjmp	%6
zjmp	%200

# d / i
and		%1, :three, r7
aff		r7
zjmp	%200
and		%1, :two, r7
aff		r7
zjmp	%6
zjmp	%200
zjmp	%6
zjmp	%200

# i / r
and		:one, r4, r7
aff		r7
zjmp	%200
and		:one, r3, r7
aff		r7
zjmp	%6
zjmp	%200
zjmp	%6
zjmp	%200

# i / d
and		:one, %3, r7
aff		r7
zjmp	%200
and		:one, %2, r7
aff		r7
zjmp	%6
zjmp	%200
zjmp	%6
zjmp	%200

# i / i
and		:one, :three, r7
aff		r7
zjmp	%200
and		:one, :two, r7
aff		r7
zjmp	%6
zjmp	%200
zjmp	%6
zjmp	%200


ld		%1594033936, r8
st		r8, 7 

and		r20, r3, r7
aff		r7
zjmp	%200
