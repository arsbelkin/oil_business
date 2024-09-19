#include <iostream>
#include <string>

using namespace std;


struct Pipe{
    // труба
    string name;
    int length;
    int diameter;
    bool is_working;

    // friend ostream& operator << (ostream &os, const Pipe &pipe){
    //     if (is_created(pipe)){
    //         os << "Pipe:" << endl
    //             << "name: " << pipe.name << endl
    //             << "lenght: " << pipe.length << endl
    //             << "diameter: " << pipe.diameter << endl
    //             << "is working" << is_work(pipe) << endl;
    //     } else {
    //         os << "The pipe has not been created yet" << endl;
    //     }

    //     return os;
    // }
};


struct CompressorStation{
    // компрессорная станция
    string name;
    int number_of_workshops;
    int workshops_in_work;
    float efficiency;

    // friend ostream& operator << (ostream& os, const CompressorStation &compressor_station){
    //     os <<  << endl;
    //     return os;
    // }
};


bool is_created(const Pipe &pipe){
    return !(pipe.diameter == -1);
}


bool is_created(const CompressorStation &compressor_station){
    return !(compressor_station.efficiency == -1);
}


string is_work(const Pipe &pipe){
    return pipe.is_working ? "yes" : "no";
}


ostream& operator << (ostream &os, const Pipe &pipe){
    if (is_created(pipe)){
        os << "-----Pipe-----" << endl
            << "name: " << pipe.name << endl
            << "lenght: " << pipe.length << endl
            << "diameter: " << pipe.diameter << endl
            << "is working: " << is_work(pipe) << endl
            << "--------------" << endl;
    } else {
        os << "The pipe has not been created yet" << endl;
    }

    return os;
}


// void Create(Pipe &pipe, int name, int lenght, int diameter, bool is_working){
//     // создать(переопределить свойства) трубу
//     pipe.name = name;
//     pipe.length = lenght;
//     pipe.diameter = diameter;
//     pipe.is_working = is_working;
// };


// void Create(CompressorStation &compressor_station, string name, int number_of_workshops, int workshops_in_work, float efficiency){
//     // создать(переопределить свойства) компрессорной станции
//     compressor_station.name = name;
//     compressor_station.number_of_workshops = number_of_workshops;
//     compressor_station.workshops_in_work = workshops_in_work;
//     compressor_station.efficiency = efficiency;
// };


void print_main_menu(){
    cout << "-----Menu-----\n";
    cout << "0 - exit\n";
    cout << "1 - add pipe\n";
    cout << "2 - add compressor station\n";
    cout << "3 - see all objects\n";
    cout << "4 - edit pipe\n";
    cout << "5 - edit compressor stationn\n";
    cout << "6 - save in file\n";
    cout << "7 - upload from file\n";
    cout << "--------------\n";
};


void add_pipe(Pipe &pipe){
    if (is_created(pipe)){
        cout << "Pipe is created already!\n";
    } else {
        cout << "-----add pipe-----\n";

        cout << "name: ";
        cin >> pipe.name;

        cout << "lenght: ";
        cin >> pipe.length;

        cout << "diameter: ";
        cin >> pipe.diameter;

        cout << "is_working(0 - no / 1 - yes): ";
        cin >> pipe.is_working;

        cout << "Pipe is created!\n";

        cout << "------------------\n";
    };
}


void add_compressorStation(CompressorStation &compressor_station){
    if (is_created(compressor_station)){
        cout << "compressor station is created already\n";
    } else {
        cout << "---add compressor station---\n";

        cout << "name: ";
        cin >> compressor_station.name;

        cout << "number of workshops: ";
        cin >> compressor_station.number_of_workshops;

        cout << "workshops in work: ";
        cin >> compressor_station.workshops_in_work;

        cout << "efficiency: ";
        compressor_station.efficiency = (float)compressor_station.workshops_in_work / compressor_station.number_of_workshops;
        cout << compressor_station.efficiency * 100 << "%" << endl;

        cout << "Comperssor Station is created!\n";

        cout << "----------------------------\n";
    };
}


void see_all_objects(Pipe &pipe, CompressorStation &compressor_station){
    cout << pipe;
    // cout << compressor_station;
}



void main_menu(){
    Pipe pipe = {"", -1, -1, 0};
    CompressorStation compressor_station = {"", -1, -1, -1};

    while (true){
        print_main_menu();


        int choice;
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Goodbye!\n";
            return;
        case 1:
            add_pipe(pipe);
            break;
        case 2:
            add_compressorStation(compressor_station);
            break;
        case 3:
            see_all_objects(pipe, compressor_station);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
};


int main(){
    main_menu();

    return 0;
}
