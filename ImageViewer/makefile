
CXX = g++
#CXX = clang++

CXX_FLAGS = -lGL -ldl `sdl2-config --libs`
CXX_FLAGS += -g -Wall -Wformat

SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ./lib

SRC_FILES = $(wildcard ${SRC_DIR}/*.cpp) $(wildcard ${SRC_DIR}/*/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

EXEC = ImageViewer

main: setup ${OBJ_FILES}
	${CXX} ${CXX_FLAGS} ${OBJ_FILES} -o ${EXEC}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	${CXX} ${CXX_FLAGS} -c -o $@ $<

setup:
	mkdir -p obj obj/files

cleanup:
	rm ${EXEC}
	rm -r ${OBJ_DIR}/*

run:
	./${EXEC}