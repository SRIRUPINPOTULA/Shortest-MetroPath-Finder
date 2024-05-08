#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>
using namespace std;

class Graph {
public:
    vector<string> purple_line;
    vector<string> green_line;
    map<string,vector<string>> adjList;
    int numVertices;
    unordered_map<string, float> stationIndices;
    vector<vector<pair<float, float>>> adjacencyList;


    Graph();
    string getPurpleStationsString();
    string getGreenStationsString();
    void print_green_stations();
    void print_complete_map();
    void addEdge(string node1, string node2);
    void printAdjList();
    void addStation(string station);
    void addEdgelength(string source, string destination, float weight);
    string getStationName(int index);
    string findPath(string source, string destination);
    string djikstra(string source, string destination);


};

#endif // GRAPH_H
