#include <iostream>
#include "../header_files/compressor_station.h"
#include "../header_files/pipe.h"
#include <math.h>
#include <fstream>
#include "../header_files/utils.h"

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


void calc_eff(CompressorStation &compressor_station){
    compressor_station.efficiency = (float)compressor_station.workshops_in_work / compressor_station.number_of_workshops;
}


void add_compressorStation(CompressorStation &compressor_station){
    if (is_created(compressor_station)){
        cout << "Compressor station is created already\n";
    } else {
        cout << "---add compressor station---\n";

        cout << "name: ";
        cin.ignore(1000, '\n');
        getline(cin, compressor_station.name);

        cout << "number of workshops: ";
        compressor_station.number_of_workshops = valid_int("number of workshops: ", 0, 10000);

        cout << "workshops in work: ";
        compressor_station.workshops_in_work = valid_int("workshops in work: ", 0, compressor_station.number_of_workshops);

        cout << "efficiency: ";
        calc_eff(compressor_station);
        cout << compressor_station.efficiency * 100 << "%" << endl;

        cout << "Comperssor Station is created!\n";

        cout << "----------------------------\n";
    };
}


void edit_workshop_status(CompressorStation &compressor_station){
    if (is_created(compressor_station)){
        int choice;
        cout << "Stop(1) or Start(2) the workshop: ";
        choice = valid_int("Stop(1) or Start(2) the workshop: ", 1, 2);
        if (choice == 1){
            if (compressor_station.workshops_in_work > 0){
                --compressor_station.workshops_in_work;
            };
        } else {
            if (compressor_station.workshops_in_work < compressor_station.number_of_workshops) {
                ++compressor_station.workshops_in_work;
            };
        };
        calc_eff(compressor_station);
        cout << "New worksop status is set\n";
        cout << "Now eff = " << compressor_station.efficiency * 100 << '%' << endl;
    } else {
        cout << "The CS has not been created yet!" << endl;
    }
}


void save(ofstream &file, const CompressorStation &compressor_station){
    if (is_created(compressor_station)){
        file << "CS" << endl;
        file << compressor_station.name << endl;
        file << compressor_station.number_of_workshops << endl;
        file << compressor_station.workshops_in_work << endl;
        file << compressor_station.efficiency * 100 << '%' << endl;
        cout << "CS save in file!\n";
    } else {
        file << "None" << endl;
        cout << "The CS has not been created yet!" << endl;
    }
}


void load(std::ifstream &file, CompressorStation &compressor_station){
    if (is_created(compressor_station)){
        cout << "CS is created already!\n";
    } else {
        file.ignore(10000, '\n');
        getline(file, compressor_station.name);
        file >> compressor_station.number_of_workshops;
        file >> compressor_station.workshops_in_work;
        calc_eff(compressor_station);
        cout << "CS is created from file!" << endl;
    }
}
