# Hasan Abdullah: Makefile - contains the compile and link commands

CC=g++
CPPFLAGS=-std=c++11
OBJS=Point.o Shape.o Circle.o Triangle.o driver.o
INCS=Point.h Shape.h Circle.h Triangle.h
PROGS=driver

Point.o: Point.h Point.cpp
	${CC} ${CPPFLAGS} -c Point.cpp
Shape.o: Point.h Shape.h Shape.cpp
	${CC} ${CPPFLAGS} -c Shape.cpp
Circle.o: Point.h Shape.h Circle.h Circle.cpp
	${CC} ${CPPFLAGS} -c Circle.cpp
Triangle.o: Point.h Shape.h Triangle.h Triangle.cpp
	${CC} ${CPPFLAGS} -c Triangle.cpp
driver.o: ${INCS} driver.cpp
	${CC} ${CPPFLAGS} -c driver.cpp
driver: ${OBJS}
	${CC} ${CPPFLAGS} ${OBJS} -o ${PROGS}
clean:
	rm ${OBJS} ${PROGS}
