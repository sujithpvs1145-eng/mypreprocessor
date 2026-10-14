mypreprocessor: mypreprocessor.o comment.o file.o marco.o
	gcc mypreprocessor.o comment.o file.o marco.o -o mypreprocessor

mypreprocessor.o: mypreprocessor.c operation.h
	gcc -c mypreprocessor.c

comment.o: comment.c operation.h
	gcc -c comment.c

file.o: file.c operation.h
	gcc -c file.c
marco.o:marco.c operation.h
	gcc -c marco.c


clean:
	rm -f *.o mypreprocessor
