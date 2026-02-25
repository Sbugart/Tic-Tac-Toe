# Tic-Tac-Toe Bot using Minimax (C++)

A terminal-based Tic-Tac-Toe game implemented in C++ featuring an AI opponent powered by the Minimax algorithm.

This project was developed with a strong focus on object-oriented design, clean architecture, and modularity.

---

## 🧠 Features

- Object-Oriented Architecture
- Minimax decision algorithm (perfect-play AI)
- Polymorphic player system (Human vs AI)
- Clean separation of responsibilities
- Terminal-based interface

---

## 🏗 Architecture Overview

The project follows a modular class-based design:

- **GameController** – Manages the game lifecycle and flow control
- **Game** – Handles turn logic and player interaction
- **Board** – Manages board state, move validation, and win detection
- **Player** – Abstract player interface
- **MiniMax** – AI implementation using recursive Minimax
- **Human** – Human-controlled player implementation

The architecture emphasizes low coupling and high cohesion between components.

---

## 📊 UML Diagram

The system was designed following the UML class diagram:


![Class Diagram](docs/class_diagram.PDF)

---

## 🚀 How to Build

Compile using:

```bash
g++ main.cpp src/*.cpp -o tictactoe

./tictactoe