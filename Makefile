BIN = ./bin
OBJ = ./obj
SRC = ./src


all:
	gcc -c $(SRC)/Cripto.c -o $(OBJ)/Cripto.o
	gcc $(SRC)/main.c $(OBJ)/Cripto.o -o $(BIN)/cripto

run:
	@ $(BIN)/cripto

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/cripto
