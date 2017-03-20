.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"


live %12
ld	8, r9
sti	r1, 5, %1			;change live by the right value
sub r1, r2, r3
sti	r1, 5, %1			;change live by the right value

# IND - REG       => 0xd0 => 0b  11    01    00    00
# REG - IND - DIR => 0x78 => 0b  01    11    10    00
# REG - REG - REG => 0x54 => 0b  01    01    01    00
#								1er    2eme  3eme  00
# reg = 01
# dir = 10
# ind = 11

# %12 = DIR = 4 octets
# 12 = IND = 2 octets
# r12 = REG = 1 octet