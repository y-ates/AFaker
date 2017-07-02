CC=g++ # TODO if g++ not available compile with gcc (little adjustment)
CFLAGS=-std=c++11 -Wall -Wextra -L/usr/lib/x86_64-linux-gnu -lcurl -I/usr/include/libxml2 -I/usr/include/glibmm-2.4 -I/usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/sigc++-2.0 -I/usr/lib/x86_64-linux-gnu/sigc++-2.0/include -I/usr/include/libxml++-2.6 -I/usr/lib/libxml++-2.6/include -lxml++-2.6 -lxml2 -lglibmm-2.4 -lgobject-2.0 -lglib-2.0 -lsigc-2.0
LDFLAGS=
pkg-config=`pkg-config --libs gtk+-2.0 --cflags gtk+-2.0`
# pkg-config libxml++-2.6 --cflags --libs
SOURCES=0_view/gui.cpp 0_view/form.cpp 0_model/grabber.cpp 0_model/parser.cpp tester.cpp main.cpp
HEADERS=0_view/gui.h 0_view/form.h 0_model/grabber.h 0_model/parser.h tester.h
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




