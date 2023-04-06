#include <iostream>
#include <vector>

#include <iterator>
using namespace std;

struct car {
    string name;
    int wheels;
    float speed;
};
void Show_Cars (  vector<car> Garage ){
    for (auto i = Garage.begin();i!=Garage.end();i++){
        cout << "\n Name of the machine\t" << i->name << "\t Wheels: \t" << i->wheels << "\t Speed: \t" << i->speed;
    }
}
vector<car> Add_Car_Last (vector<car> Garage){
    car Auto;
    cout << "\n Enter name of the car: \t";
    cin >> Auto.name;


    cout << "\n Enter the number of wheels of this machine: \t";
    cin >> Auto.wheels;


    cout << "\n Enter the speed indicator of this machine: \t";
    cin >> Auto.speed;
    Garage.push_back(Auto);
    return Garage;
}
vector<car> Add_Car_First (vector<car> Garage){
    car Auto;
    cout << "\n Enter name of the car: \t";
    cin >> Auto.name;


    cout << "\n Enter the number of wheels of this machine: \t";
    cin >> Auto.wheels;


    cout << "\n Enter the speed indicator of this machine: \t";
    cin >> Auto.speed;

    Garage.insert(Garage.begin(),Auto);
    return Garage;
}
vector<car> Add_Car_After_Given (vector<car> Garage, int place){
    car Auto;
    vector <car> :: iterator Iterator = Garage.begin();
    advance(Iterator,place);
    cout << "\n Enter name of the car: \t";
    cin >> Auto.name;


    cout << "\n Enter the number of wheels of this machine: \t";
    cin >> Auto.wheels;


    cout << "\n Enter the speed indicator of this machine: \t";
    cin >> Auto.speed;
    Garage.insert(Iterator,Auto);
    return Garage;
}
vector<car> Add_Car_Before_Given (vector<car> Garage, int place){
    car Auto;
    vector <car> :: iterator Iterator = Garage.begin();
    advance(Iterator,-1);
    advance(Iterator,place);
    cout << "\n Enter name of the car: \t";
    cin >> Auto.name;


    cout << "\n Enter the number of wheels of this machine: \t";
    cin >> Auto.wheels;


    cout << "\n Enter the speed indicator of this machine: \t";
    cin >> Auto.speed;
    Garage.insert(Iterator,Auto);
    return Garage;
}
vector<car> Delete_By_Name (vector<car> Garage, string Bad_Name){
    vector<car> New_Garage;
    for (auto i = Garage.begin();i!=Garage.end();i++){
        if (i->name == Bad_Name){
            continue;
        }
        else{
            New_Garage.push_back(*i);
        }
    }
    return New_Garage;
}




int main() {
    int n;
    vector<car> Garage;
    cout<<"Enter the size of the array of structures: ";
    cin>>n;
    while (n>0) {
        car Auto;
        cout << "\n Enter name of the car: \t";
        cin >> Auto.name;


        cout << "\n Enter the number of wheels of this machine: \t";
        cin >> Auto.wheels;


        cout << "\n Enter the speed indicator of this machine: \t";
        cin >> Auto.speed;
        Garage.push_back(Auto);
        n--;
    }

    int x = 99;
    cout<<'\n';
    cout << "NumGuide:" << '\n';
    cout << "press 1 to add pattern to start" << '\n';
    cout << "press 2 to add pattern to end" << '\n';
    cout << "press 3 to add pattern after given pattern" << '\n';
    cout << "press 4 to add pattern before given pattern" << '\n';
    cout << "press 5 to delete pattern with the specified name" << '\n';
    cout << "press 6 to see all patterms" << '\n';
    cout << "press 7 to kill program" << '\n';
    while (true) {

        cout<< '\n' << "What do you want to do with the array?"<<'\n';
        cin >> x;
        switch (x) {
            case 1: {
                Garage = Add_Car_First (Garage);
                break;
            }

            case 2: {
                Garage= Add_Car_Last(Garage);
                break;
            }

            case 3: {

                int place;
                cout << "After which car to put a new one? ";
                cin>>place;
                Garage = Add_Car_After_Given(Garage, place);
                break;

            }

            case 4: {
                int place;
                cout << "Before which car to put a new one? ";
                cin>>place;
                Garage = Add_Car_Before_Given(Garage, place);
                break;
            }

            case 5: {
                string Bad_Name;
                cout << "The machine with which name should be deleted? ";
                cin>>Bad_Name;
                Garage=Delete_By_Name(Garage,Bad_Name);
                break;
            }

            case 6: {
                Show_Cars (Garage);
                break;
            }

            case 7: {

                return 0;

            }
        }
    }



}

