#include <iostream>
#include "../header_files/pipe.h"
#include <fstream>
#include "../header_files/compressor_station.h"
#include "../header_files/utils.h"

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
        pipe.is_working = valid_int("New working status(0 - no / 1 - yes): ", 0, 1);
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

        cout << "name:";
        cin.ignore(1000, '\n');
        getline(cin, pipe.name);

        cout << "lenght: ";
        pipe.length = valid_int("lenght: ", 1, 10000);

        cout << "diameter: ";
        pipe.diameter = valid_int("diameter: ", 1, 1000);

        cout << "is_working(0 - no / 1 - yes): ";
        pipe.is_working = valid_int("is_working(0 - no / 1 - yes): ", 0, 1);;

        cout << "Pipe is created!\n";

        cout << "------------------\n";
    };
}


void save(ofstream &file, const Pipe &pipe){
    if (is_created(pipe)) {
        file << "Pipe" << endl;
        file << pipe.name << endl;
        file << pipe.length << endl;
        file << pipe.diameter << endl;
        file << pipe.is_working << endl;
        cout << "Pipe save in file!\n";
    } else {
        file << "None" << endl;
        cout << "The pipe has not been created yet!" << endl;
    }
}

void load(ifstream &file, Pipe &pipe){
    if (is_created(pipe)) {
        cout << "Pipe is created already!\n";
    } else {
        file.ignore(1000, '\n');
        getline(file, pipe.name);
        file >> pipe.length;
        file >> pipe.diameter;
        file >> pipe.is_working;
        cout << "Pipe is created from file!" << endl;
    }
}
