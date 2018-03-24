# Hasan Abdullah: Makefile - compilation rules for <Poker,Canasta>Hand project

CC=g++
CPPFLAGS=-std=c++11
OBJS=Card.o Hand.o PokerHand.o CanastaHand.o driver.o
INCS=Array1.h Card.h Hand.h PokerHand.h CanastaHand.h
PROGS=driver

Card.o: Card.h Card.cpp
	${CC} ${CPPFLAGS} -c Card.cpp
Hand.o: Array1.h Card.h Hand.h Hand.cpp
	${CC} ${CPPFLAGS} -c Hand.cpp
PokerHand.o: Hand.h PokerHand.h PokerHand.cpp
	${CC} ${CPPFLAGS} -c PokerHand.cpp
CanastaHand.o: Array1.h Card.h Hand.h CanastaHand.h CanastaHand.cpp
	${CC} ${CPPFLAGS} -c CanastaHand.cpp
driver.o: ${INCS} driver.cpp
	${CC} ${CPPFLAGS} -c driver.cpp
driver: ${OBJS}
	${CC} ${CPPFLAGS} ${OBJS} -o ${PROGS}
clean:
	rm ${OBJS} ${PROGS}
