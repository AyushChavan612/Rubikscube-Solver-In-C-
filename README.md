# Rubik's Cube Optimal Solver in C++

An ultra-fast, highly optimized Rubik's Cube solver written from scratch in C++. This project implements advanced search algorithms and heavily optimized data structures to find the mathematically optimal (shortest) solution to a scrambled Rubik's Cube.

## Features

* **Multiple Internal Models:** Choose from 3D Arrays, 1D Arrays, or a blazing-fast 64-bit integer **Bitboard** representation.
* **Optimal Solvers:** Includes implementations of standard BFS, DFS, IDDFS, and a highly pruned **A* (A-Star)** search algorithm.
* **Pattern Databases (Heuristics):** Generates and utilizes massive Mathematical Pattern Databases (Corners and Edges) to drastically prune the search tree.
* **Multithreading:** Utilizes C++ `std::thread` for parallel generation of multiple pattern databases, cutting load times in half.
* **Cross-Platform Build:** Uses CMake for seamless compiling on Linux, Windows, or macOS.

---

## Project Architecture

This project is built using modern C++17 and is divided into three core components:

### 1. The Models (`/Models`)
* **`ThreeDArrayModel`:** A visual and intuitive 3x3x3 character array representation.
* **`OneDArrayModel`:** A flattened 54-element array for faster memory access.
* **`BitBoardModel`:** The flagship model. It compresses the entire state of the Rubik's Cube into a few 64-bit integers, allowing for incredibly fast bitwise operations during the search phase.

### 2. The Pattern Databases (`/PatternDatabase`)
To give the A* search its "intelligence", the engine pre-computes the exact distance to the solved state for specific sub-components of the cube.
* **Corner Database:** Tracks the permutation and orientation of all 8 corners.
* **Edge Databases:** Two separate databases that track 6 edges each, utilizing custom encoding/decoding logic to map exact physical states to unique array indices.

### 3. The Solvers (`/Solvers`)
* **A* Search (`AStar.hpp`):** Uses the `max()` of the Pattern Databases as an admissible heuristic to guarantee the shortest possible path to the solved state.

---

## Getting Started

### Prerequisites
To build and run this project, you will need:
* A modern C++ compiler (GCC, Clang, or MSVC) with **C++17 support**.
* **CMake** (version 3.10 or higher).
* **Make** (for Linux/macOS users).

### Building the Project
This project uses an out-of-source CMake build to keep the directory clean. Run the following commands in your terminal from the root of the project:

```bash
# 1. Create a build directory
mkdir build
cd build

# 2. Generate the build files via CMake
cmake ..

# 3. Compile the code (Using multi-core compilation if available)
make