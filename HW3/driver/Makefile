# Hasan Abdullah: Makefile - the file containing the compilation rules

CC=g++
CPPFLAGS=-std=c++11
INCS=Card.h Hand.h
OBJS=Card.o Hand.o driver.o
PROGS=driver

Card.o: Card.h Card.cpp
	${CC} ${CPPFLAGS} -c Card.cpp
Hand.o: ${INCS} Hand.cpp
	${CC} ${CPPFLAGS} -c Hand.cpp
driver.o: ${INCS} driver.cpp
	${CC} ${CPPFLAGS} -c driver.cpp
${PROGS}: ${OBJS}
	${CC} ${CPPFLAGS} ${OBJS} -o ${PROGS}
clean:
	rm ${OBJS} ${PROGS}
