prog=bin
APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src


all:
	gcc -c $(SRC)/Cripto.c  -I $(INCLUDE)/ -o $(OBJ)/Cripto.o -g
	gcc $(SRC)/main.c $(OBJ)/Cripto.o -I $(INCLUDE) -o $(BIN)/$(prog) -g

run:
	$(BIN)/$(prog)

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*
