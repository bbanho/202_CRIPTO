prog=bin
APPS = ./apps
BIN = ./bin
OBJ = ./obj
SRC = ./src

all:
	gcc -c $(SRC)/Cripto.c  -o $(OBJ)/Cripto.o -g
	gcc $(SRC)/main.c $(OBJ)/Cripto.o -o ./$(prog) -g

run:
	./$(prog)

clean:
	rm $(OBJ)/*.o
	rm ./$(prog)
