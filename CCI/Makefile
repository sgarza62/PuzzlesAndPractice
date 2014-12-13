UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
    CC=g++
    CFLAGS=-std=c++0x -lpthread -g -Wall
    BOOSTFLAGS=-lboost_system
endif

ifeq ($(UNAME), Darwin)
    CC=clang++
    CFLAGS=-std=c++11 -g -Wall -stdlib=libc++ -I/usr/local/include -L/usr/local/lib
    BOOSTFLAGS=-lboost_system-mt
endif


SRCS = $(wildcard *.cc)

all: $(SRCS:.cc=)

.cc:
	$(CC) $(CFLAGS) $(BOOSTFLAGS) $< -o $@

clean:
	rm -rf *.o 
