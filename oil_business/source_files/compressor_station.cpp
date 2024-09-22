#include <iostream>
#include "../header_files/compressor_station.h"

using namespace std;


bool is_created(const CompressorStation &compressor_station){
    return !(compressor_station.efficiency == -1);
}


ostream& operator << (ostream &os, const CompressorStation &compressor_station){
    if (is_created(compressor_station)){
        os << "-----Compressor Station-----" << endl
            << "name: " << compressor_station.name << endl
            << "number of workshops: " << compressor_station.number_of_workshops << endl
            << "workshops in work: " << compressor_station.workshops_in_work << endl
            << "efficiency: " << compressor_station.efficiency * 100 << "%" << endl
            << "--------------" << endl;
    } else {
        os << "The compressor station has not been created yet!" << endl;
    }

    return os;
}


void add_compressorStation(CompressorStation &compressor_station){
    if (is_created(compressor_station)){
        cout << "Compressor station is created already\n";
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
