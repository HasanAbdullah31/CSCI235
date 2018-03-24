# Hasan Abdullah: Makefile - compilation rules for Book project

CC=g++
OPTS=-std=c++11
ERR=FileError.h NonExistent.h NoPermissions.h
INCS=RecordLimits.h Book.h BookRecords.h
OBJS=NonExistent.o NoPermissions.o Book.o BookRecords.o driver.o
PROGS=driver

NonExistent.o: FileError.h NonExistent.h NonExistent.cpp
	${CC} ${OPTS} -c NonExistent.cpp
NoPermissions.o: FileError.h NoPermissions.h NoPermissions.cpp
	${CC} ${OPTS} -c NoPermissions.cpp
Book.o: RecordLimits.h Book.h Book.cpp
	${CC} ${OPTS} -c Book.cpp
BookRecords.o: Array.h Array.cpp ${ERR} ${INCS} BookRecords.cpp
	${CC} ${OPTS} -c BookRecords.cpp
driver.o: RecordLimits.h Book.h BookRecords.h driver.cpp
	${CC} ${OPTS} -c driver.cpp
driver: ${OBJS}
	${CC} ${OPTS} ${OBJS} -o ${PROGS}
clean:
	rm *~ *.txt ${OBJS} ${PROGS}
