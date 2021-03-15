#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

OBJECTS=snowman.o
OBJMAIN = main.o
SOURCES=snowman.cpp main.cpp

run: test
	./$^

product: $(OBJMAIN) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o product

test: TestRunner.o StudentTest1.o StudentTest2.o StudentTest3.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

StudentTest1.cpp:  # Yosef Danan
	curl https://raw.githubusercontent.com/YD5463/System-Programing-2/master/Test.cpp > $@

StudentTest2.cpp: # Shlomo Glick
	curl https://raw.githubusercontent.com/shlomog12/ex1_partA/main/Test.cpp > $@

StudentTest3.cpp: # Eviatar Nachshoni
	curl https://raw.githubusercontent.com/EN555/EX1-c-/master/Test.cpp > $@

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=* --

$(OBJMAIN): main.cpp snowman.hpp
	$(CXX) $(CXXFLAGS) --compile main.cpp -o $(OBJMAIN)

$(OBJECTS): snowman.cpp snowman.hpp
	$(CXX) $(CXXFLAGS) --compile snowman.cpp -o $(OBJECTS)

clean:
	rm -f *.o test
	rm -f StudentTest*.cpp
	rm -f product
