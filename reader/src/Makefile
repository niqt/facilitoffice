#


SPEAK_INCLUDE = ../../speak

SPEAK_LIB_DIR = ../../lib 

CXX	= g++
LFLAGS	= -L $(SPEAK_LIB_DIR) -lspeak -lrt 
PROG_NAME = ../bin/reader
PROGS_O	= main.o
INC_PATH = -I ../include -I $(SPEAK_INCLUDE)

CFLAGS += $(INC_PATH)

all:    objs progs

progs : 
	$(CXX)  $(CFLAGS) $(LFLAGS) -o $(PROG_NAME) $(PROGS_O) 
	
objs:   $(PROGS_O)

.cpp.o:
	$(CXX) -g $(CFLAGS) -c -o $*.o $< 

.o:
	$(CXX) -g $(CFLAGS) $(LFLAGS) -o $* $(PROGS_O)


