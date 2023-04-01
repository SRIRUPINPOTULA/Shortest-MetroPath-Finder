/* 1.Show the metro map 2.View the stations 3.Find the intermediate stations based on the source and 
departure station 4.*/


#include <iostream>
#include<vector>  
using namespace std;



   void print_stations()
   {
        vector<string>purple_line={"Baiyyapanahalli", "Swami Vivekananda Road", "Indiranagar","Halasuru","Trinity","Mahathma Gandhi Road","Cubbon Park",
        "Dr. B. R. Ambedkar Staation","Sri M Visveswaraya Station, Central College","Nadaprabhu Kempegowda Station, Majestic","Krantivira Sangolli Rayanna Railway Station", "Magadi Road","Sri Balagangadharanatha Swaji Stn., Hosahalli",
        "Vijayanagar","Attiguppe","Deepanjali Nagar","Mysore Road","Nayandahalli","Rajarajeshwari Nagar","Jnanabharathi","Pattanagere","Kengeri Bus Terminal","Kengeri"};
        vector<string>green_line={"Nagasandra","Dasarahalli","Jalahalli","Peenya Industry","Peenya","Goraguntepalya","Yeshwanthpur","Sandal Soap Factory","Mahalakshmi",
        "Rajajinagar","Mahakavi Kuvempu Road","Srirammpura","Mantri Square Road","Nadaprabhu Kempegowda Station, Majestic","Chickpete","Krishna Rajendra Market","National College"
        ,"Lalbagh","South End Circle","Jayanagar","Rashtreeya Vidyalaya Road","Banashankari","Jaya Prakash Nagar","Yelachenahalli","Konanakunte Cross","Doddakallasandra"
        ,"Vajarahalli","Thalaghattapura","Silk Institute"};
        cout<<"List of Stations on Purple Line"<<"\n";int a=0;
        for (auto i:purple_line)
        {
            cout<<a++<<". "<<i<<"\n";
        }
        a=0;
        cout<<"List of Stations on Green line\n";
        for (auto i:green_line)
        {
            cout<<a++<<". "<<i<<"\n";
        }
   }

   void graph_metro_map()
   {
        vector<vector<int>>adj;
        int nodes=58;
        for(int i=0;i<nodes;i++)
        {
            for(int j=0;j<nodes;j++)
            {
                adj[i][j]=0;
            }
        }
        
   }


int main()
{
    
    cout<<"Saibaba Sri Amma Bhagavan"<<"\n";
    cout<<"===============================================================";
    cout<<"\tWelcome to the Bangalore Metro App!!!!!";
    cout<<"===============================================================";
    cout<<"Show the Options: \n";
    cout<<"\n"<<"Pick a Choice from below:";
    cout<<"\n 1. List all the Stations in the Map";
    cout<<"\n 2. The Bengaluru Metro Map";
    cout<<"\n 3. Know the shortest path between two stations";
    cout<<"\n 4. Find the time between two Stations.";
    cout<<"\n 5. Exit the Menu";
    cout<<"Choose an Option: "<<"\n";
    int choice=0;
    cin>>choice;
    switch(choice)
    {
        case 1:
            print_stations();
            break;
        /*case 2: 
            g.graph_metro_map();
            break;
        case 3:
            g.shortest_distance();
            break;*/
        case 5: 
            exit(0);
        default: 
            cout<<"Please Enter a Valid Option"<<"\n";
            cout<<"Choose the Option fromt eh above List"<<"\n";
    }
    return 0; 
}