
FLAGS = -pedantic-errors -std=c++11

card.o: card.cpp card.hpp
    g++ $(FLAGS) -c $<

flow.o: flow.cpp flow.hpp card.hpp
    g++ $(FLAGS) -c $<

main.o: main.cpp flow.hpp card.hpp
    g++ $(FLAGS) -c $<

blackjack: main.o flow.o card.o
    g++ $(FLAGS) $^ -o $@

clean:
    rm -f flow.o card.o main.o main

.PHONY: clean
