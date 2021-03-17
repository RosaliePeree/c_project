HOME= .
BIN = $(HOME)/bin/$(ARCH)
SRC= $(HOME)/src
OBJ= $(HOME)/obj
.c= $(SRC)/degre.c
ARCH = $(shell uname -s)-$(shell uname -m)

#DEFS= -DDEBUG
CFLAGS = -g -Wall
CC = gcc
LD = gcc
LDFLAGS = -lm
RM = rm

OBJS = testdegre1 testdegre2

all: $(OBJS) clean
	@echo All good!

%: %.o
	@echo --- Linking ---
	$(LD) $(BIN)/$< $(.c) -o $(BIN)/$@

# Cible générique d'un objet
%.o: $(SRC)/%.c
	@echo --- Compiling .c---
	@[ -d $(BIN) ] || mkdir -p $(BIN)
	$(CC) $(CFLAGS) -c $< -o $(BIN)/$@

clean : 
	@echo --- Clean up temporary files --- 
	@-$(RM) $(BIN)/*.o