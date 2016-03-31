CC = clang++
INCLUDEPATHS = -I./Inc
COMPILEFLAGS = -std=gnu++11 -Wall
EXE_NAME = IloMusiKulupu.out
TESTS_EXE_NAME = IloMusiKulupu.test

# cpp source files and compiled objects
CPP_SRC = $(shell find Src -name "*.cpp")
TEST_SRC = $(shell find Test -name "*.cpp")
CPP_UNITS = $(CPPSRC:%.cpp=%.o)
TEST_UNITS = $(TEST_SRC:%.cpp=%.o)

DEPENDANCY_FILES = $(CPP_SRC:%.cpp=%.d) $(TEST_SRC:%.cpp=%.d)
MAKEFILES = $(shell find Makefiles -name "*.makefile")

.PHONY: all
all: $(EXE_NAME)
	echo "what?"

$(EXE_NAME): $(CPP_UNITS) $(TEST_UNITS)



include $(MAKEFILES)
include $(DEPENDANCY_FILES)

#$(EXE_NAME): $(CPP_UNITS)
	#$(CC) $(CPP_UNITS) \
	#$(INCLUDEPATHS) \
	#$(COMPILEFLAGS) \
	#-o $(EXE_NAME)

#$(TESTS_EXE_NAME): $(CPP_UNITS) $(TEST_UNITS) 

clean:
	rm -rf $(CPP_UNITS) $(TEST_UNITS) $(DEPENDANCY_FILES)
