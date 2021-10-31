cc="gcc"
flag='c'

mod: modifying.o pointer.o
	$(cc) modifying.o pointer.o

modify.o: modifying.c
	$(cc) modifying.c -$(flag) 

main: main.o pointer.o 
	$(cc) main.o pointer.o

main.o: main.c
	$(cc) main.c -$(flag) 

pointer.o: pointer.c
	$(cc) pointer.c -$(flag)
