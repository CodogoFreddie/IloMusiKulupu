CC = clang++
INCLUDEPATHS = -I./Inc $(shell sdl2-config --cflags)
COMPILEFLAGS = -std=gnu++11 -pthread -g -Wall -pg $(INCLUDEPATHS)
LIBRARYFLAGS = -pthread -lpthread $(shell sdl2-config --libs) -lGLEW -lGL
EXE_NAME = CityProject.out
TESTS_EXE_NAME = CityProject.test

G_TEST_FOLDER = ../gtest/googletest
G_TEST_LIBRARY = ../gtest/googletest/libgtest.a
G_TEST_INCLUDES = ../gtest/googletest/include

G_MOCK_FOLDER = ../gtest/googlemock
G_MOCK_LIBRARY = ../gtest/googlemock/libgmock.a
G_MOCK_INCLUDES = ../gtest/googlemock/include

# cpp source files and compiled objects
CPPSRC = $(shell find Src -name "*.cpp")
TEST_SRC = $(shell find Test -name "*.cpp")
CPPOBJ = $(CPPSRC:%.cpp=%.o)
TEST_OBJ = $(TEST_SRC:%.cpp=%.o)

DEPENDANCY_FILES = $(CPPSRC:%.cpp=%.d) $(TEST_SRC:%.cpp=%.d)

.PHONY: all
all: $(EXE_NAME)

$(EXE_NAME): $(CPPOBJ)
	$(CC) $(CPPOBJ) -o $(EXE_NAME) $(LIBRARYFLAGS) $(INCLUDEPATHS)

.PHONY: run
run: $(EXE_NAME)
	./$(EXE_NAME)

.PHONY: test
test: MockFramework $(TEST_OBJ) $(filter-out "Src/main.o", $(CPPOBJ))
	$(CC) $(filter-out Src/main.o, $(CPPOBJ)) \
	$(TEST_OBJ) $(G_TEST_LIBRARY) $(G_MOCK_LIBRARY) \
	-o $(TESTS_EXE_NAME) $(LIBRARYFLAGS) \
	-I $(INCLUDEPATHS) -I $(G_TEST_INCLUDES) -I $(G_MOCK_INCLUDES)

.PHONY: runTest
runTest: test
	./$(TESTS_EXE_NAME)

.PHONY: MockFramework
MockFramework: $(G_TEST_FOLDER) $(G_TEST_LIBRARY) $(G_TEST_INCLUDES)\
	$(G_MOCK_FOLDER) $(G_MOCK_LIBRARY) $(G_MOCK_INCLUDES)

-include $(DEPENDANCY_FILES)

Src/%.o: Src/%.cpp
	@ echo "Compling Source: $<"
	@ $(CC) -c $< -o $@ $(COMPILEFLAGS) -I $(INCLUDEPATHS)

Test/%.o: Test/%.cpp $(G_TEST_INCLUDES) $(G_MOCK_LIBRARY)
	@ echo "Compiling Test: $<"
	@ $(CC) -c $< \
	-I $(INCLUDEPATHS) -I $(G_TEST_INCLUDES) -I $(G_MOCK_INCLUDES) \
	-o $@ $(COMPILEFLAGS)

%.d: %.cpp
	@ echo "Generating Dependancy File For: $<"
	@ $(CC) -c $< \
	-I $(INCLUDEPATHS) -I $(G_TEST_INCLUDES) -I $(G_MOCK_INCLUDES) \
	$(COMPILEFLAGS) \
	-MM -MT $(subst .d,.o,$@) -MF $@

clean:
	rm -f $(EXE_NAME)
	rm -f $(CPPOBJ) $(TEST_OBJ)
	rm -f $(DEPENDANCY_FILES)
	rm -f Scripts/includeDependancies

.PHONY: apt-get
apt-get:
	sudo aptitude install libglew-dev libsdl2-dev libsdl2-image-dev libglm-dev libfreetype6-dev

$(G_TEST_FOLDER):
	git clone git@github.com:google/googletest.git ../gtest

$(G_TEST_LIBRARY): $(G_TEST_FOLDER)
	cd ../gtest/googletest/ ; \
	cmake . ; \
	make ;

$(G_TEST_INCLUDES): $(G_TEST_FOLDER)

$(G_MOCK_FOLDER):
	git clone git@github.com:google/googletest.git ../gtest

$(G_MOCK_LIBRARY): $(G_MOCK_FOLDER)
	cd ../gtest/googlemock/ ; \
	cmake . ; \
	make ;

$(G_MOCK_INCLUDES): $(G_MOCK_FOLDER)
