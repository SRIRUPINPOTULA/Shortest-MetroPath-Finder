/* 1.Show the metro map 2.View the stations 3.Find the intermediate 
stations based on the source and 
departure station 4.*/

Add distances between stations and compile the code.


#include <iostream>
#include<vector> 
#include <map>
#include <queue>
#include  <bits/stdc++.h>
using namespace std;
class Graph { 
private: 
    vector<string>purple_line = {"Baiyyapanahalli","Swami Vivekananda Road","Indiranagar","Halasuru",
    "Trinity","Mahathma Gandhi Road","Cubbon Park","Dr.B.R. Ambedkar Station",
    "Sri M Visveswaraya Station, Central College","Nadaprabhu Kempegowda Station, Majestic",
    "Krantivira Sangolli Rayanna Railway Station","Magadi Road","Sri Balagangadharanatha Swaji Stn., Hosahalli",
    "Vijayanagar","Attiguppe","Deepanjali Nagar","Mysore Road","Nayandahalli","Rajarajeshwari Nagar",
    "Jnanabharathi","Pattanagere","Kengeri Bus Terminal","Kengeri"
    };
    
    vector<string>green_line={"Nagasandra","Dasarahalli","Jalahalli","Peenya Industry","Peenya",
    "Goraguntepalya","Yeshwanthpur","Sandal Soap Factory","Mahalakshmi",
    "Rajajinagar","Mahakavi Kuvempu Road","Srirammpura","Mantri Square Road",
    "Nadaprabhu Kempegowda Station, Majestic","Chickpete","Krishna Rajendra Market","National College",
    "Lalbagh","South End Circle","Jayanagar","Rashtreeya Vidyalaya Road","Banashankari",
    "Jaya Prakash Nagar","Yelachenahalli","Konanakunte Cross","Doddakallasandra",
    "Vajarahalli","Thalaghattapura","Silk Institute"
    };
    map<string, vector<string>> adjList;
    int numVertices;
    unordered_map<string, int> stationIndices;
    vector<vector<pair<int, int>>> adjacencyList;

public: 

    void print_purple_stations(){
    int a=1;
    for (auto i:purple_line){
            cout<<a++<<". "<<i<<"\n";
         }
    }
    void print_green_stations(){
    int a=1;
    for (auto i:green_line){
            cout<<a++<<". "<<i<<"\n";
        }
    }
    void print_complete_map(){
        for (auto i:purple_line)
        {
            cout<<i<<" ";
        }
        for (auto i:green_line)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    void addEdge(string node1, string node2) {
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }
    void printAdjList() {
        for (auto node : adjList) {
            cout<< node.first << " -> ";
            for (auto neighbor : node.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    void findPath(string source, string destination) {
        queue<string> q;
        map<string, bool> visited;
        map<string, string> parent;

        q.push(source);
        visited[source] = true;
        parent[source] = "-1";

        while (!q.empty()) {
            string node = q.front();
            q.pop();

            if (node == destination) {
                // destination reached, print the path
                vector<string> path;
                while (node != "-1") {
                    path.push_back(node);
                    node = parent[node];
                }
                cout << "Path: ";
                for (int i = path.size()-1; i >= 0; i--) {
                    cout << path[i] << " ";
                }
                cout << endl;
                return;
            }

            for (auto neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }
        // destination not reachable from source
        cout << "Path not found." << endl;
    }
    //
    //Djikstra's Algorithm
    Graph() : numVertices(0) {}

    void addStation(const string& station) {
        stationIndices[station] = numVertices++;
        adjacencyList.resize(numVertices);
    }

    void addEdgelength(const string& source, const string& destination, int weight) {
        int sourceIndex = stationIndices[source];
        int destIndex = stationIndices[destination];
        adjacencyList[sourceIndex].push_back(make_pair(destIndex, weight));
        adjacencyList[destIndex].push_back(make_pair(sourceIndex, weight));
    }

    vector<string> dijkstra(const string& source, const string& destination) {
        int sourceIndex = stationIndices[source];
        int destIndex = stationIndices[destination];

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(numVertices, numeric_limits<int>::max());
        vector<int> parent(numVertices, -1);
        vector<bool> visited(numVertices, false);

        pq.push(make_pair(0, sourceIndex));
        distance[sourceIndex] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            visited[u] = true;

            for (const auto& neighbor : adjacencyList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!visited[v] && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }

        vector<string> shortestPath;
        int current = destIndex;
        while (current != -1) {
            shortestPath.push_back(getStationName(current));
            current = parent[current];
        }

        reverse(shortestPath.begin(), shortestPath.end());
        return shortestPath;
    }

private:
    string getStationName(int index) {
        for (const auto& entry : stationIndices) {
            if (entry.second == index) {
                return entry.first;
            }
        }
        return "";
    }

};


int main() {
    
    Graph graph;
    vector<string>v1 = {"Baiyyapanahalli","Swami Vivekananda Road","Indiranagar","Halasuru",
    "Trinity","Mahathma Gandhi Road","Cubbon Park","Dr.B.R. Ambedkar Station",
    "Sri M Visveswaraya Station, Central College","Nadaprabhu Kempegowda Station, Majestic",
    "Krantivira Sangolli Rayanna Railway Station","Magadi Road","Sri Balagangadharanatha Swaji Stn., Hosahalli",
    "Vijayanagar","Attiguppe","Deepanjali Nagar","Mysore Road","Nayandahalli","Rajarajeshwari Nagar",
    "Jnanabharathi","Pattanagere","Kengeri Bus Terminal","Kengeri"
    };
    
    vector<string>v2={"Nagasandra","Dasarahalli","Jalahalli","Peenya Industry","Peenya",
    "Goraguntepalya","Yeshwanthpur","Sandal Soap Factory","Mahalakshmi",
    "Rajajinagar","Mahakavi Kuvempu Road","Srirammpura","Mantri Square Road",
    "Nadaprabhu Kempegowda Station, Majestic","Chickpete","Krishna Rajendra Market","National College",
    "Lalbagh","South End Circle","Jayanagar","Rashtreeya Vidyalaya Road","Banashankari",
    "Jaya Prakash Nagar","Yelachenahalli","Konanakunte Cross","Doddakallasandra",
    "Vajarahalli","Thalaghattapura","Silk Institute"
    };
    int n=v1.size();
    for(int i=0;i<n-1;i++)
    {
        graph.addEdge(v1[i],v1[i+1]);
        graph.addStation(v1[i]);
    }
    
    int m=v2.size();
    for(int j=0; j < m-1 ; j++)
    {
        graph.addEdge(v2[j],v2[j+1]);
        graph.addStation(v2[i]);
    }
    
    /*graph.addStation("A");
    graph.addStation("B");
    graph.addStation("C");
    graph.addStation("D");
    graph.addStation("E");*/

    // Adding edges
    graph.addEdgelength("Baiyyapanahall", "Swami Vivekananda Road", 5);
    graph.addEdgelength("Swami Vivekananda Road", "Indiranagar", 5);
    graph.addEdgelength("Indiranagar","Halasuru",5);
    graph.addEdgelength("Halasuru","Trinity",5);
    graph.addEdgelength("Trinity","Mahathma Gandhi Road",5);
    graph.addEdgelength("Mahathma Gandhi Road","Cubbon Park",5);
    graph.addEdgelength("Cubbon Park", "Dr.B.R. Ambedkar Station", 2);
    graph.addEdgelength("Dr.B.R. Ambedkar Station", "Sri M Visveswaraya Station, Central College", 9);
    graph.addEdgelength("Sri M Visveswaraya Station, Central College", "Nadaprabhu Kempegowda Station, Majesti", 3);
    graph.addEdgelength("Nadaprabhu Kempegowda Station, Majesti", "Krantivira Sangolli Rayanna Railway Station", 4);
    graph.addEdgelength("Krantivira Sangolli Rayanna Railway Station","Magadi Road",);
    graph.addEdgelength("Magadi Road","Sri Balagangadharanatha Swaji Stn., Hosahalli",);
    graph.addEdgelength("Sri Balagangadharanatha Swaji Stn., Hosahalli","Vijayanagar",);
    graph.addEdgelength("Vijayanagar","Attiguppe",);
    graph.addEdgelength("Attiguppe","Deepanjali Nagar",);
    graph.addEdgelength("Deepanjali Nagar","Mysore Road",);
    graph.addEdgelength("Mysore Road","Nayandahalli",);
    graph.addEdgelength("Nayandahalli","Rajarajeshwari Nagar",);
    graph.addEdgelength("Rajarajeshwari Nagar","Jnanabharathi",);
    graph.addEdgelength("Jnanabharathi","Pattanagere",);
    graph.addEdgelength("Pattanagere","Kengeri Bus Terminal",);
    graph.addEdgelength("Kengeri Bus Terminal","Kengeri",);
    //Distance of Gree Line
    graph.addEdgelength("Nagasandra","Dasarahalli",);
    graph.addEdgelength("Dasarahalli","Jalahalli",);
    graph.addEdgelength("Jalahalli","Peenya Industry",);
    graph.addEdgelength("Peenya","Goraguntepalya",);
    graph.addEdgelength("Goraguntepalya","Yeshwanthpur",);
    graph.addEdgelength("Yeshwanthpur","Sandal Soap Factory",);
    graph.addEdgelength("Sandal Soap Factory","Mahalakshmi",);
    graph.addEdgelength("Mahalakshmi","Rajajinagar",);
    graph.addEdgelength("Rajajinagar","Mahakavi Kuvempu Road",);
    graph.addEdgelength("Mahakavi Kuvempu Road","Srirammpura",);
    graph.addEdgelength("Srirammpura","Mantri Square Road",);
    graph.addEdgelength("Mantri Square Road","Nadaprabhu Kempegowda Station, Majestic",);
    graph.addEdgelength("Nadaprabhu Kempegowda Station, Majestic","Chickpete",);
    graph.addEdgelength("Chickpete","Krishna Rajendra Market",);
    graph.addEdgelength("Krishna Rajendra Market","National College",);
    graph.addEdgelength("National College","Lalbagh",);
    graph.addEdgelength("Lalbagh","South End Circle",);
    graph.addEdgelength("South End Circle","Jayanagar",);
    graph.addEdgelength("Jayanagar","Rashtreeya Vidyalaya Road",);
    graph.addEdgelength("Rashtreeya Vidyalaya Road","Banashankari",);
    graph.addEdgelength("Banashankari","Jaya Prakash Nagar",);
    graph.addEdgelength("Jaya Prakash Nagar","Yelachenahalli",);
    graph.addEdgelength("Yelachenahalli","Konanakunte Cross",);
    graph.addEdgelength("Konanakunte Cross","Doddakallasandra",);
    graph.addEdgelength("Doddakallasandra","Vajarahalli",);
    graph.addEdgelength("Vajarahalli","Thalaghattapura",);
    graph.addEdgelength("Thalaghattapura","Silk Institute",);
    // Finding shortest path
    string source = "A";
    string destination = "E";
    vector<string> shortestPath = graph.dijkstra(source, destination);

    // Displaying shortest path
    cout << "Shortest path from " << source << " to " << destination << ": ";
    for (const auto& station : shortestPath) {
        cout << station << " -> ";
    }
    cout << "End" << endl;
    
    /*
    int choice=0;
    cout<<"1. List all the stations on Purple Line"<<"\n";
    cout<<"2. List all the stations on Green Line"<<"\n";
    cout<<"3. Print the Complete Map"<<"\n";
    cout<<"4. Find the distance between two stations"<<"\n";
    cout<<"5. Exit"<<"\n";
    do{
        cout<< "Enter your choice: ";
        cin>>choice;
        string source;
        string destination;
        
        
    switch(choice)
    {
        case 1:
            graph.print_purple_stations();
            break;
        case 2: 
            graph.print_green_stations();
            break;
        case 3:
            cout<<"The Bengaluru Metro Map!!!!"<<"\n";
            graph.printAdjList();
            break;
        case 4:
            cout<<"Available Stations are: "<<"\n";
            graph.print_complete_map();
            cout << "Enter the source station: ";
            getline(cin>>ws,source);
            cout<< "Enter the destination station: ";
            getline(cin>>ws,destination);
            graph.findPath(source, destination);
            break;
        case 5:
            cout<<"Thank you!!!";
            exit(0);
            break;
        default:
            cout<<"Please Enter a Correct Choice"<<"\n";
        
    }
    }while(choice);
    */
    
    return 0;
}
