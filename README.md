# Shortest_MetroPath
In Bengaluru Metro, inorder move to from one to another the feasible transport for every bangalorien is Namma Metro. This metro line currently operates in green and purple lines. These both metro lines have a common merge point from which is Majestic Station and diverge to various routes from there. 
The main of this implementation is to find the path between any two stations where stations are irrespective of green or purple lines. 
Since, there is a shuffle of passengers from green line metro to purple line metro it is atmost important to indicate that transfer is done at majestic station.
The complete implemenatiton is written in C++. 
A. Methodology Adapted: 
  In this implementation, it is considered to develope a graph where the edges are the path between any two metro stations and stations are graph nodes. 
B. Algorithms Used: 
1. BFS 
2. Dijkstra's Algorithm.
C. Implemenation:
  An approach of menu-driven program is presented that gives the user to select various options to display the various stations to print the shortest path.
D. Compilation: 
Command Used: 1. clang++ -std=c++11 main.cpp -o main
              2. ./main
