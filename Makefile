cc="gcc"
flag='c'

a.out: modifying.o
	$(cc) modifying.o 

modify.o: modifying.c
	$(cc) modifying.c -$(flag) 

main.o: main.c
	$(cc) main.c -$(flag) 
