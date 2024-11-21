CC = g++
CFLAGS += -Wall

BIN =table_2
SRC =${BIN}.cpp


all: compile test
compile:
	${CC} ${CFLAGS} ${SRC} -o ${BIN}
test:
	echo "5 9 1 2 1 3 1 1 1 2 1 10 2 1 2 2 1 2 2 2 2 1 7 3 1 1 1 1 2 1 9 4 2 3 1 2 1 1 1 1 7 1 2 1 4 1 2 1" | ./${BIN}

clean:
	rm -f ${BIN}	
