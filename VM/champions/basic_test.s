.name "basic_tests"
.comment "ld, st"

#test basic operations

start:
# live with random number
live	%666

#############
###  AFF  ###
#############

aff		r0
aff		r1
aff		r2
aff		r8
aff		r9
aff		r10
aff		r20
aff		r98
aff		r99

############
###  LD  ###
############

truc:
live	%666

# load 42 to r2
ld		%42, r2

# load @0 (02 90 00 00) to r3
ld		0, r3

############
###  ST  ###
############

# store r2 to r3
st		r2, r3

# store r3 @0
st		r3, 0

# store r3 @-4
st		r3, -4

# store r3 @-516
st		r3, -516

# store r3 @6
st		r3, 6

# overwritten live
live	%666

# store r3 @518
st		r3, 518

# overwritten live
live	%666

st		r3, :start

#############
###  ADD  ###
#############

add		r1, r2, r5
st		r5, 6
live	%666

#############
###  SUB  ###
#############

sub		r1, r2, r5
st		r5, 6
live	%666

#############
###  LDI  ###
#############

ld		%1, r6

ldi		%0, %0, r5
st		r5, 6
live	%666

ldi		%3, %-2, r5
st		r5, 6
live	%666

ldi		%0, r6, r5
st		r5, 6
live	%666

ldi		r6, %0, r5
st		r5, 6
live	%666

ldi		r6, %-7, r5
st		r5, 6
live	%666

ldi		%-42, r6, r5
st		r5, 6
live	%666

ldi		:one, r6, r5
st		r5, 6
live	%666

ldi		:one, %0, r5
st		r5, 6
live	%666

one:
live	%1

#############
###  STI  ###
#############

ld		%-42, r2

sti		r2, %0, %0

sti		r2, %3, %-4

sti		r2, %-5, %13
live	%666

sti		r2, %7, r6

sti		r2, r6, %-4

sti		r2, r6, r2

sti		r2, :one, r6

live	%-9

sti		r2, :one, %-5

aff		r2
aff		r6

#############
###  LLD  ###
#############

# zaz's lld doesn't work properly

#ld		-1, r2
#lld		-1, r3
#aff		r2
#st		r2, 6
#live	%666
#live	%-1
#st		r3, 6
#live	%666

#ld 9000, r2
#lld 9000, r3
#st		r2, 6
#live	%666
#st		r3, 6
#live	%666

#ld %9000, r2
#lld %9000, r3
#st		r2, 6
#live	%666
#st		r3, 6
#live	%666

##############
###  LLDI  ###
##############

ld		%8000, r6

ldi		%0, %0, r5
st		r5, 6
live	%666

ldi		%9000, %-2, r5
st		r5, 6
live	%666

ldi		%0, r6, r5
st		r5, 6
live	%666

ldi		r6, %0, r5
st		r5, 6
live	%666

ldi		r6, %-7, r5
st		r5, 6
live	%666

ldi		%-42, r6, r5
st		r5, 6
live	%666

ldi		:one, r6, r5
st		r5, 6
live	%666

ldi		:one, %0, r5
st		r5, 6
live	%666


#ldi		:start, r6, r5


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


# 0x01 live
# 0x02 ld
# 0x03 st
# 0x04 add
# 0x05 sub
# 0x06 and
# 0x07 or
# 0x08 xor
# 0x09 zjmp
# 0x0a ldi
# 0x0b sti r/rdi/rd
# 0x0c fork
# 0x0d lld
# 0x0e lldi
# 0x10 aff

#lfork
