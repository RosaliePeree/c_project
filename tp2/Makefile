# makefile
HOME= .
BIN = $(HOME)/bin/$(ARCH)
SRC= $(HOME)/src
OBJ= $(HOME)/obj
ARCH = $(shell uname -s)-$(shell uname -m)


#DEFS= -DDEBUG
CFLAGS = -g -Wall
CC = gcc
LD = gcc
LDFLAGS = -lm
RM = rm

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c,%,$(SRCS))

all: $(OBJS) clean
	@echo All good!

%: %.o
	@echo --- Linking ---
	$(LD) $(LDFLAGS) $(BIN)/$< -o $(BIN)/$@

# Cible générique d'un objet
%.o: $(SRC)/%.c
	@echo --- Compiling .c---
	@[ -d $(BIN) ] || mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(DEFS) -c $< -o $(BIN)/$@

clean : 
	@echo --- Clean up temporary files --- 
	@-$(RM) $(BIN)/*.o