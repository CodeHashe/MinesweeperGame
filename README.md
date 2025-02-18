# MinesweeperGame

A classic **Minesweeper** game built using **C++** and the **SFML** library.

## 📌 Features
- Classic Minesweeper mechanics
- Grid-based gameplay with mines, numbers, and flags
- Timer and mine counter
- Simple and intuitive UI
- Restart functionality

## 🛠️ Technologies Used
- **C++** for core game logic
- **SFML** for graphics and rendering

## 🚀 Installation & Setup
### Prerequisites
Ensure you have the following installed:
- C++ Compiler (G++/MSVC/Clang)
- SFML Library ([Download SFML](https://www.sfml-dev.org/download.php))

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/CodeHashe/MinesweeperGame.git
   cd MinesweeperGame
   ```
2. Install **SFML** (if not installed):
   ```bash
   sudo apt-get install libsfml-dev  # Linux
   brew install sfml                 # macOS
   ```
   For Windows, download and configure SFML manually.
3. Compile the game:
   ```bash
   g++ -o Minesweeper main.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```
4. Run the game:
   ```bash
   ./Minesweeper
   ```

## 🎮 How to Play
- Left-click to **reveal a tile**
- Right-click to **place a flag**
- Avoid clicking on mines!
- Win by revealing all non-mine tiles

## 📝 License
This project is licensed under the **MIT License**.

## 🤝 Contributing
Feel free to submit pull requests or report issues!

## 📬 Contact
For any questions, reach out via GitHub Issues or email.

Happy Coding! 🎉

