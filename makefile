CC = clang++
INCLUDEPATHS = -I./Inc \
			   -I./Dependencies/FredLib/Inc \
			   -I/usr/include/SDL2 \
			   -I/usr/include/GL -I/usr/include/libdrm 

COMPILEFLAGS = -std=gnu++14 -Wall -pthread -g
PROJECTNAME = FreddieLib
EXE_NAME = $(PROJECTNAME).out
TESTS_EXE_NAME = $(PROJECTNAME).test

TEST_INCLUDE_PATHS = \
					 -I./Dependencies/googletest/googletest/include \
					 -I./Dependencies/googletest/googlemock/include 

TEST_OBJECTS = \
			   ./Dependencies/googletest/googletest/libgtest.a \
			   ./Dependencies/googletest/googlemock/libgmock.a

COMPILEFLAGS = -std=gnu++14 \
			   -Wall \
			   -pthread \
			   -g \

LINK_LIBS = -lSDL2 \
			-lGLEW -lGLU -lGL \
			-lassimp

# cpp source files and compiled objects
CPP_SRC = $(shell find Src -name "*.cpp")
TEST_SRC = $(shell find Test -name "*.cpp")
MESH_SRC = $(shell find Blend -name "*.blend")

CPP_UNITS = $(CPP_SRC:%.cpp=%.o)
TEST_UNITS = $(TEST_SRC:%.cpp=%.o)
MESH_UNITS = $(MESH_SRC:%.blend=%_0.obj)

MAKEFILES = $(shell find Makefiles -name "*.makefile")
DEPENDANCY_FILES = $(CPP_SRC:%.cpp=%.d) $(TEST_SRC:%.cpp=%.d)

all: $(EXE_NAME)

test: $(TESTS_EXE_NAME)

run: $(EXE_NAME) $(MESH_UNITS)
	./$(EXE_NAME)

runTest: $(TESTS_EXE_NAME)
	./$(TESTS_EXE_NAME)

runTestBreak: $(TESTS_EXE_NAME)
	./$(TESTS_EXE_NAME) --gtest_break_on_failure

include $(MAKEFILES)
-include $(DEPENDANCY_FILES)

$(EXE_NAME): $(CPP_UNITS)
	@ echo "Compiling main runtime"
	@ $(CC) $(CPP_UNITS) \
		$(LINK_LIBS) \
		$(INCLUDEPATHS) \
		$(COMPILEFLAGS) \
		-o $(EXE_NAME)

$(TESTS_EXE_NAME): $(EXE_NAME) $(TEST_UNITS) 
	@ echo "Compiling test runtime"
	@ $(CC) \
		$(LINK_LIBS) \
		$(TEST_UNITS) \
		$(filter-out Src/main.o, $(CPP_UNITS)) \
		$(TEST_OBJECTS) \
		$(INCLUDEPATHS) \
		-I$(GTEST_HEADER) \
		-I$(GMOCK_HEADER) \
		$(COMPILEFLAGS) \
		-o $(TESTS_EXE_NAME)

clean:
	rm -rf $(CPP_UNITS) $(TEST_UNITS) $(DEPENDANCY_FILES) **/*.obj **/*.mtl
