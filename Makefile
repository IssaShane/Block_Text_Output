CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD
EXEC=LETTERS
OBJECTS=main.o csv.o word_engine.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm *.o *.d
