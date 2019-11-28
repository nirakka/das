CXX = g++ -std=c++14
all : use conv

use : use.o
	$(CXX) -o $@ use.o

conv : conv.o
	$(CXX) -o $@ conv.o

use.o : use.cpp typedef.h globl.h
	$(CXX) -c $*.cpp

conv.o : conv.cpp typedef.h globl.h
	$(CXX) -c $*.cpp

clean:
	-rm *.exe use.o conv.o
