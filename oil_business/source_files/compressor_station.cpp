#include <iostream>
#include "../header_files/compressor_station.h"
#include "../header_files/pipe.h"
#include <math.h>
#include <fstream>
#include "../header_files/utils.h"

using namespace std;


int CompressorStation::current_csID = 0;


CompressorStation::CompressorStation(){
    cout << "---add compressor station---\n";

    this->id = CompressorStation::current_csID++;
    cout << "id: " << this->id << endl;

    cout << "name: ";
    cin.ignore(1000, '\n');
    getline(cin, this->name);

    cout << "number of workshops: ";
    this->number_of_workshops = valid_int("number of workshops: ", 1, 10000);

    cout << "workshops in work: ";
    this->workshops_in_work = valid_int("workshops in work: ", 0, this->number_of_workshops);

    cout << "efficiency: ";
    calc_workload();
    cout << this->workload * 100 << "%" << endl;

    cout << "Comperssor Station is created!\n";

    cout << "----------------------------\n";
}


int CompressorStation::get_id() const{
    return this->id;
}


bool CompressorStation::is_created() const{
    return !(this->workload == -1);
}


ostream& operator << (ostream &os, const CompressorStation &compressor_station){
    if (compressor_station.is_created()){
        os << "-----Compressor Station " << compressor_station.get_id() << "-----" << endl
            << "id: " << compressor_station.get_id() << endl
            << "name: " << compressor_station.name << endl
            << "number of workshops: " << compressor_station.number_of_workshops << endl
            << "workshops in work: " << compressor_station.workshops_in_work << endl
            << "efficiency: " << compressor_station.workload * 100 << "%" << endl
            << "--------------" << endl;
    } else {
        os << "The compressor station has not been created yet!" << endl;
    }

    return os;
}


void CompressorStation::calc_workload(){
    this->workload = (float)this->workshops_in_work / this->number_of_workshops;
}


void CompressorStation::edit_workshop_status(){
    if (this->is_created()){
        int choice;
        cout << "Stop(1) or Start(2) the workshop: ";
        choice = valid_int("Stop(1) or Start(2) the workshop: ", 1, 2);
        if (choice == 1){
            if (this->workshops_in_work > 0){
                --this->workshops_in_work;
            };
        } else {
            if (this->workshops_in_work < this->number_of_workshops) {
                ++this->workshops_in_work;
            };
        };
        this->calc_workload();
        cout << "New worksop status is set\n";
        cout << "Now eff = " << this->workload * 100 << '%' << endl;
    } else {
        cout << "The CS has not been created yet!" << endl;
    }
}


void CompressorStation::save(ofstream &file) const{
    if (this->is_created()){
        file << "CS" << endl;
        file << this->name << endl;
        file << this->number_of_workshops << endl;
        file << this->workshops_in_work << endl;
        file << this->workload * 100 << '%' << endl;
        cout << "CS save in file!\n";
    } else {
        file << "None" << endl;
        cout << "The CS has not been created yet!" << endl;
    }
}


void add_compressorStation(unordered_map<int, CompressorStation> &c_ss){
    CompressorStation compressor_station;
    c_ss.emplace(compressor_station.get_id(), compressor_station);
}


// bool is_created(const CompressorStation &compressor_station){
//     return !(compressor_station.workload == -1);
// }


// ostream& operator << (ostream &os, const CompressorStation &compressor_station){
//     if (is_created(compressor_station)){
//         os << "-----Compressor Station-----" << endl
//             << "name: " << compressor_station.name << endl
//             << "number of workshops: " << compressor_station.number_of_workshops << endl
//             << "workshops in work: " << compressor_station.workshops_in_work << endl
//             << "efficiency: " << compressor_station.workload * 100 << "%" << endl
//             << "--------------" << endl;
//     } else {
//         os << "The compressor station has not been created yet!" << endl;
//     }

//     return os;
// }


// void calc_workload(CompressorStation &compressor_station){
//     compressor_station.workload = (float)compressor_station.workshops_in_work / compressor_station.number_of_workshops;
// }


// void add_compressorStation(CompressorStation &compressor_station){
    // if (is_created(compressor_station)){
    //     cout << "Compressor station is created already\n";
    // } else {
    //     cout << "---add compressor station---\n";

    //     cout << "name: ";
    //     cin.ignore(1000, '\n');
    //     getline(cin, compressor_station.name);

    //     cout << "number of workshops: ";
    //     compressor_station.number_of_workshops = valid_int("number of workshops: ", 1, 10000);

    //     cout << "workshops in work: ";
    //     compressor_station.workshops_in_work = valid_int("workshops in work: ", 0, compressor_station.number_of_workshops);

    //     cout << "efficiency: ";
    //     calc_workload(compressor_station);
    //     cout << compressor_station.workload * 100 << "%" << endl;

    //     cout << "Comperssor Station is created!\n";

    //     cout << "----------------------------\n";
    // };
// }


// void edit_workshop_status(CompressorStation &compressor_station){
//     if (is_created(compressor_station)){
//         int choice;
//         cout << "Stop(1) or Start(2) the workshop: ";
//         choice = valid_int("Stop(1) or Start(2) the workshop: ", 1, 2);
//         if (choice == 1){
//             if (compressor_station.workshops_in_work > 0){
//                 --compressor_station.workshops_in_work;
//             };
//         } else {
//             if (compressor_station.workshops_in_work < compressor_station.number_of_workshops) {
//                 ++compressor_station.workshops_in_work;
//             };
//         };
//         calc_workload(compressor_station);
//         cout << "New worksop status is set\n";
//         cout << "Now eff = " << compressor_station.workload * 100 << '%' << endl;
//     } else {
//         cout << "The CS has not been created yet!" << endl;
//     }
// }


// void save(ofstream &file, const CompressorStation &compressor_station){
//     if (is_created(compressor_station)){
//         file << "CS" << endl;
//         file << compressor_station.name << endl;
//         file << compressor_station.number_of_workshops << endl;
//         file << compressor_station.workshops_in_work << endl;
//         file << compressor_station.workload * 100 << '%' << endl;
//         cout << "CS save in file!\n";
//     } else {
//         file << "None" << endl;
//         cout << "The CS has not been created yet!" << endl;
//     }
// }


// void load(std::ifstream &file, CompressorStation &compressor_station){
//     if (is_created(compressor_station)){
//         cout << "CS is created already!\n";
//     } else {
//         file.ignore(10000, '\n');
//         getline(file, compressor_station.name);
//         file >> compressor_station.number_of_workshops;
//         file >> compressor_station.workshops_in_work;
//         calc_workload(compressor_station);
//         cout << "CS is created from file!" << endl;
//     }
// }
