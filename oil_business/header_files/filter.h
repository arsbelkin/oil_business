#pragma once
#include <pipe.h>
#include <utils.h>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>


template<typename T>
using Filter = bool(*)(const Pipe &pipe, T param);

//TODO: edit func 
template<typename T>
void selectByID(const std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj){
    std::cout << "input id: ";

    std::string line;
    INPUT_LINE(std::cin, line);
    std::istringstream iss(line);
    int id;

    while (true){
        if ((iss >> id) && (obj.count(id) > 0)) {
            selected_obj.emplace(id);
        } else {
            if (iss.eof()){
                break;
            }
            iss.clear();
            iss >> line;
        }
    }

    // while (iss >> id){
    //     if (obj.count(id) > 0){
            
    //     }
    // }
}
