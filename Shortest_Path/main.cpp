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
    vector<vector<pair<float, float>>> adjacencyList;

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

    void addEdgelength(const string& source, const string& destination, float weight) {
        int sourceIndex = stationIndices[source];
        int destIndex = stationIndices[destination];
        adjacencyList[sourceIndex].push_back(make_pair(destIndex, weight));
        adjacencyList[destIndex].push_back(make_pair(sourceIndex, weight));
    }

    void dijkstra(const string& source, const string& destination) {
        int sourceIndex = stationIndices[source];
        int destIndex = stationIndices[destination];

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<float> distance(numVertices, numeric_limits<int>::max());
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
                float weight = neighbor.second;

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
        for (const auto& station : shortestPath) {
        cout << station << " -> ";
        
    }
        cout<<""<<distance[destIndex];       
        cout << " End" << endl;        
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
        graph.addStation(v2[j]);
    }
    
  

    // Adding edges
    graph.addEdgelength("Baiyyapanahall", "Swami Vivekananda Road", 1.9);
    graph.addEdgelength("Swami Vivekananda Road", "Indiranagar", 1.4);
    graph.addEdgelength("Indiranagar","Halasuru",1.4);
    graph.addEdgelength("Halasuru","Trinity",1.1);
    graph.addEdgelength("Trinity","Mahathma Gandhi Road",5);
    graph.addEdgelength("Mahathma Gandhi Road","Cubbon Park",2.7);
    graph.addEdgelength("Cubbon Park", "Dr.B.R. Ambedkar Station", 0.6);
    graph.addEdgelength("Dr.B.R. Ambedkar Station", "Sri M Visveswaraya Station, Central College", 750);
    graph.addEdgelength("Sri M Visveswaraya Station, Central College", "Nadaprabhu Kempegowda Station, Majesti", 1.4);
    graph.addEdgelength("Nadaprabhu Kempegowda Station, Majesti", "Krantivira Sangolli Rayanna Railway Station", 2.3);
    graph.addEdgelength("Krantivira Sangolli Rayanna Railway Station","Magadi Road",2.3);
    graph.addEdgelength("Magadi Road","Sri Balagangadharanatha Swaji Stn., Hosahalli",1.3);
    graph.addEdgelength("Sri Balagangadharanatha Swaji Stn., Hosahalli","Vijayanagar",1.5);
    graph.addEdgelength("Vijayanagar","Attiguppe",1);
    graph.addEdgelength("Attiguppe","Deepanjali Nagar",2.3);
    graph.addEdgelength("Deepanjali Nagar","Mysore Road",4.5);
    graph.addEdgelength("Mysore Road","Nayandahalli",1.1);
    graph.addEdgelength("Nayandahalli","Rajarajeshwari Nagar",2.1);
    graph.addEdgelength("Rajarajeshwari Nagar","Jnanabharathi",3.0);
    graph.addEdgelength("Jnanabharathi","Pattanagere",2.8);
    graph.addEdgelength("Pattanagere","Kengeri Bus Terminal",4);
    graph.addEdgelength("Kengeri Bus Terminal","Kengeri",1.5);
    //Distance of Gree Line
    graph.addEdgelength("Nagasandra","Dasarahalli",1.4);
    graph.addEdgelength("Dasarahalli","Jalahalli",0.9);
    graph.addEdgelength("Jalahalli","Peenya Industry",0.8);
    graph.addEdgelength("Peenya","Goraguntepalya",1.9);
    graph.addEdgelength("Goraguntepalya","Yeshwanthpur",1.1);
    graph.addEdgelength("Yeshwanthpur","Sandal Soap Factory",2.5);
    graph.addEdgelength("Sandal Soap Factory","Mahalakshmi",1.1);
    graph.addEdgelength("Mahalakshmi","Rajajinagar",0.85);
    graph.addEdgelength("Rajajinagar","Mahakavi Kuvempu Road",1.7);
    graph.addEdgelength("Mahakavi Kuvempu Road","Srirammpura",0.4);
    graph.addEdgelength("Srirammpura","Mantri Square Road",2.5);
    graph.addEdgelength("Mantri Square Road","Nadaprabhu Kempegowda Station, Majestic",2.2);
    graph.addEdgelength("Nadaprabhu Kempegowda Station, Majestic","Chickpete",1.5);
    graph.addEdgelength("Chickpete","Krishna Rajendra Market",1.5);
    graph.addEdgelength("Krishna Rajendra Market","National College",1.8);
    graph.addEdgelength("National College","Lalbagh",2.1);
    graph.addEdgelength("Lalbagh","South End Circle",1.3);
    graph.addEdgelength("South End Circle","Jayanagar",1);
    graph.addEdgelength("Jayanagar","Rashtreeya Vidyalaya Road",900);
    graph.addEdgelength("Rashtreeya Vidyalaya Road","Banashankari",1.4);
    graph.addEdgelength("Banashankari","Jaya Prakash Nagar",0.8);
    graph.addEdgelength("Jaya Prakash Nagar","Yelachenahalli",1.4);
    graph.addEdgelength("Yelachenahalli","Konanakunte Cross",1.1);
    graph.addEdgelength("Konanakunte Cross","Doddakallasandra",1.6);
    graph.addEdgelength("Doddakallasandra","Vajarahalli",1.9);
    graph.addEdgelength("Vajarahalli","Thalaghattapura",1);
    graph.addEdgelength("Thalaghattapura","Silk Institute",1.4);
    
    
    int choice=0;
    cout<<"1. List all the stations on Purple Line"<<"\n";
    cout<<"2. List all the stations on Green Line"<<"\n";
    cout<<"3. Print the Complete Map"<<"\n";
    cout<<"4. Find the distance between two stations"<<"\n";
    cout<<"5. Display the Shortest Path and Distance between two stations"<<"\n";
    cout<<"6. Exit"<<"\n";
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
            cout<<"Print Available Stations: "<<"\n";
            graph.print_complete_map();
            cout<<"Enter the source station: ";
            getline(cin>>ws,source);
            cout<<"Enter the destination: ";
            getline(cin>>ws,destination);
            graph.dijkstra(source, destination);
        case 6:
            cout<<"Thank you!!!";
            exit(0);
            break;
        default:
            cout<<"Please Enter a Correct Choice"<<"\n";
        
    }
    }while(choice);
    
    
    return 0;
}
