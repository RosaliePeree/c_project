# makefile
HOME= .
BIN= $(HOME)/bin
SRC= $(HOME)/src

#DEFS= -DDEBUG
CFLAG = -Wall -o
CC= gcc
RM = rm

OBJS    = exo2-1 exo2-2 exo2-3 exo2-4

all: $(OBJS)

%: $(SRC)/%.c $(BIN)
	@echo --- Compile ---
	$(CC) $< $(CFLAG) $(BIN)/$@
	
$(BIN):
	mkdir $@

clean : 
	@echo --- Nettoyage des fichiers temporaires --- 
	@-$(RM) $(BIN)/*