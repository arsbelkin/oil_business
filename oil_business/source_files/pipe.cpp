#include <iostream>
#include "../header_files/pipe.h"
#include <fstream>

using namespace std;


bool is_created(const Pipe &pipe){
    return !(pipe.diameter == -1);
}


string work_to_string(const Pipe &pipe){
    return pipe.is_working ? "yes" : "no";
}


void edit_work_status(Pipe &pipe){
    if (is_created(pipe)) {
        cout << "New working status(0 - no / 1 - yes): ";
        cin >> pipe.is_working;
        cout << "New working status is set!" << endl;
    } else {
        cout << "The pipe has not been created yet!" << endl;
    }
}


ostream& operator << (ostream &os, const Pipe &pipe){
    if (is_created(pipe)){
        os << "-----Pipe-----" << endl
            << "name: " << pipe.name << endl
            << "lenght: " << pipe.length << endl
            << "diameter: " << pipe.diameter << endl
            << "is working: " << work_to_string(pipe) << endl
            << "--------------" << endl;
    } else {
        os << "The pipe has not been created yet!" << endl;
    }

    return os;
}


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


void save(const Pipe &pipe){
    if (is_created(pipe)) {
        ofstream file("static/pipe.txt");
        if (file.is_open()){
            file << pipe.name << endl;
            file << pipe.length << endl;
            file << pipe.diameter << endl;
            file << pipe.is_working << endl;
        }
        file.close();
        cout << "Pipe save in file!\n";
    } else {
        cout << "The pipe has not been created yet!" << endl;
    }
}
