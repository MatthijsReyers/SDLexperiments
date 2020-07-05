
CXX = g++
#CXX = clang++

SOURCES = main.cpp

EXEC = Painter

CXXFLAGS = -lGL -ldl `sdl2-config --libs`
CXXFLAGS += -g -Wall -Wformat

main:
	${CXX} ${CXXFLAGS} ${SOURCES} -o ${EXEC}

cleanup:
	rm ${EXEC}

demo: main
	./${EXEC}
	rm ${EXEC}