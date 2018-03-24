# Hasan Abdullah: Makefile - the make file containing the compile commands

CC=g++
CPPFLAGS=-std=c++11
INCS=MathError.h ZeroDivide.h IntOverflow.h
OBJS=MathError.o ZeroDivide.o IntOverflow.o driver.o
PROGS=driver

MathError.o: MathError.h MathError.cpp
	${CC} ${CPPFLAGS} -c MathError.cpp
ZeroDivide.o: MathError.h ZeroDivide.h ZeroDivide.cpp
	${CC} ${CPPFLAGS} -c ZeroDivide.cpp
IntOverflow.o: MathError.h IntOverflow.h IntOverflow.cpp
	${CC} ${CPPFLAGS} -c IntOverflow.cpp
driver.o: ${INCS} driver.cpp
	${CC} ${CPPFLAGS} -c driver.cpp
driver: ${OBJS}
	${CC} ${CPPFLAGS} ${OBJS} -o ${PROGS}
clean:
	rm ${OBJS} ${PROGS}
