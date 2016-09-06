CC=g++ # TODO if g++ not available compile with gcc (little adjustment)
CFLAGS= #-Wall
LDFLAGS=
pkg-config=`pkg-config --libs --cflags gtk+-2.0`
SOURCES=gui.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=AFaker.o

# $(EXECUTABLE): $(OBJECTS)
# 	$(CC) $(CFLAGS) $(pkg-config) $(OBJECTS) -o $@

# .cpp.o:
# 	$(CC) $(CFLAGS) $(pkg-config) $< -o $@

all:
	$(CC) $(CFLAGS) $(pkg-config) $(SOURCES) -o $(OBJECTS)

gui:
	$(CC) $(CFLAGS) -o gui.o gui.cpp $(pkg-config)

clean:
	rm *.o




