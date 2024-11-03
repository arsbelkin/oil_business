#pragma once
#include <iostream>
#include <unordered_set>


#define INPUT_LINE(in, str) in.ignore(1000, '\n'); \
                            getline(in>>std::ws, str);


#define CLEAR_SELECTED(selected) selected.clear(); \
                                std::cout << "Selected cleared!" << std::endl;


void save_obj(const std::unordered_map<int, Pipe> &pipes, const std::unordered_map<int, CompressorStation> &c_ss);

void load_obj(std::unordered_map<int, Pipe> &pipes, std::unordered_map<int, CompressorStation> &c_ss);

int valid_int(const std::string message, const int min_value, const int max_value);

void see_all_objects(const std::unordered_map<int, Pipe> &pipes, const std::unordered_map<int, CompressorStation> &c_ss);


template<typename T>
void print_selected(const std::unordered_map<int, T> &obj, const std::unordered_set<int> &selected_obj){
    if (selected_obj.size() == 0) std::cout << "No selected!" << std::endl;
    
    for (const int &id: selected_obj){
        std::cout << obj.find(id)->second << std::endl; 
    }
}
