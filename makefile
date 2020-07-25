EXEC_NAME=tictactoe
C_FLAGS=-Wall
L_FLAGS=-lSDL2

tictactoe: main.o Window.o
	g++ main.o Window.o -o $(EXEC_NAME) $(L_FLAGS)

main.o: main.cpp
	g++ $(C_FLAGS) -c main.cpp

Window.o: Window.cpp
	g++ $(C_FLAGS) -c Window.cpp

clean:
	rm *.o $(EXEC_NAME)
