/* 1.Show the metro map 2.View the stations 3.Find the intermediate stations based on the source and 
departure station 4.*/


#include <iostream>
#include<vector> 
#include <map>
#include <queue>
using namespace std;
class Graph { 
private: 
    vector<string>purple_line={"Baiyyapanahalli", "Swami Vivekananda Road", "Indiranagar","Halasuru","Trinity","Mahathma Gandhi Road","Cubbon Park","Dr.B.R. Ambedkar Staation","Sri M Visveswaraya Station, Central College","Nadaprabhu Kempegowda Station, Majestic","Krantivira Sangolli Rayanna Railway Station", "Magadi Road","Sri Balagangadharanatha Swaji Stn., Hosahalli", "Vijayanagar","Attiguppe","Deepanjali Nagar","Mysore Road","Nayandahalli","Rajarajeshwari Nagar","Jnanabharathi","Pattanagere","Kengeri Bus Terminal","Kengeri"};
    vector<string>green_line={"Nagasandra","Dasarahalli","Jalahalli","Peenya Industry","Peenya","Goraguntepalya","Yeshwanthpur","Sandal Soap Factory","Mahalakshmi",
        "Rajajinagar","Mahakavi Kuvempu Road","Srirammpura","Mantri Square Road","Nadaprabhu Kempegowda Station, Majestic","Chickpete","Krishna Rajendra Market","National College"
        ,"Lalbagh","South End Circle","Jayanagar","Rashtreeya Vidyalaya Road","Banashankari","Jaya Prakash Nagar","Yelachenahalli","Konanakunte Cross","Doddakallasandra"
        ,"Vajarahalli","Thalaghattapura","Silk Institute"};
    map<string, vector<string>> adjList;

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
    //Djikstra's Algorithm
    

};


int main() {
    
    Graph graph;
    vector<string>v1={"Baiyyapanahalli", "Swami Vivekananda Road", "Indiranagar","Halasuru","Trinity","Mahathma Gandhi Road","Cubbon Park","Dr.B.R. Ambedkar Staation","Sri M Visveswaraya Station, Central College","Nadaprabhu Kempegowda Station, Majestic","Krantivira Sangolli Rayanna Railway Station", "Magadi Road","Sri Balagangadharanatha Swaji Stn., Hosahalli", "Vijayanagar","Attiguppe","Deepanjali Nagar","Mysore Road","Nayandahalli","Rajarajeshwari Nagar","Jnanabharathi","Pattanagere","Kengeri Bus Terminal","Kengeri"};
    vector<string>v2={"Nagasandra","Dasarahalli","Jalahalli","Peenya Industry","Peenya","Goraguntepalya","Yeshwanthpur","Sandal Soap Factory","Mahalakshmi",
        "Rajajinagar","Mahakavi Kuvempu Road","Srirammpura","Mantri Square Road","Nadaprabhu Kempegowda Station, Majestic","Chickpete","Krishna Rajendra Market","National College"
        ,"Lalbagh","South End Circle","Jayanagar","Rashtreeya Vidyalaya Road","Banashankari","Jaya Prakash Nagar","Yelachenahalli","Konanakunte Cross","Doddakallasandra"
        ,"Vajarahalli","Thalaghattapura","Silk Institute"};
    // add nodes to the graph
    int n=v1.size();
    for(int i=0;i<n-1;i++)
    {
        graph.addEdge(v1[i],v1[i+1]);
    }
    
    int m=v2.size();
    for(int j=0; j < m-1 ; j++)
    {
        graph.addEdge(v2[j],v2[j+1]);
    }

    int choice=0;
    cout<<"1. List all the stations on Purple Line"<<"\n";
    cout<<"2. List all the stations on Green Line"<<"\n";
    cout<<"3. Print the Complete Map"<<"\n";
    cout<<"4. Find the distance between two stations"<<"\n";
    cout<<"5. Exit"<<"\n";
    string source;
    string destination;
    do{
        cout<< "Enter your choice: ";
        cin>>choice;
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
            cout << "Enter source node: ";
            cin >> source;
            cout << "Enter destination node: ";
            cin >> destination;
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
    
    return 0;
}
