CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla
OBJECTS = bonus.o dpll.o tseitinTransformer.o tokenizer.o treeNode.o parser.o # add if needed
DEPENDS = ${OBJECTS:.o=.d}
EXEC = bonus

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies

