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
<<<<<<< HEAD
	g++ -c $*.cpp -o $*.o  

debug: ${OBJ}
=======
	g++ -c $*.cpp -o $*.o 

DEBUG: ${OBJ}
>>>>>>> 14d86be... first start
	${CC} ${DEBUG} -o $@ ${OBJ} ${INCDIRS} ${LIBDIRS} ${LIBS}

clean:
	rm -rf ${BIN} ${OBJ}

