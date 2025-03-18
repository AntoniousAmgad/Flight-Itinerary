CPP = g++

TARGET = flight_map

SRC = main.cpp flightMap.cpp type.cpp

HEADERS = flightMap.h type.h

OBJ = main.o flightMap.o type.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CPP) -o $(TARGET) $(OBJ)

main.o: main.cpp $(HEADERS)
	$(CPP) -c main.cpp

flightMap.o: flightMap.cpp $(HEADERS)
	$(CPP) -c flightMap.cpp

clean:
	rm -f $(OBJ) $(TARGET)
