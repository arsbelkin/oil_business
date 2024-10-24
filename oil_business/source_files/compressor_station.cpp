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
    INPUT_LINE(cin, this->name);

    cout << "number of workshops: ";
    this->number_of_workshops = valid_int("number of workshops: ", 1, 10000);

    cout << "workshops in work: ";
    this->workshops_in_work = valid_int("workshops in work: ", 0, this->number_of_workshops);

    cout << "efficiency: ";
    calc_workload();
    cout << PRINT_WORKLOAD(this->) << endl;

    cout << "Comperssor Station is created!\n";

    cout << "----------------------------\n";
}


CompressorStation::CompressorStation(std::ifstream &file){
    this->id = CompressorStation::current_csID++;
    INPUT_LINE(file, this->name);
    file >> this->number_of_workshops;
    file >> this->workshops_in_work;
    this->calc_workload();
}


int CompressorStation::get_id() const{
    return this->id;
}


ostream& operator << (ostream &os, const CompressorStation &compressor_station){
    os << "-----Compressor Station " << compressor_station.get_id() << "-----" << endl
        << "id: " << compressor_station.get_id() << endl
        << "name: " << compressor_station.name << endl
        << "number of workshops: " << compressor_station.number_of_workshops << endl
        << "workshops in work: " << compressor_station.workshops_in_work << endl
        << "efficiency: " << PRINT_WORKLOAD(compressor_station.) << endl
        << "--------------" << endl;

    return os;
}


void CompressorStation::calc_workload(){
    this->workload = (float)this->workshops_in_work / this->number_of_workshops;
}


void CompressorStation::edit_workshop_status(){
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
    cout << "Now eff = " << PRINT_WORKLOAD(this->) << endl;
}


void CompressorStation::save(ofstream &file) const{
    file << "CS" << endl;
    file << this->name << endl;
    file << this->number_of_workshops << endl;
    file << this->workshops_in_work << endl;
    file << PRINT_WORKLOAD(this->) << endl;
    cout << "CS save in file!\n";
}


void load(std::ifstream &file, std::unordered_map<int, CompressorStation> &c_ss){
    CompressorStation compressor_station(file);
    c_ss.emplace(compressor_station.get_id(), compressor_station);
}


void add_compressorStation(unordered_map<int, CompressorStation> &c_ss){
    CompressorStation compressor_station;
    c_ss.emplace(compressor_station.get_id(), compressor_station);
}
