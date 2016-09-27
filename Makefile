CC=g++ # TODO if g++ not available compile with gcc (little adjustment)
CFLAGS=-std=c++11 -Wall -Wextra
LDFLAGS=
pkg-config=`pkg-config --libs --cflags gtk+-2.0`
SOURCES=0_view/gui.cpp main.cpp
HEADERS=0_view/gui.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=AFaker

# $(EXECUTABLE): $(OBJECTS)
# 	$(CC) $(CFLAGS) $(pkg-config) $(OBJECTS) -o $@

# .cpp.o:
# 	$(CC) $(CFLAGS) $(pkg-config) $< -o $@

all:
	$(CC) $(CFLAGS) $(pkg-config) $(SOURCES) -o $(EXECUTABLE)

main:
	$(CC) $(CFLAGS) -o main.o $(SOURCES) $(pkg-config)

clean:
	rm $(EXECUTABLE)




