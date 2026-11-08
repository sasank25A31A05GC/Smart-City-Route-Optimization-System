# Smart City Route Optimization System

A simple C++17 mini-project that models a city as a weighted, undirected graph and finds the shortest route between two locations using Dijkstra's algorithm.

## Features
- Predefined sample city with six locations.
- Weighted roads represented by an adjacency list.
- Shortest route and total distance calculation.
- Route reconstruction using a parent array.
- Input validation for location IDs.

## ADS concepts
- Weighted Graph
- Adjacency List
- Min-Priority Queue (Binary Heap)
- Dijkstra's Shortest Path Algorithm

## Sample locations
| ID | Location |
|---:|---|
| 0 | College |
| 1 | Railway Station |
| 2 | Bus Stand |
| 3 | Government Hospital |
| 4 | City Center |
| 5 | Shopping Mall |

All distances in the sample graph are illustrative kilometres, not verified real-world road measurements.

## Compile and run
```bash
g++ -std=c++17 -O2 src/main.cpp -o smart_city
./smart_city
```
On Windows:
```bash
g++ -std=c++17 -O2 src/main.cpp -o smart_city.exe
smart_city.exe
```

## Sample input
```text
0
3
```

## Sample output
```text
Shortest route: College -> Bus Stand -> Government Hospital
Total distance: 13 km
```

## Algorithm
See [`docs/algorithm.txt`](docs/algorithm.txt).

## Flowchart and sample I/O
- [`assets/dijkstra_flowchart.png`](assets/dijkstra_flowchart.png)
- [`assets/sample_input_output.png`](assets/sample_input_output.png)

## Future enhancements
- Add/remove locations and roads dynamically.
- Block/unblock roads and recalculate routes.
- Add BFS, DFS and Prim's Minimum Spanning Tree.
- Build a web interface with a C++ REST API and an interactive map.
- Persist city data using JSON or SQLite.

## Team
- Sasank
- Venkatesh

## Note
This is the initial algorithm-focused version. The web application is planned as a future enhancement.
