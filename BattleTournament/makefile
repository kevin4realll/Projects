output: Character.o Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o Tournament.o ListNode.o Lineup.o Graveyard.o main.o
	g++ Character.o Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o Tournament.o ListNode.o Lineup.o Graveyard.o main.o -o output

inputVal.o: inputVal.cpp inputVal.hpp
	g++ -c inputVal.cpp

Character.o: Character.cpp Character.hpp
	g++ -c Character.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c BlueMen.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -c Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -c Vampire.cpp

Tournament.o: Tournament.cpp Tournament.hpp inputVal.hpp
	g++ -c Tournament.cpp

ListNode.o: ListNode.cpp ListNode.hpp
	g++ -c ListNode.cpp

Lineup.o: Lineup.cpp Lineup.hpp
	g++ -c Lineup.cpp

Graveyard.o: Graveyard.cpp Graveyard.hpp
	g++ -c Graveyard.cpp

main.o: main.cpp inputVal.hpp
	g++ -c main.cpp

clean:
	rem* .o output
