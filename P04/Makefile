CXXFLAGS = --std=c++17

all: flash_cards

flash_cards: card.o deck.o main.o *.h
	$(CXX) $(CXXFLAGS) card.o deck.o main.o -o flash_cards

card.o: card.cpp *.h
	$(CXX) $(CXXFLAGS) -c card.cpp -o card.o

deck.o: deck.cpp *.h
	$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o *.gch *~ a.out flash_cards