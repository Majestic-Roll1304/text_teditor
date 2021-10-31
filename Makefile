cc="gcc"
flag='c'

mod: modifying.o
	$(cc) modifying.o 

modify.o: modifying.c
	$(cc) modifying.c -$(flag) 

main: main.o
	$(cc) main.o

main.o: main.c
	$(cc) main.c -$(flag) 
