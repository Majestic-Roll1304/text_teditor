cc="gcc"
flag='c'

mod: modifying.o pointer.o update.o
	$(cc) modifying.o pointer.o update.o -o mod

textflow: main.o pointer.o update.o
	$(cc) main.o pointer.o update.o -o textflow

main.o: main.c
	$(cc) main.c -$(flag) 

pointer.o: pointer.c
	$(cc) pointer.c -$(flag)

modify.o: modifying.c
	$(cc) modifying.c -$(flag) 

update.o:update.c
	$(cc) update.c -$(flag)

remobj:
	rm *.o 

remall:
	rm *.o mod textflow
