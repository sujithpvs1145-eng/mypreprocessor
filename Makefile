mypreprocessor: mypreprocessor.o comment.o file.o macro.o
	gcc mypreprocessor.o comment.o file.o macro.o -o mypreprocessor

mypreprocessor.o: mypreprocessor.c operation.h
	gcc -c mypreprocessor.c

comment.o: comment.c operation.h
	gcc -c comment.c

file.o: file.c operation.h
	gcc -c file.c
macro.o:macro.c operation.h
	gcc -c macro.c


clean:
	rm -f *.o mypreprocessor
