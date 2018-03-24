# Hasan Abdullah: Makefile - compilation rules for Hash Table project

CC=g++
OPTS=-std=c++11
INCS=Node.h List.h Hash.h
OBJS=Node.o List.o Hash.o driver.o
PROG=driver

Node.o: Node.h Node.cpp
	${CC} ${OPTS} -c Node.cpp
List.o: Node.h List.h List.cpp
	${CC} ${OPTS} -c List.cpp
Hash.o: ${INCS} Hash.cpp
	${CC} ${OPTS} -c Hash.cpp
driver.o: ${INCS} driver.cpp
	${CC} ${OPTS} -c driver.cpp
driver: ${OBJS}
	${CC} ${OPTS} ${OBJS} -o ${PROG}
clean:
	rm *~ ${OBJS} ${PROG}
