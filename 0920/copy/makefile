all: main.o copyfile.o
	gcc -o copyfile main.o copyfile.o
main.o: main.c

copyfile.o: copyfile.c copyfile.h

clean:
	rm *.0
