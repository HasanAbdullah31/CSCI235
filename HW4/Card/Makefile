# Hasan Abdullah: Makefile - the file containing the compilation rules

CC=g++
CPPFLAGS=-std=c++11
INCS=Card.h Hand.h CardError.h SymbolFail.h SuitFail.h InHand.h
OBJS=Card.o Hand.o SymbolFail.o SuitFail.o InHand.o driver.o
PROGS=driver

Card.o: SymbolFail.h SuitFail.h Card.h Card.cpp
	${CC} ${CPPFLAGS} -c Card.cpp
Hand.o: InHand.h Card.h Hand.h Hand.cpp
	${CC} ${CPPFLAGS} -c Hand.cpp
SymbolFail.o: Card.h CardError.h SymbolFail.h SymbolFail.cpp
	${CC} ${CPPFLAGS} -c SymbolFail.cpp
SuitFail.o: Card.h CardError.h SuitFail.h SuitFail.cpp
	${CC} ${CPPFLAGS} -c SuitFail.cpp
InHand.o: Hand.h CardError.h InHand.h InHand.cpp
	${CC} ${CPPFLAGS} -c InHand.cpp
driver.o: ${INCS} driver.cpp
	${CC} ${CPPFLAGS} -c driver.cpp
driver: ${OBJS}
	${CC} ${CPPFLAGS} ${OBJS} -o ${PROGS}
clean:
	rm ${OBJS} ${PROGS}
