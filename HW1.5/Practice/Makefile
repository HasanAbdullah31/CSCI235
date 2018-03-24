# Hasan Abdullah: Makefile - contains the compile and link commands

CC=g++
OPTS=-std=c++11
OBJS=Point.o Shape.o Circle.o Triangle.o driver.o
INCS=Point.h Shape.h Circle.h Triangle.h
PROGS=driver

Point.o: Point.h Point.cpp
	${CC} ${OPTS} -c Point.cpp
Shape.o: Shape.h Point.h Shape.cpp
	${CC} ${OPTS} -c Shape.cpp
Circle.o: ${INCS} Circle.cpp
	${CC} ${OPTS} -c Circle.cpp
Triangle.o: ${INCS} Triangle.cpp
	${CC} ${OPTS} -c Triangle.cpp
driver.o: ${INCS} driver.cpp
	${CC} ${OPTS} -c driver.cpp
${PROGS}: ${OBJS}
	${CC} ${OPTS} ${OBJS} -o driver
clean:
	rm ${OBJS} ${PROGS}
