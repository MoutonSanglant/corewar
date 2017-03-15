#by zaz, it's not very good, but what did you expect, rainbowdash is way better
#2013

.name		"toto"
.comment	"0 + 0 = ?"

ld		%1, r4
ld		%1, r5
ld		%0, r7
aff		r7

# 02 90 ff ff
#ld		%43057150, r3
# 02 d0 ff fe
#ld		%47251454, r3
# 02 d1 ff ff
#ld		%47316991, r3
# 02 d0 ff ff
#ld		%47251455, r3
# 03 d0 ff ff
#ld		%64028671, r3
# 90 ff ff 04
#ld		%-1862271228, r3

# 03 70 d1 d1
#ld		%57725393, r3
# 03 71 d1 d1
#ld		%57790929, r3
# 03 50 d1 d1
#ld		%55628241, r3
# 03 00 d1 d1
#ld		%50385361, r3
# 03 ff d1 d1
#ld		%67097041, r3

# 01 ff ff ff -> 3
#ld		%33554431, r3
# 02 ff ff ff -> 3
#ld		%50331647, r3
# 03 ff ff ff -> 3
#ld		%67108863, r3
# 04 ff ff ff -> 3
#ld		%83886079, r3
# 05 ff ff ff -> 3
#ld		%100663295, r3
# 06 ff ff ff -> 3
#ld		%117440511, r3
# 07 ff ff ff -> 3
#ld		%134217727, r3
# 08 ff ff ff -> 3
#ld		%150994943, r3
# 09 ff ff ff -> 3
#ld		%167772159, r3
# 0a ff ff ff -> 3
#ld		%184549375, r3
# 0b ff ff ff
#ld		%201326591, r3
# 0c ff ff ff
#ld		%218103807, r3
# 0d ff ff ff
#ld		%234881023, r3
# 0e ff ff ff
#ld		%251658239, r3
# 0f ff ff ff
#ld		%268435455, r3
# 10 ff ff ff
ld		%285212671, r3

ld		%151123455, r9

st		r9, 13

live	%0
fork	%18
#live	%0
#sti		r3, %100, %4
#ld		1, r3
#ld		%-1, r3
sti		r3, r4, r5

st		r3, 64
st		r3, 64
st		r3, -15
live	%0

# saut OK
#add		r9, r9, r2

# saut PAS OK (je saute, zaz non)
#add		r30, r30, r2

# saut PAS OK (je saute, zaz non)
#add		r2, r2, r30
#zjmp		%200
