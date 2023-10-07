Project : main.o keeper.o base.o
	g++ main.o keeper.o base.o -o Project

main.o : main.cpp
	g++ -c main.cpp -o main.o

base.o: Base.cpp
	g++ -c Base.cpp -o base.o

keeper.o: Keeper.cpp
	g++ -c Keeper.cpp -o keeper.o

clear : Project
