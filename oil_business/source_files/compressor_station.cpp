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

    this->id = ++CompressorStation::current_csID;
    cout << "id: " << this->id << endl;

    cout << "name: ";
    INPUT_LINE(cin, this->name);

    cout << "number of workshops: ";
    this->number_of_workshops = GetCorrectNumber<int>("number of workshops: ", {1, 10000}, IsInRange);

    cout << "workshops in work: ";
    this->workshops_in_work = GetCorrectNumber<int>("workshops in work: ", {0, this->number_of_workshops}, IsInRange);

    cout << "workload: ";
    calc_workload();
    cout << PRINT_WORKLOAD(this->) << endl;

    cout << "Comperssor Station is created!\n";

    cout << "----------------------------\n";
}


CompressorStation::CompressorStation(std::ifstream &file){
    file >> this->id;
    file.ignore(10000, '\n');
    getline(file>>std::ws, this->name);
    file >> this->number_of_workshops;
    file >> this->workshops_in_work;
    this->calc_workload();
}


int CompressorStation::get_currentId(){
    return CompressorStation::current_csID;
}


void CompressorStation::set_currentID(const std::unordered_map<int, CompressorStation>& data){
    CompressorStation::current_csID = get_maxKey(data);
}


int CompressorStation::get_id() const{
    return this->id;
}


std::string CompressorStation::get_name() const{
    return this->name;
}


void CompressorStation::clear_currentID(){
    CompressorStation::current_csID = 1;
}


float CompressorStation::get_workload() const{
    return this->workload;
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


void CompressorStation::edit_workshop_status(int choice){
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
}


void CompressorStation::save(ofstream &file) const{
    file << "CS" << endl;
    file << this->id << endl;
    file << this->name << endl;
    file << this->number_of_workshops << endl;
    file << this->workshops_in_work << endl;
    file << PRINT_WORKLOAD(this->) << endl;
}
