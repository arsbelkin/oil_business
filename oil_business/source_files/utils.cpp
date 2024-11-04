#include <iostream>
#include "../header_files/pipe.h"
#include "../header_files/pipes_func.h"
#include "../header_files/compressor_station.h"
#include "../header_files/utils.h"
#include <fstream>
#include <sstream>

using namespace std;


int valid_int(const std::string message, const int min_value, const int max_value){
    int value;

    while ((cin >> value).fail() 
            || cin.peek() != '\n'
            || value < min_value || value > max_value)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << message;
    }
    return value;
}


void save_obj(const unordered_map<int, Pipe> &pipes, const unordered_map<int, CompressorStation> &c_ss){
    string path_to_file;

    cout << "file name: ";
    INPUT_LINE(cin, path_to_file);

    ofstream file("static/" + path_to_file);

    if (file.is_open()){
        if (pipes.empty()) {
            cout << "No pipes" << endl;
        } else {
            for (auto& [_, pipe]: pipes){
                pipe.save(file);
            }
        }

        if (c_ss.empty()) {
            cout << "No compressor stations" << endl;
        } else {
            for (auto& cs: c_ss){
                cs.second.save(file);
            }
        }

        file.close();

    } else {
        cout << "Error opening file!" << endl;
    }
    
}


void load_obj(std::unordered_map<int, Pipe> &pipes, std::unordered_map<int, CompressorStation> &c_ss){
    string path_to_file;
    string line;
    
    cout << "files name: ";
    INPUT_LINE(cin, line);

    istringstream iss(line);
    ifstream file;

    while (iss >> path_to_file){
        file.open("static/" + path_to_file);

        if (file.is_open()){
            string line;

            while (file >> line){
                if (line=="Pipe"){
                    load(file, pipes);
                }

                if (line=="CS"){
                    load(file, c_ss);
                }
            }
        
            file.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
}


void see_all_objects(const unordered_map<int, Pipe> &pipes, const unordered_map<int, CompressorStation> &c_ss){
    if (pipes.empty()) {
        cout << "No pipes" << endl;
    } else {
        for (auto& pipe: pipes){
            cout << pipe.second << endl;
        }
    }

    if (c_ss.empty()) {
        cout << "No compressor stations" << endl;
    } else {
        for (auto& cs: c_ss){
            cout << cs.second << endl;
        }
    }
}
