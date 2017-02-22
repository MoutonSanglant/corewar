./asm lolo.s; hexdump -C lolo.cor > my.txt; rm lolo.cor; ./off_asm lolo.s; hexdump -C lolo.cor > of.txt; rm lolo.cor; diff *.txt;
#./asm lolo.s; hexdump -C lolo.cor; rm lolo.cor; ./off_asm lolo.s; hexdump -C lolo.cor; rm lolo.cor
