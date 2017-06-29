CC=g++ # TODO if g++ not available compile with gcc (little adjustment)
CFLAGS=-std=c++11 -Wall -Wextra -L/usr/lib/x86_64-linux-gnu -lcurl
LDFLAGS=
pkg-config=`pkg-config --libs gtk+-2.0 --cflags gtk+-2.0`
SOURCES=0_view/gui.cpp 0_view/form.cpp 0_model/grabber.cpp tester.cpp main.cpp
HEADERS=0_view/gui.h 0_view/form.h 0_model/grabber.h tester.h
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




