# Hasan Abdullah: Makefile - specifies compilation rules used with make utility

PROG=driver
CC=g++
CPPFLAGS=-std=c++11
OBJS=Bag.o driver.o

#Bag.o: Bag.cpp Bag.h
#	${CC} ${CPPFLAGS} -c Bag.cpp

driver.o:
	${CC} ${CPPFLAGS} -c Bag.cpp driver.cpp
${PROG}: driver.o
	${CC} ${CPPFLAGS} driver.o -o driver
clean:
	rm -f core ${PROG} ${OBJS}
