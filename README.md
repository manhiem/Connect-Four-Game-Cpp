# C-0-nn-3-ct Four Game
Connect Four

## Table of Contents
- Introduction
- Features
- How to Play
- C++ Concepts Used
- Dependencies
- Installation
- Usage
- Contributing
- License

### Introduction
"C-0-nn-3-ct Four" is a command-line-based Connect Four game implemented in C++. The game allows two players to take turns and compete to connect four of their colored discs in a row, either horizontally, vertically, or diagonally, on a grid of 7 columns and 6 rows. The player who connects four discs first wins the game.

This project is a simple yet fun implementation of the classic Connect Four game, showcasing various C++ concepts and techniques.

### Features
Two-player gameplay: Play against a friend and compete to connect four discs in a row.
Colorful board: The game uses ANSI escape sequences to display colored discs for each player (red and yellow).
Win detection: The game automatically detects a winning sequence of four discs for any player and declares the winner.
User-friendly interface: Clear and concise messages guide players through the gameplay.

### How to Play
Setup: Run the game, enter the names of Player 1 (Red) and Player 2 (Yellow), and choose their respective colors.

Gameplay: Players take turns to enter the column number (1 to 7) where they want to drop their colored disc. The disc will fall to the lowest available position in that column.

Win Condition: The game checks after each move if any player has successfully connected four discs horizontally, vertically, or diagonally. If a winning sequence is found, the game ends, and the winning player is declared.

End of Game: The game stops and displays the "CONGO!" message when any player wins.

### C++ Concepts Used
This Connect Four game showcases various C++ concepts, including:

- Object-Oriented Programming (OOP): The game is structured using classes and objects to represent players and the game board.
- Vectors: A 2D vector is used to represent the game board, which efficiently manages the game state.
- Loops and Conditionals: For game flow control and win condition checks.
- User Input Handling: The game takes user input to make moves and interact with the players.
- ANSI Escape Sequences: Used to display colored text for player discs and to clear the terminal for a better user experience.

### Dependencies
The game has no external dependencies and can be compiled and run using a C++ compiler (e.g., g++).

### Installation
1. Clone the repository
2. Navigate to the project directory
3. g++ -o connect_four connect_four.cpp

### Usage
1. Run the executable file.
2. Follow the instructions displayed in the terminal to enter player names and colors.
3. Play the game by entering the column number where you want to drop your disc.
4. The game will automatically detect the winner and stop when any player connects four discs in a row.

### Contributing
Contributions are welcome! Feel free to open issues for bug reports or feature requests. If you'd like to contribute code, please fork the repository and submit a pull request.

