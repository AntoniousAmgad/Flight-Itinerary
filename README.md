# ✈️ Flight Map - BlueSky Airline

A C++ application that simulates a flight route system for BlueSky Airline. It allows users to load a list of cities and available flights, find valid flight paths between cities, and display detailed itineraries including total cost.

---

## 🚀 Features

- Load and store city and flight data from files
- Build a flight map (graph) from origin to destination cities
- Check if a city is served by the airline
- Search for a valid path between two cities using DFS
- Display a full itinerary with flight details and total cost
- Clean and modular C++ implementation using classes and STL

---

## 📁 Project Structure

- `flightMap.h`: Header file with class and struct declarations
- `flightMap.cpp`: Core logic and implementation
- `main.cpp`: (You can create this) Contains UI/menu and interaction
- `cities.txt`: Text file containing list of cities
- `flights.txt`: Text file containing flight information

---

## 🛠️ How to Build & Run

1. **Make sure you have a C++ compiler installed**  
   (e.g. g++, clang++, or use Visual Studio)

2. **Compile the code:**

   ```bash
   g++ *.cpp -o flightMapApp
---
##🧠 Concepts Used

- Graph Representation using Adjacency Lists

- Depth-First Search (DFS) for pathfinding

- Vectors, Stacks, Maps (STL)

- File I/O with ifstream

- Clean OOP design using constructors, destructors, and encapsulation
