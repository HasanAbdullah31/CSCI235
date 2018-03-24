# Hasan Abdullah: Makefile - compilation rules for Linked List project

CC=g++
OPTS=-std=c++11
INCS=Node.h List.h
OBJS=Node.o List.o driver.o
PROG=driver

Node.o: Node.h Node.cpp
	${CC} ${OPTS} -c Node.cpp
List.o: ${INCS} List.cpp
	${CC} ${OPTS} -c List.cpp
driver.o: ${INCS} driver.cpp
	${CC} ${OPTS} -c driver.cpp
driver: ${OBJS}
	${CC} ${OPTS} ${OBJS} -o ${PROG}
clean:
	rm *~ ${OBJS} ${PROG}
