# makefile
HOME= .
SRC= $(HOME)/src
ARCH = $(shell uname -s)-$(shell uname -m)
BIN = $(HOME)/bin/$(ARCH)
PROG = $(BIN)/compare.exe

#DEFS= -DDEBUG
CFLAGS = -Wall -c
CC = gcc
LD = gcc
LFLAGS = -Wall -I. -lm
RM = rm -f

OBJS = $(BIN)/main.o $(BIN)/exo.o
	
$(PROG): $(OBJS)
	@echo --- Linking ---
	$(LD) $(LDFLAGS) $(OBJS) -o $(PROG)

$(BIN)/main.o: $(SRC)/main.c
	@echo --- Compiling main.c---
	@[ -d $(BIN) ] || mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(DEFS) -c $(SRC)/main.c -o $(BIN)/main.o

$(BIN)/exo.o: $(SRC)/exo.c
	@echo --- Compiling exo.c ---
	$(CC) $(CFLAGS) -c $(SRC)/exo.c -o $(BIN)/exo.o
