all: main.out

main.out: main.o libretto.o esame.o
	gcc main.o libretto.o esame.o -o main.out

esame.o: esame.h esame.c
	gcc -c esame.c

libretto.o: esame.h libretto.h libretto.c
	gcc -c libretto.c

main.o: libretto.h main.c
	gcc -c main.c

clean:
	rm -f esame.o libretto.o main.o
