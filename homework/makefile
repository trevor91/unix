test: main.o read.o write.o parser.o func.o
	gcc -o test main.o read.o write.o parser.o func.o
main.o: main.c io.h parser.h func.h

read.o: read.c parser.h

write.o: write.c func.h

parser.o: parser.c parser.h

func.o: func.c func.h

clean:
	rm *.o
