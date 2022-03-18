# 1340-project
# group114

Topic: a text-based game

Group members:

Name: Chung Cheuk Man
UID: 3035928079

Name: Kwok Katia
UID: 3035927934

Game description and basic rules:

Background: Players will act as a player of blackjack in Macau 

Description: In this game, players are going to play blackjack.

Some instructions for the game: 
blackjack is a game that each player betting who get set of cards that is closest to 21. 
Players will be in certain games of blackjack and given $1000 at the beginning of the game.
One can choose to loan or not after each game.
if one lose all the money i.e. $0, one must get a loan from the mafia and pay the loan after 5 rounds. Or else, one will be excruciated and killed by mafia!
Each player will put a bet to start the game. Then one will draw 2 cards.
Players can choose to hit(take another card), stand(take none), double down(raise the bet by 100% and take only 1 more card), split(create two hands), surrender(give up half of the bet and end the game instantly),insurance(sidebet)



Features:
The program encompass the following coding elements:
1.Generation of random game sets or events:
- cards of player and opponent(s) each round


2. Data structures for storing game status:
- int(money,loan)
- char array(cards)
- string(story)
-array(status until last game)


3. Dynamic memory management:
- At the beginning of the game,  $1000 is given to each players. In the game whenever the player wins, it will be put into the array. 
- In the story mode, the size of the vector is returned to show the money and the progress that the player currently has.

4. File input/output (e.g., for loading/saving game status):
- During the game, player can choose to quit at any time. The money or loan of the player will thus be saved into several files.
- The player can start a new game at anytime with the money or loan stored in the latest game.

5. Program codes in multiple files:
The program will be saved in multiple files. The main cpp files are:
- main.cpp: the main logic of the game
- setup.cpp: covers assisting game set-ups such as initialization, saving and loading functions, etc.
- action.cpp: programmes of actions during the game.
Besides the above files, there will be many .txt files for UI and file I/O used, as well as Makefile and multiple header files.

C/C++ libraries:
Some libraries will be used in our program, listed as follows:
#include <iostream>: standart input/output
#include <fstream>: manipulation of files (story status saving and loading)
#include <string>: string manipulation
#include <iomanip>: setw(), setfill(), etc. (UI design)
#include <cstdlib>: rand(), srand() for generating randomness 
#include <ctime>: time(0) to set random seed
  
Compilation and execution of instructions:
Step 1: Aftering cloning the URL, type "play game" in the terminal and execute the main to start the game. 
Step 2: Follow the game instructions and enjoy the game!
