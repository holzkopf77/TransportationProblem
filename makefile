#
#	Makefile dla leniwych by Hodor
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11

__start__: a.out
	./a.out

a.out: obj/demander.o obj/main.o obj/supplier.o obj/TransportProblem.o
	g++ -Wall -pedantic -std=c++11 -o a.out obj/demander.o obj/main.o obj/supplier.o obj/TransportProblem.o

obj/demander.o: src/demander.cpp inc/demander.hh inc/iTransportProblem.hh inc/supplier.hh inc/TransportProblem.hh 
	g++ ${CPPFLAGS} -o obj/demander.o src/demander.cpp

obj/main.o: src/main.cpp inc/demander.hh inc/iTransportProblem.hh inc/supplier.hh inc/TransportProblem.hh 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/supplier.o: src/supplier.cpp inc/demander.hh inc/iTransportProblem.hh inc/supplier.hh inc/TransportProblem.hh 
	g++ ${CPPFLAGS} -o obj/supplier.o src/supplier.cpp

obj/TransportProblem.o: src/TransportProblem.cpp inc/demander.hh inc/iTransportProblem.hh inc/supplier.hh inc/TransportProblem.hh 
	g++ ${CPPFLAGS} -o obj/TransportProblem.o src/TransportProblem.cpp

clean:
	rm -f obj/*.o a.out
