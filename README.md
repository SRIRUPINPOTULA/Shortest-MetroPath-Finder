# Shortest_MetroPath
In Bengaluru Metro, inorder move to from one to another the feasible transport for every bangalorien is Namma Metro. This metro line currently operates in green and purple lines. These both metro lines have a common merge point from which is Majestic Station and diverge to various routes from there. 
The main of this implementation is to find the path between any two stations where stations are irrespective of green or purple lines. 
Since, there is a shuffle of passengers from green line metro to purple line metro it is atmost important to indicate that transfer is done at majestic station.
The complete implemenatiton is written in C++ which relates to the code in directory "Shortest Path in C++". 

**Method - 1:**

A. Methodology Adapted: 
  In this implementation, it is considered to develope a graph where the edges are the path between any two metro stations and stations are graph nodes. 

B. Algorithms Used: 
1. BFS 
2. Dijkstra's Algorithm

C. Implemenation:
  An approach of menu-driven program is presented that gives the user to select various options to display the various stations to print the shortest path.

D. Compilation: 
Command Used: 1. clang++ -std=c++11 main.cpp -o main
              2. ./main

**Method - 2:**

To enhance user experience and provide a more intuitive interface, the existing C++ implementation of the shortest path finder has been integrated into a graphical user interface (GUI) using Qt (which can be found in Shortest_Path directory for further details). This transition allows users to input the source and destination stations via text entry bars.

Additionally, a dropdown menu has been introduced, offering users several options for interaction:
1. List of All Stations: This option provides users with a comprehensive list of all available stations.
2. Stations by Line: Users can select either the green or purple line to view the stations exclusively belonging to that line.
3. Algorithm Selection: The GUI offers a choice between two algorithms: Breadth First Search and Dijkstra's Algorithm, enabling users to select the preferred method for finding the shortest path.
4. Path Finding: Upon inputting the source and destination stations and selecting the algorithm, users can initiate the process of finding the shortest path. The GUI displays the path along with the total distance between the source and destination stations.

Furthermore, the GUI incorporates a prompt mechanism that dynamically suggests whether the user should consider changing lines based on the destination station. This feature enhances user guidance, ensuring a smoother navigation experience throughout the transit system.

A sample image would look like:
<img width="799" alt="image" src="https://github.com/SRIRUPINPOTULA/Shortest-MetroPath-Finder/assets/58518732/7cf0968c-43a1-4071-82d9-8c1cbab54560">
