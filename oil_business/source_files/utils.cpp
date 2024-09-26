#include <iostream>
#include "../header_files/pipe.h"
#include "../header_files/compressor_station.h"
#include "../header_files/utils.h"
#include "fstream"

using namespace std;


int valid_int(std::string message, int min_value, int max_value){
    int x;

    while ((cin >> x).fail() 
            || cin.peek() != '\n'
            || x < min_value || x > max_value)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << message;
    }
    return x;
}


void save_obj(const Pipe &pipe, const CompressorStation &compressor_station){
    ofstream file("static/output.txt");
    if (file.is_open()){
        save(file, pipe);
        save(file, compressor_station);
    }
    file.close();
}


void load_obj(Pipe &pipe, CompressorStation &compressor_station){
    ifstream file("static/output.txt");

    if (file.is_open()){
        string line;
        file >> line;

        if (line=="Pipe"){
            load(file, pipe);
        } else cout << "Pipe cant created from file" << endl;

        file >> line;
        if (line == "CS"){
            load(file, compressor_station);
        } else cout << "CS cant created from file" << endl;

    } else cout << "file not created!" << endl;
    
    file.close();
}
