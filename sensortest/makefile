CPPUNIT_PATH=/usr/local
GCC = g++ -std=c++14 -g

TARGET = readSensorValuetest
SRCS   = readSensorValuetest.cpp readSensorValue.cpp
OBJS   = $(SRCS:.cpp=.o) main.o

all : $(TARGET)

$(TARGET): $(OBJS)
	$(GCC) -o $@ $(OBJS) -L${CPPUNIT_PATH}/lib -lstdc++ -lcppunit -ldl

main.o : main.cpp
readSensorValuetest.o : readSensorValuetest.cpp readSensorValueTest.h typedef.h
readSensorValue.o : readSensorValue.cpp readSensorValue.h typedef.h

%.o: %.cpp
	$(GCC) -c $*.cpp -I${CPPUNIT_PATH}/include

clean:
	-rm *.exe $(OBJS) $(TARGET)
