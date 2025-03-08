CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp -o llrec.o

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp -o llrec-test.o

llrec-test: llrec.o llrec-test.o
	$(CXX) $(CXXFLAGS) llrec.o llrec-test.o -o llrec-test
clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 