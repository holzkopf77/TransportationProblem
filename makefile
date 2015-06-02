#
#	Makefile dla leniwych by Hodor
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11

__start__: a.out
	./a.out

a.out: obj/main.o
	g++ -Wall -pedantic -std=c++11 -o a.out obj/main.o

obj/main.o: src/main.cpp inc/iTransportProblem.hh 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o a.out
