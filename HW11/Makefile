# Hasan Abdullah: Makefile - compilation rules for Pet project (Exam 1+HW11)

CC=g++
CPPFLAGS=-std=c++11
INCS=Color.h Array.h Pet.h Cat.h Dog.h
OBJS=Pet.o Cat.o Dog.o driver.o
PROGS=driver

Pet.o: Color.h Pet.h Pet.cpp
	${CC} ${CPPFLAGS} -c Pet.cpp
Cat.o: Pet.h Cat.h Cat.cpp
	${CC} ${CPPFLAGS} -c Cat.cpp
Dog.o: Pet.h Dog.h Dog.cpp
	${CC} ${CPPFLAGS} -c Dog.cpp
driver.o: ${INCS} driver.cpp
	${CC} ${CPPFLAGS} -c driver.cpp
driver: ${OBJS}
	${CC} ${CPPFLAGS} ${OBJS} -o ${PROGS}
clean:
	rm ${OBJS} ${PROGS}
