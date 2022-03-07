# 1340-project
# group114

Topic: a text-based story-telling game

Group members:

Name: Chung Cheuk Man
UID: 3035928079

Name: Kwok Katia
UID: 3035927934

Game description and basic rules:

Background: An adventure game happened in middle ages. Players can choose their own characters. 

Description: In this game, players are required to escape from the castle.

Some instructions for the game: 
Players can only go to the next room by passing the initial room.   
When players meet a monster, they can fight with or escape from the monster.
If players choose to escape, they may escape successfully or risk receiving damage from the monsters.
Players can quit the game at any time and retrive the last game one was in.

Features:
The program encompass the following coding elements:
1.Generation of random game sets or events:
- The characters in the castle are randomly generated in any room of a fixed room.
- The doors of each room are randomly generated in a fixed range of position.
- The attack power of the player and the monster are in a random range.
- The tools of players received are randomly distributed.

2. Data structures for storing game status:
- Integer(life value, attack power value, magic level, experience)
- Vector (list of tools that the player currently has)
- String (tool type, description etc.), 
- 3 structs (item, position, status) tracking tool information, position in the castle as well as player and monster status respectively.

3. Dynamic memory management:
- At the beginning of the game, the vector recording the tools the player has is empty. In the game whenever the player gets an item, it will be put into the vector. Whenever the player use an tool during a fight, the vector will push the item out. 
- The vector has certain size limit to prevent the player storing too many tools. 
- In the walking mode, the size of the vector is returned to show the number of tools that the player currently has.

4. File input/output (e.g., for loading/saving game status):
- In the walking mode, player can choose to escape at any time. The entire game will thus be saved into several files tracking the player's status, current castle information etc.
- At the beginning of the game, player can choose to start by the previous game, or to start a new game.

5. Program codes in multiple files:
The program will be saved in multiple files. The main cpp files are:
- main.cpp: the main logic of the game
- preGame.cpp: covers assisting game set-ups such as initialization, saving and loading functions, etc.
- playGame.cpp: mainly the walking mode and the fighting mode of the game.
Besides the above files, there will be many .txt files for UI and file I/O used, as well as Makefile and ultiple header files.

C/C++ libraries:
Some libraries will be used in our program, listed as follows:
#include <iostream>: standart input/output
#include <fstream>: manipulation of files (hero status saving and loading)
#include <string>: string manipulation
#include <iomanip>: setw(), setfill(), etc. (UI design)
#include <vector>: vector manipulation (dynamic array management)
#include <cstdlib>: rand(), srand() for generating randomness 
#include <ctime>: time(0) to set random seed
  
Compilation and execution of instructions:
Step 1: Aftering cloning the URL, type "play game" in the terminal and execute the main to start the game. 
Step 2: Follow the game instructions and enjoy the game!
