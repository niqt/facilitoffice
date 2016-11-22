CC = gcc
CXX = g++
INCPATH = -I /usr/include/festival -I /usr/include/speech_tools -I ./
LIBS = -lFestival -lestools -lestbase -leststring -lesd -lncurses
LFLAGS = -shared -W -fPIC
NAME = libspeak.so
TESTSOURCE = test.c
TESTNAME = test

SOURCES = \
	speak.cpp

speak.o: 
	$(CXX) -fPIC -c $(SOURCES) $(INCPATH)

all: 
	$(CXX) $(LFLAGS) -o $(NAME) speak.o $(LIBS) 
	echo "Library created, now move it"
	mv lib* ../lib

clean:
	rm -rf *.o *~ $(TESTNAME)

test:
	$(CXX) $(TESTSOURCE) -o $(TESTNAME) $(INCPATH) $(LIBS) -L ../lib -lspeak
