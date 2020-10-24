EXEC_NAME=tictactoe
C_FLAGS=-Wall
L_FLAGS=-lSDL2

$(EXEC_NAME): Grid.o main.o Window.o XO.o
	g++ Grid.o main.o Window.o XO.o -o $(EXEC_NAME) $(L_FLAGS)

Grid.o: DrawGrid.hpp Grid.cpp
	g++ $(C_FLAGS) -c Grid.cpp

main.o: main.cpp
	g++ $(C_FLAGS) -c main.cpp

Window.o: Window.cpp
	g++ $(C_FLAGS) -c Window.cpp

XO.o: XO.cpp
	g++ $(C_FLAGS) -c XO.cpp

clean:
	rm *.o $(EXEC_NAME)
