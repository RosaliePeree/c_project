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

OBJS    = exo3 exo4 exo5-1 exo5-2 exo6 exo7 exo8 exo12

all: $(OBJS)

%: $(SRC)/%.c $(BIN)
	@echo --- Compile ---
	$(CC) $< $(CFLAG) $(BIN)/$@
	
$(BIN):
	mkdir $@

clean : 
	@echo --- Nettoyage des fichiers temporaires --- 
	@-$(RM) $(BIN)/*