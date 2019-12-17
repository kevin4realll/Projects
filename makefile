output: Space.o Game.o Player.o Briefcase.o Office.o Market.o Hotel.o Yacht.o main.o
	g++ -std=c++11 Space.o Game.o Player.o Briefcase.o Office.o Market.o Hotel.o Yacht.o main.o -o output

Space.o: Space.cpp
	g++ -std=c++11 -c Space.cpp

Game.o: Game.cpp
	g++ -std=c++11 -c Game.cpp

Player.o: Player.cpp
	g++ -std=c++11 -c Player.cpp

Briefcase.o: Briefcase.cpp
	g++ -std=c++11 -c  Briefcase.cpp

Office.o: Office.cpp
	g++ -std=c++11 -c Office.cpp

Market.o: Market.cpp
	g++ -std=c++11 -c Market.cpp

Hotel.o: Hotel.cpp
	g++ -std=c++11 -c Hotel.cpp

Yacht.o: Yacht.cpp
	g++ -std=c++11 -c Yacht.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm*.o output

