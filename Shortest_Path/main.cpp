/* 1.Show the metro map 2.View the stations 3.Find the intermediate stations based on the source and 
departure station 4.*/

#include <iostream>
#include<vector> 
using namespace std;
vector<string>purple_line={"Baiyyapanahalli", "Swami Vivekananda Road", "Indiranagar","Halasuru","Trinity","Mahathma Gandhi Road","Cubbon Park","Dr.B.R. Ambedkar Staation","Sri M Visveswaraya Station, Central College","Nadaprabhu Kempegowda Station, Majestic","Krantivira Sangolli Rayanna Railway Station", "Magadi Road","Sri Balagangadharanatha Swaji Stn., Hosahalli", "Vijayanagar","Attiguppe","Deepanjali Nagar","Mysore Road","Nayandahalli","Rajarajeshwari Nagar","Jnanabharathi","Pattanagere","Kengeri Bus Terminal","Kengeri"};
vector<string>green_line={"Nagasandra","Dasarahalli","Jalahalli","Peenya Industry","Peenya","Goraguntepalya","Yeshwanthpur","Sandal Soap Factory","Mahalakshmi",
        "Rajajinagar","Mahakavi Kuvempu Road","Srirammpura","Mantri Square Road","Nadaprabhu Kempegowda Station, Majestic","Chickpete","Krishna Rajendra Market","National College"
        ,"Lalbagh","South End Circle","Jayanagar","Rashtreeya Vidyalaya Road","Banashankari","Jaya Prakash Nagar","Yelachenahalli","Konanakunte Cross","Doddakallasandra"
        ,"Vajarahalli","Thalaghattapura","Silk Institute"};
void print_purple_stations(){
    int a=0;
    for (auto i:purple_line){
            cout<<a++<<". "<<i<<"\n";
    }
}
void print_green_stations(){
    int a=0;
    for (auto i:green_line){
            cout<<a++<<". "<<i<<"\n";
    }
}


void print_complete_map(){
    for (auto i:purple_line)
    {
        cout<<i<<"\t";
    }
    for (auto i:green_line)
    {
        cout<<i<<"\t";
    }
    cout<<"\n";
}


int main() {
    cout<< "Select an Item from the below Menu\n";
    
    int choice=0;
    cin>>choice;
    
    switch(choice)
    {
        case 1:
            print_purple_stations();
            break;
        case 2: 
            print_green_stations();
            break;
        case 3:
            cout<<"Available Stations are: "<<"\n";
            print_complete_map();
            break;
        case 4:
            cout<<"Thank you!!!";
            exit(0);
            break;
        default:
            cout<<"Please Enter a Correct Choice";
        
    }
    }while(choice);
    

    return 0;
}
