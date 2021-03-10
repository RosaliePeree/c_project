# makefile
HOME= .
BIN= $(HOME)/bin
SRC= $(HOME)/src

#DEFS= -DDEBUG
CFLAG = -Wall -o
CC= gcc
LD= gcc
LDFLAGS= -lm
RM = rm

OBJS    = exo1 exo2-1 exo2-2 exo2-3

all: $(OBJS)

%: $(SRC)/%.c $(BIN)
	@echo --- Compile ---
	$(CC) $< $(CFLAG) $(BIN)/$@
	
$(BIN):
	mkdir $@

clean : 
	@echo --- Nettoyage des fichiers temporaires --- 
	@-$(RM) $(BIN)/*