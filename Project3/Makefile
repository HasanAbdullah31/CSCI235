# Hasan Abdullah: Makefile - compilation rules for Binary Tree project

CC=g++
OPTS=-std=c++11
INCS=Node.h BinaryTree.h
OBJS=Date.o Node.o BinaryTree.o driver.o
PROG=driver

Date.o: Date.h Date.cpp
	${CC} ${OPTS} -c Date.cpp
Node.o: Node.h Node.cpp
	${CC} ${OPTS} -c Node.cpp
BinaryTree.o: ${INCS} BinaryTree.cpp
	${CC} ${OPTS} -c BinaryTree.cpp
driver.o: Date.h ${INCS} driver.cpp
	${CC} ${OPTS} -c driver.cpp
driver: ${OBJS}
	${CC} ${OPTS} ${OBJS} -o ${PROG}
clean:
	rm *~ ${OBJS} ${PROG}
