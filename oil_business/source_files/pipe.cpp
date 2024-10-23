#include <iostream>
#include "../header_files/pipe.h"
#include <fstream>
#include "../header_files/compressor_station.h"
#include "../header_files/utils.h"
#include <string>

using namespace std;


int Pipe::current_pipeID = 0;


Pipe::Pipe(){
    cout << "-----add pipe-----\n";

    this->id = Pipe::current_pipeID++;
    cout << "id: " << this->id << endl;;

    cout << "name:";
    cin.ignore(1000, '\n');
    getline(cin, this->name);

    cout << "lenght: ";
    this->length = valid_int("lenght: ", 1, 10000);

    cout << "diameter: ";
    this->diameter = valid_int("diameter: ", 1, 1000);

    cout << "is_working(0 - no / 1 - yes): ";
    this->is_working = valid_int("is_working(0 - no / 1 - yes): ", 0, 1);;

    cout << "Pipe is created!\n";

    cout << "------------------\n";
}


int Pipe::get_id() const{
    return this->id;
}


//TODO: change
bool Pipe::is_created() const {
    return !(this->diameter == -1);
}


string Pipe::work_to_string() const{
    return this->is_working ? "yes" : "no";
}


//TODO: change
void Pipe::edit_work_status(){
    if (this->is_created()) {
        cout << "New working status(0 - no / 1 - yes): ";
        this->is_working = valid_int("New working status(0 - no / 1 - yes): ", 0, 1);
        cout << "New working status is set!" << endl;
    } else {
        cout << "The pipe has not been created yet!" << endl;
    }
}

//TODO: change
ostream& operator << (ostream &os, const Pipe &pipe){
    if (pipe.is_created()){
        os << "-----Pipe " << pipe.get_id() << "-----" << endl
            << "id: " << pipe.get_id() << endl
            << "name: " << pipe.name << endl
            << "lenght: " << pipe.length << endl
            << "diameter: " << pipe.diameter << endl
            << "is working: " << pipe.work_to_string() << endl
            << "--------------" << endl;
    } else {
        os << "The pipe has not been created yet!" << endl;
    }

    return os;
}


// TODO: change
void Pipe::save(ofstream &file) const{
    if (this->is_created()) {
        file << "Pipe" << endl;
        file << this->name << endl;
        file << this->length << endl;
        file << this->diameter << endl;
        file << this->is_working << endl;
        cout << "Pipe save in file!\n";
    } else {
        file << "None" << endl;
        cout << "The pipe has not been created yet!" << endl;
    }
}


void add_pipe(unordered_map<int, Pipe> &pipes){
    Pipe pipe;
    pipes.emplace(pipe.get_id(), pipe);
}


// bool is_created(const Pipe &pipe){
//     return !(pipe.diameter == -1);
// }


// string work_to_string(const Pipe &pipe){
//     return pipe.is_working ? "yes" : "no";
// }


// void edit_work_status(Pipe &pipe){
//     if (is_created(pipe)) {
//         cout << "New working status(0 - no / 1 - yes): ";
//         pipe.is_working = valid_int("New working status(0 - no / 1 - yes): ", 0, 1);
//         cout << "New working status is set!" << endl;
//     } else {
//         cout << "The pipe has not been created yet!" << endl;
//     }
// }


// ostream& operator << (ostream &os, const Pipe &pipe){
//     if (is_created(pipe)){
//         os << "-----Pipe-----" << endl
//             << "name: " << pipe.name << endl
//             << "lenght: " << pipe.length << endl
//             << "diameter: " << pipe.diameter << endl
//             << "is working: " << work_to_string(pipe) << endl
//             << "--------------" << endl;
//     } else {
//         os << "The pipe has not been created yet!" << endl;
//     }

//     return os;
// }


// void add_pipe(Pipe &pipe){
//     if (is_created(pipe)){
//         cout << "Pipe is created already!\n";
//     } else {
        // cout << "-----add pipe-----\n";

        // cout << "name:";
        // cin.ignore(1000, '\n');
        // getline(cin, pipe.name);

        // cout << "lenght: ";
        // pipe.length = valid_int("lenght: ", 1, 10000);

        // cout << "diameter: ";
        // pipe.diameter = valid_int("diameter: ", 1, 1000);

        // cout << "is_working(0 - no / 1 - yes): ";
        // pipe.is_working = valid_int("is_working(0 - no / 1 - yes): ", 0, 1);;

        // cout << "Pipe is created!\n";

        // cout << "------------------\n";
//     };
// }


// void save(ofstream &file, const Pipe &pipe){
//     if (is_created(pipe)) {
//         file << "Pipe" << endl;
//         file << pipe.name << endl;
//         file << pipe.length << endl;
//         file << pipe.diameter << endl;
//         file << pipe.is_working << endl;
//         cout << "Pipe save in file!\n";
//     } else {
//         file << "None" << endl;
//         cout << "The pipe has not been created yet!" << endl;
//     }
// }

// void load(ifstream &file, Pipe &pipe){
//     if (is_created(pipe)) {
//         cout << "Pipe is created already!\n";
//     } else {
//         file.ignore(1000, '\n');
//         getline(file, pipe.name);
//         file >> pipe.length;
//         file >> pipe.diameter;
//         file >> pipe.is_working;
//         cout << "Pipe is created from file!" << endl;
//     }
// }
