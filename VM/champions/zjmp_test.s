.name "zjmp_tests"
.comment "ld, st"

#test basic operations

start:
# live with random number
live	%666
zjmp	%200

############
###  LD  ###
############

# load 42 to r2
ld		%42, r2
zjmp	%200

# load @0 (02 90 00 00) to r3
ld		0, r3
zjmp	%200

############
###  ST  ###
############

# store r2 to r3
st		r2, r3
zjmp	%200

# store r3 @0
st		r3, 0
zjmp	%200

# store r3 @-4
st		r3, -4
zjmp	%200

# store r3 @-516
st		r3, -516
zjmp	%200

# store r3 @6 + 3
st		r3, 9
zjmp	%200

# overwritten live
live	%666

# store r3 @518 + 3
st		r3, 521
zjmp	%200

# overwritten live
live	%666

st		r3, :start
zjmp	%200

#############
###  LDI  ###
#############

ld		%1, r6

ldi		%0, %0, r5
zjmp	%200
st		r5, 6
live	%666

ldi		%3, %-2, r5
zjmp	%200
st		r5, 6
live	%666

ldi		%0, r6, r5
zjmp	%200
st		r5, 6
live	%666

ldi		r6, %0, r5
zjmp	%200
st		r5, 6
live	%666

ldi		r6, %-7, r5
zjmp	%200
st		r5, 6
live	%666

ldi		%-42, r6, r5
zjmp	%200
st		r5, 6
live	%666

ldi		:one, r6, r5
zjmp	%200
st		r5, 6
live	%666

ldi		:one, %0, r5
zjmp	%200
st		r5, 6
live	%666

one:
live	%1

#############
###  STI  ###
#############

ld		%-42, r2

sti		r2, %0, %0
zjmp	%200

sti		r2, %3, %-4
zjmp	%200

sti		r2, %-5, %13
zjmp	%200
live	%666

sti		r2, %7, r6
zjmp	%200

sti		r2, r6, %-4
zjmp	%200

sti		r2, r6, r2
zjmp	%200

sti		r2, :one, r6
zjmp	%200

live	%-9

sti		r2, :one, %-5
zjmp	%200

aff		r2
aff		r6

#############
###  LLD  ###
#############

# zaz's lld doesn't work properly

##############
###  LLDI  ###
##############

ld		%8000, r6

lldi		%0, %0, r5
zjmp	%200
st		r5, 6
live	%666

lldi		%9000, %-2, r5
#zjmp	%200
st		r5, 6
live	%666

lldi		%0, r6, r5
zjmp	%200
st		r5, 6
live	%666

lldi		r6, %0, r5
zjmp	%200
st		r5, 6
live	%666

lldi		r6, %-7, r5
zjmp	%200
st		r5, 6
live	%666

lldi		%-42, r6, r5
zjmp	%200
st		r5, 6
live	%666

lldi		:one, r6, r5
zjmp	%200
st		r5, 6
live	%666

lldi		:one, %0, r5
zjmp	%200
st		r5, 6
live	%666
