SRC=$(wildcard *.cpp)
OBJ = ${SRC:.cpp=.o}

BIN = ./Run
# LIBDIRS = -lSDL2  -lSDL2_image -llua
# INCDIRS = 
CC = g++
DEBUG = -g


all: ${BIN}

run: ${BIN}
	./${BIN}


${BIN}: ${OBJ}
	${CC} -o $@ ${OBJ} ${INCDIRS} ${LIBDIRS} ${LIBS}


%.o : %.cpp
	g++ -c $*.cpp -o $*.o 

DEBUG: ${OBJ}
	${CC} ${DEBUG} -o $@ ${OBJ} ${INCDIRS} ${LIBDIRS} ${LIBS}

clean:
	rm -rf ${BIN} ${OBJ}

