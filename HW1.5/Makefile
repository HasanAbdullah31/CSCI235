# Hasan Abdullah: Makefile - contains the compile and link commands

CC=g++
OPTS=-std=c++11
OBJS=Point.o Shape.o Quadrilateral.o Square.o Rectangle.o Rhombus.o Parallelogram.o driver.o
INCS=Point.h Shape.h Quadrilateral.h
PROGS=driver

Point.o: Point.h Point.cpp
	${CC} ${OPTS} -c Point.cpp
Shape.o: Shape.h Point.h Shape.cpp
	${CC} ${OPTS} -c Shape.cpp
Quadrilateral.o: ${INCS} Quadrilateral.cpp
	${CC} ${OPTS} -c Quadrilateral.cpp
Square.o: ${INCS} Square.h Square.cpp
	${CC} ${OPTS} -c Square.cpp
Rectangle.o: ${INCS} Rectangle.h Rectangle.cpp
	${CC} ${OPTS} -c Rectangle.cpp
Rhombus.o: ${INCS} Rhombus.h Rhombus.cpp
	${CC} ${OPTS} -c Rhombus.cpp
Parallelogram.o: ${INCS} Parallelogram.h Parallelogram.cpp
	${CC} ${OPTS} -c Parallelogram.cpp
driver.o: ${INCS} Square.h Rectangle.h Rhombus.h Parallelogram.h driver.cpp
	${CC} ${OPTS} -c driver.cpp
${PROGS}: ${OBJS}
	${CC} ${OPTS} ${OBJS} -o driver
clean:
	rm ${OBJS} ${PROGS}
