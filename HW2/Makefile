# Hasan Abdullah: Makefile - rules to compile and link the Card project

CC=g++
OPTS=-std=c++11
OBJS=Card.o PokerHand.o driver.o
INCS=Card.h PokerHand.h
PROG=driver

Card.o: Card.h Card.cpp
	${CC} ${OPTS} -c Card.cpp
PokerHand.o: ${INCS} PokerHand.cpp
	${CC} ${OPTS} -c PokerHand.cpp
driver.o: ${INCS} driver.cpp
	${CC} ${OPTS} -c driver.cpp
${PROG}: ${OBJS}
	${CC} ${OPTS} ${OBJS} -o ${PROG}
clean:
	rm ${OBJS} ${PROG}
