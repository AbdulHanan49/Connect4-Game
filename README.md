# Connect 4 Game

Welcome to the **Connect 4 Game**! This is a console-based implementation of the classic **Connect 4** game where two players take turns dropping their tokens into a grid to connect four in a row (horizontally, vertically, or diagonally).

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [How to Run](#how-to-run)
- [Gameplay](#gameplay)
  - [How to Play](#how-to-play)
  - [Example Board](#example-board)
  - [Example Output](#example-output)
- [Code Overview](#code-overview)
- [Contributing](#contributing)
  
## Overview

This game provides a two-player experience where users can:
- Enter custom names for Player 1 and Player 2.
- Take turns selecting a column to drop their tokens.
- Watch real-time token drop animations.
- Automatically detect the winner (or a draw) based on the grid.

## Features

- Two-player local gameplay.
- Winner detection for horizontal, vertical, and diagonal matches.
- Animated token drop simulation.
- Simple and interactive console interface.

## How to Run

### Prerequisites
1. Install a C++ compiler (e.g., `g++`).
2. Ensure a terminal or console is available.

### Steps
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/Connect4-Game.git
   cd Connect4-Game

    Compile the code:

g++ -o connect4 game.cpp

Run the game:

    ./connect4

Gameplay
How to Play

    Players enter their names at the start of the game.
    On their turn, each player selects a column (1–7) to drop their token (X or O).
    The game continues until:
        A player connects four tokens in a row.
        The grid is completely filled, resulting in a draw.

Example Board

     ======================================
                   CONNECT 4
     ======================================

       1   2   3   4   5   6   7
     +---+---+---+---+---+---+---+
     | - | - | - | - | - | - | - |
     +---+---+---+---+---+---+---+
     | - | - | - | - | - | - | - |
     +---+---+---+---+---+---+---+
     | - | - | - | - | - | - | - |
     +---+---+---+---+---+---+---+
     | - | - | - | - | - | - | - |
     +---+---+---+---+---+---+---+
     | - | - | - | - | - | - | - |
     +---+---+---+---+---+---+---+
     | X | - | - | - | - | - | - |
     +---+---+---+---+---+---+---+

Example Output

WELCOME TO THE CONNECT 4 GAME!
======================================
Enter name for Player 1: Alice
Enter name for Player 2: Bob

Alice's turn (X). Choose a column: 3
Board Updated...
Bob's turn (O). Choose a column: 3
Board Updated...

Hurrah!! Alice Wins the Game!

Code Overview

The game logic is encapsulated in the Connect4 structure, with the following key components:

    Initialization
    Sets up the game board and player data.

    Game Loop
    Manages turn-based play, input validation, and winner checks.

    Winner Detection
    Identifies four connected tokens horizontally, vertically, or diagonally.

    Functions
        initialize: Prepares the board.
        displayBoard: Prints the grid.
        makeMove: Validates and performs the token drop.
        simulateDrop: Animates the drop effect.
        checkWinner: Determines the game outcome.

Contributing

Contributions are welcome! Please follow these steps:

    Fork the repository.
    Create a new branch: git checkout -b feature-name.
    Commit your changes: git commit -m 'Add new feature'.
    Push to the branch: git push origin feature-name.
    Create a pull request.
