CPPUNIT_PATH=/usr/local
GCC = g++ -std=c++14 -g

TARGET = countertest counterarraytest
SRCS   = counter.cpp
OBJS   = $(SRCS:.cpp=.o) main.o

all : $(TARGET)

countertest : countertest.o $(OBJS)
	$(GCC) -o $@ countertest.o $(OBJS) -L${CPPUNIT_PATH}/lib -lstdc++ -lcppunit -ldl

counterarraytest : counterarraytest.o $(OBJS)
	$(GCC) -o $@ counterarraytest.o $(OBJS) -L${CPPUNIT_PATH}/lib -lstdc++ -lcppunit -ldl

main.o : main.cpp
countertest.o : countertest.cpp countertest.h typedef.h
counterarraytest.o : counterarraytest.cpp countertest.h typedef.h
counter.o : counter.cpp counter.h typedef.h

%.o: %.cpp
	$(GCC) -c $*.cpp -I${CPPUNIT_PATH}/include

clean:
	rm -f *.o $(TARGET)
