#include "graph.h"
using namespace std;
#include <sstream>
#include<queue>

Graph::Graph() : numVertices(0) {
    purple_line = {"Baiyyapanahalli","Swami Vivekananda Road","Indiranagar","Halasuru",
        "Trinity","Mahathma Gandhi Road","Cubbon Park","Dr.B.R. Ambedkar Station",
        "Sri M Visveswaraya Station, Central College","Nadaprabhu Kempegowda Station, Majestic",
        "Krantivira Sangolli Rayanna Railway Station","Magadi Road","Sri Balagangadharanatha Swaji Stn., Hosahalli",
        "Vijayanagar","Attiguppe","Deepanjali Nagar","Mysore Road","Nayandahalli","Rajarajeshwari Nagar",
        "Jnanabharathi","Pattanagere","Kengeri Bus Terminal","Kengeri"
    };
    green_line = {"Nagasandra","Dasarahalli","Jalahalli","Peenya Industry","Peenya",
        "Goraguntepalya","Yeshwanthpur","Sandal Soap Factory","Mahalakshmi",
        "Rajajinagar","Mahakavi Kuvempu Road","Srirammpura","Mantri Square Road",
        "Nadaprabhu Kempegowda Station, Majestic","Chickpete","Krishna Rajendra Market","National College",
        "Lalbagh","South End Circle","Jayanagar","Rashtreeya Vidyalaya Road","Banashankari",
        "Jaya Prakash Nagar","Yelachenahalli","Konanakunte Cross","Doddakallasandra",
        "Vajarahalli","Thalaghattapura","Silk Institute"
    };

    purple_line_stations ={"Baiyyapanahalli","Swami Vivekananda Road","Indiranagar","Halasuru",
        "Trinity","Mahathma Gandhi Road","Cubbon Park","Dr.B.R. Ambedkar Station",
        "Sri M Visveswaraya Station, Central College","Nadaprabhu Kempegowda Station, Majestic",
        "Krantivira Sangolli Rayanna Railway Station","Magadi Road","Sri Balagangadharanatha Swaji Stn., Hosahalli",
        "Vijayanagar","Attiguppe","Deepanjali Nagar","Mysore Road","Nayandahalli","Rajarajeshwari Nagar",
        "Jnanabharathi","Pattanagere","Kengeri Bus Terminal","Kengeri"

    };

    green_line_stations = {"Nagasandra","Dasarahalli","Jalahalli","Peenya Industry","Peenya",
        "Goraguntepalya","Yeshwanthpur","Sandal Soap Factory","Mahalakshmi",
        "Rajajinagar","Mahakavi Kuvempu Road","Srirammpura","Mantri Square Road",
        "Nadaprabhu Kempegowda Station, Majestic","Chickpete","Krishna Rajendra Market","National College",
        "Lalbagh","South End Circle","Jayanagar","Rashtreeya Vidyalaya Road","Banashankari",
        "Jaya Prakash Nagar","Yelachenahalli","Konanakunte Cross","Doddakallasandra",
        "Vajarahalli","Thalaghattapura","Silk Institute"

    };

}

string Graph::getPurpleStationsString() {
    stringstream ss;
    for (size_t i = 0; i < purple_line.size(); ++i) {
        ss << purple_line[i];
        if (i != purple_line.size() - 1) {
            ss << "\n"; // Add newline character except for the last station
        }
    }
    return ss.str();
}

string Graph::getGreenStationsString() {
    stringstream ss;
    for (size_t i = 0; i < green_line.size(); ++i) {
        ss << green_line[i];
        if (i != green_line.size() - 1) {
            ss << "\n"; // Add newline character except for the last station
        }
    }
    return ss.str();
}

void Graph::addEdge(string node1, string node2) {
    adjList[node1].push_back(node2);
    adjList[node2].push_back(node1);
}

void Graph::addStation(string station) {
    stationIndices[station] = numVertices++;
    adjacencyList.resize(numVertices);
}

void Graph::addEdgelength(string source, string destination, float weight) {
    float sourceIndex = stationIndices[source];
    float destIndex = stationIndices[destination];
    adjacencyList[sourceIndex].push_back(make_pair(destIndex, weight));
}

string Graph::getStationName(int index) {
    for (const auto& entry : stationIndices) {
        if (entry.second == index) {
            return entry.first;
        }
    }
    return "";
}

string Graph::findPath(string source, string destination) {

    int n=purple_line.size();
    for(int i=0;i<n-1;i++)
    {
        addEdge(purple_line[i],purple_line[i+1]);
    }

    int m=green_line.size();
    for(int j=0; j < m-1; j++)
    {
        addEdge(green_line[j],green_line[j+1]);
    }
    for(int i=0;i<n;i++)
    {
        addStation(purple_line[i]);
    }
    for(int j=0; j < m; j++)
    {
        addStation(green_line[j]);
    }
    string res;
    if(purple_line_stations.find(source) != purple_line_stations.end() && green_line_stations.find(destination)!=green_line_stations.end())
    {
        res="Change to Green line at Majestic";
    }

    else if(purple_line_stations.find(destination) != purple_line_stations.end() && green_line_stations.find(source)!=green_line_stations.end())
    {
        res="Change to Purple line at Majestic";
    }

    else
    {
        res="Stay on the Same line";
    }

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
            // destination reached, construct the path
            vector<string> path;

            while (node != "-1") {
                path.push_back(node);
                node = parent[node];
            }
            string pathString;
            for (int i = path.size() - 1; i >= 0; i--) {
                pathString += path[i] + "\n";
            }
            return res+"\n"+pathString;
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
    return "Path not found.";
}

//string Graph::djikstra(string source, string destination) {
pair<string, string> Graph::djikstra(string source, string destination) {
    int n=purple_line.size();
    for(int i=0;i<n-1;i++)
    {
        addEdge(purple_line[i],purple_line[i+1]);
    }

    int m=green_line.size();
    for(int j=0; j < m-1; j++)
    {
        addEdge(green_line[j],green_line[j+1]);
    }
    for(int i=0;i<n;i++)
    {
        addStation(purple_line[i]);
    }
    for(int j=0; j < m; j++)
    {
        addStation(green_line[j]);
    }
    string res;
    if(purple_line_stations.find(source) != purple_line_stations.end() && green_line_stations.find(destination)!=green_line_stations.end())
    {
        res="Change to Green line at Majestic";
    }

    else if(purple_line_stations.find(destination) != purple_line_stations.end() && green_line_stations.find(source)!=green_line_stations.end())
    {
        res="Change to Purple line at Majestic";
    }

    else
    {
        res="Stay on the Same line";
    }


    addEdgelength("Baiyyapanahall", "Swami Vivekananda Road", 1.9);
    addEdgelength("Swami Vivekananda Road", "Indiranagar", 1.4);
    addEdgelength("Indiranagar","Halasuru",1.4);
    addEdgelength("Halasuru","Trinity",1.1);
    addEdgelength("Trinity","Mahathma Gandhi Road",5);
    addEdgelength("Mahathma Gandhi Road","Cubbon Park",2.7);
    addEdgelength("Cubbon Park", "Dr.B.R. Ambedkar Station", 0.6);
    addEdgelength("Dr.B.R. Ambedkar Station", "Sri M Visveswaraya Station, Central College", 0.750);
    addEdgelength("Sri M Visveswaraya Station, Central College", "Nadaprabhu Kempegowda Station, Majestic", 1.4);
    addEdgelength("Nadaprabhu Kempegowda Station, Majestic", "Krantivira Sangolli Rayanna Railway Station", 2.3);
    addEdgelength("Krantivira Sangolli Rayanna Railway Station","Magadi Road",2.3);
    addEdgelength("Magadi Road","Sri Balagangadharanatha Swaji Stn., Hosahalli",1.3);
    addEdgelength("Sri Balagangadharanatha Swaji Stn., Hosahalli","Vijayanagar",1.5);
    addEdgelength("Vijayanagar","Attiguppe",1);
    addEdgelength("Attiguppe","Deepanjali Nagar",2.3);
    addEdgelength("Deepanjali Nagar","Mysore Road",4.5);
    addEdgelength("Mysore Road","Nayandahalli",1.1);
    addEdgelength("Nayandahalli","Rajarajeshwari Nagar",2.1);
    addEdgelength("Rajarajeshwari Nagar","Jnanabharathi",3.0);
    addEdgelength("Jnanabharathi","Pattanagere",2.8);
    addEdgelength("Pattanagere","Kengeri Bus Terminal",4);
    addEdgelength("Kengeri Bus Terminal","Kengeri",1.5);
    //Distance of Green Line
    addEdgelength("Nagasandra","Dasarahalli",1.4);
    addEdgelength("Dasarahalli","Jalahalli",0.9);
    addEdgelength("Jalahalli","Peenya Industry",0.8);
    addEdgelength("Peenya Industry","Goraguntepalya",1.9);
    addEdgelength("Goraguntepalya","Yeshwanthpur",1.1);
    addEdgelength("Yeshwanthpur","Sandal Soap Factory",2.5);
    addEdgelength("Sandal Soap Factory","Mahalakshmi",1.1);
    addEdgelength("Mahalakshmi","Rajajinagar",0.85);
    addEdgelength("Rajajinagar","Mahakavi Kuvempu Road",1.7);
    addEdgelength("Mahakavi Kuvempu Road","Srirammpura",0.4);
    addEdgelength("Srirammpura","Mantri Square Road",2.5);
    addEdgelength("Mantri Square Road","Nadaprabhu Kempegowda Station, Majestic",2.2);
    addEdgelength("Nadaprabhu Kempegowda Station, Majestic","Chickpete",1.5);
    addEdgelength("Chickpete","Krishna Rajendra Market",1.5);
    addEdgelength("Krishna Rajendra Market","National College",1.8);
    addEdgelength("National College","Lalbagh",2.1);
    addEdgelength("Lalbagh","South End Circle",1.3);
    addEdgelength("South End Circle","Jayanagar",1);
    addEdgelength("Jayanagar","Rashtreeya Vidyalaya Road",0.9);
    addEdgelength("Rashtreeya Vidyalaya Road","Banashankari",1.4);
    addEdgelength("Banashankari","Jaya Prakash Nagar",0.8);
    addEdgelength("Jaya Prakash Nagar","Yelachenahalli",1.4);
    addEdgelength("Yelachenahalli","Konanakunte Cross",1.1);
    addEdgelength("Konanakunte Cross","Doddakallasandra",1.6);
    addEdgelength("Doddakallasandra","Vajarahalli",1.9);
    addEdgelength("Vajarahalli","Thalaghattapura",1);
    addEdgelength("Thalaghattapura","Silk Institute",1.4);

    //Reverselist
    addEdgelength("Swami Vivekananda Road","Baiyyapanahall", 1.9);
    addEdgelength( "Indiranagar","Swami Vivekananda Road", 1.4);
    addEdgelength("Halasuru","Indiranagar",1.4);
    addEdgelength("Trinity","Halasuru",1.1);
    addEdgelength("Mahathma Gandhi Road","Trinity",5);
    addEdgelength("Cubbon Park","Mahathma Gandhi Road",2.7);
    addEdgelength( "Dr.B.R. Ambedkar Station","Cubbon Park", 0.6);
    addEdgelength( "Sri M Visveswaraya Station, Central College", "Dr.B.R. Ambedkar Station",0.750);
    addEdgelength( "Nadaprabhu Kempegowda Station, Majestic", "Sri M Visveswaraya Station, Central College",1.4);
    addEdgelength( "Krantivira Sangolli Rayanna Railway Station", "Nadaprabhu Kempegowda Station, Majestic",2.3);
    addEdgelength("Magadi Road","Krantivira Sangolli Rayanna Railway Station",2.3);
    addEdgelength("Sri Balagangadharanatha Swaji Stn., Hosahalli","Magadi Road",1.3);
    addEdgelength("Vijayanagar","Sri Balagangadharanatha Swaji Stn., Hosahalli",1.5);
    addEdgelength("Attiguppe","Vijayanagar",1);
    addEdgelength("Deepanjali Nagar","Attiguppe",2.3);
    addEdgelength("Mysore Road","Deepanjali Nagar",4.5);
    addEdgelength("Nayandahalli","Mysore Road",1.1);
    addEdgelength("Rajarajeshwari Nagar","Nayandahalli",2.1);
    addEdgelength("Jnanabharathi","Rajarajeshwari Nagar",3.0);
    addEdgelength("Pattanagere","Jnanabharathi",2.8);
    addEdgelength("Kengeri Bus Terminal","Pattanagere",4);
    addEdgelength("Kengeri","Kengeri Bus Terminal",1.5);
    addEdgelength("Dasarahalli","Nagasandra",1.4);
    addEdgelength("Jalahalli","Dasarahalli",0.9);
    addEdgelength("Peenya Industry","Jalahalli",0.8);
    addEdgelength("Goraguntepalya","Peenya Industry",1.9);
    addEdgelength("Yeshwanthpur","Goraguntepalya",1.1);
    addEdgelength("Sandal Soap Factory","Yeshwanthpur",2.5);
    addEdgelength("Mahalakshmi","Sandal Soap Factory",1.1);
    addEdgelength("Rajajinagar","Mahalakshmi",0.85);
    addEdgelength("Mahakavi Kuvempu Road","Rajajinagar",1.7);
    addEdgelength("Srirammpura","Mahakavi Kuvempu Road",0.4);
    addEdgelength("Mantri Square Road","Srirammpura",2.5);
    addEdgelength("Nadaprabhu Kempegowda Station, Majestic","Mantri Square Road",2.2);
    addEdgelength("Chickpete","Nadaprabhu Kempegowda Station, Majestic",1.5);
    addEdgelength("Chickpete","Krishna Rajendra Market",1.5);
    addEdgelength("National College","Krishna Rajendra Market",1.8);
    addEdgelength("Lalbagh","National College",2.1);
    addEdgelength("South End Circle","Lalbagh",1.3);
    addEdgelength("South End Circle","Jayanagar",1);
    addEdgelength("Rashtreeya Vidyalaya Road","Jayanagar",0.9);
    addEdgelength("Banashankari","Rashtreeya Vidyalaya Road",1.4);
    addEdgelength("Jaya Prakash Nagar","Banashankari",0.8);
    addEdgelength("Yelachenahalli","Jaya Prakash Nagar",1.4);
    addEdgelength("Konanakunte Cross","Yelachenahalli",1.1);
    addEdgelength("Doddakallasandra","Konanakunte Cross",1.6);
    addEdgelength("Vajarahalli","Doddakallasandra",1.9);
    addEdgelength("Thalaghattapura","Vajarahalli",1);
    addEdgelength("Silk Institute","Thalaghattapura",1.4);

    float sourceIndex = stationIndices[source];
    float destIndex = stationIndices[destination];

    priority_queue<pair<float, float>, vector<pair<float, float>>, greater<pair<float, float>>> pq;
    vector<float> distance(numVertices, numeric_limits<float>::max());
    vector<float> parent(numVertices, -1);
    vector<bool> visited(numVertices, false);

    pq.push(make_pair(0, sourceIndex));
    distance[sourceIndex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (const auto& neighbor : adjacencyList[u]) {
            float v = neighbor.first;
            float weight = neighbor.second;

            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    vector<string> shortestPath;
    float current = destIndex;
    while (current != -1) {
        shortestPath.push_back(getStationName(current));
        current = parent[current];
    }

    reverse(shortestPath.begin(), shortestPath.end());

    // Construct the path string
    string path;
    for (const auto& station : shortestPath) {
        path += station + "\n";
    }
    float totalDistance = distance[destIndex];

    string distanceStr = "Total Distance: " + to_string(totalDistance) + " km";

    return make_pair(res + "\n" + path, distanceStr);

    //return res+"\n"+path;
}
