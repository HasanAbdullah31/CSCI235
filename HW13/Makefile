# Hasan Abdullah: Makefile - compilation rules for Queue project

CC=g++
OPTS=-std=c++11
INCS=Queue.h
OBJS=Queue.o driver.o

Queue.o: Queue.h Queue.cpp
	${CC} ${OPTS} -c Queue.cpp
driver.o: ${INCS} driver.cpp
	${CC} ${OPTS} -c driver.cpp
driver: ${OBJS}
	${CC} ${OPTS} ${OBJS} -o driver
clean:
	rm *~ ${OBJS} driver
