test: test.o read.o write.o

test.o: io.h test.c

read.o: io.h read.c

write.o: io.h write.c

clean:
	rm *.o
