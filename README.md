# 1340-project
# group114

Topic: a text-based game

Group members:

Name: Chung Cheuk Man
UID: 3035928079

Name: Kwok Katia
UID: 3035927934

Game description and basic rules:

Background: You are a loser and has nothing but to gamble everyday. This is your only way to get rid of the poor status. All you have is 1000HKD. You will act as a player of blackjack in Macau casino.

Description: In this game, players are going to play blackjack.blackjack is a game that each player betting who get set of cards that is closest to 21. Players will be in certain games of blackjack and given $1000 at the beginning of the game. One can choose to loan or not after each game. if one lose all the money i.e. $0, one must get a loan from the mafia and pay the loan after 5 rounds. Or else, one will be excruciated and killed by mafia!

Some instructions for the game:

    Flow of 1 round:
1. player will put a bet to start the game.
2. one will draw a point within 21.
3. Players can choose to do one of these action:
    1. hit(take another card)
    2. stand(take none)
    3. double down(raise the bet by 100% and take only 1 more card)
    4. surrender(give up half of the bet and end the game instantly, GOTO step 1 or borrow money or back to menu)
4. if the accumulated points of the cards are still small than 21, dealer will make its move
5. if the accumulated points are more than 21, player is lost and the word `bust` will be printed
6. if dealer and player both stand, then cards will be shown and winners are to be decided.
7. If they share the same point or both being greater than 21, none wins.



Features:
The program encompass the following coding elements:
1.Generation of random game sets or events:
- cards of player and dealer each round

2. Data structures for storing game status:
- int(money,loan,debt,due)
- array(cards)
- string(storyline)
- boolean(having debt or not)
- vector(status until last game, e.g. bet history, amount of money left, loan)

3. Dynamic memory management:
- At the beginning of the game,  $1000 is given to each players. In the game whenever the player wins, it will be put into the array.
- In the story mode, the size of the vector is returned to show the money and the progress that the player currently has.

4. File input/output (e.g., for loading/saving game status):
- During the game, player can choose to quit at any time. The money or loan of the player will thus be saved into several files.
- The player can start a new game at anytime with the money or loan stored in the latest game.

5. Program codes in multiple files:
The program will be saved in multiple files. The main cpp files are:
- main.cpp: the main logic of the game
- flow.cpp: covers assisting game set-ups such as initialization, saving and loading functions, etc.
- card.cpp: card dynamic during the game.
Besides the above files, there will be .txt files for UI and file I/O used, as well as Makefile and some header files.

C/C++ libraries:
Some libraries will be used in our program, listed as follows:
#include <iostream>: standard input/output
#include <fstream>: manipulation of files (status of player and storyline)
#include <string>: string manipulation
#include <iomanip>: setw(), setfill(), etc. (UI design)
#include <cstdlib>: rand(), srand() for generating randomness
#include <ctime>: time(0) to set random seed

Compilation and execution of instructions:
Step 1: Download the all the files in the github
Step 2: unzip it on any directory
step 3: set that directory to be the current one
Step 4: type `make blackjack` to construct the program in the terminal
step 5: type `./blackjack` to run the game
Step 6: enjoy the game!
