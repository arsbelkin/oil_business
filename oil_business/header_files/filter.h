#pragma once
#include <pipe.h>
#include <compressor_station.h>
#include <utils.h>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>


template<typename T, typename K>
using Filter = bool(*)(const T &obj, const K param);


template<typename T>
void selectByID(const std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj){
    std::cout << "input ids: ";

    std::string line;
    INPUT_LINE(std::cin, line);
    std::istringstream iss(line);
    int id;

    while (true){
        if ((iss >> id) && (obj.count(id) > 0)) {
            selected_obj.emplace(id);
        } else {
            if (iss.eof()) break;

            iss.clear();
            iss >> line;
        }
    }
}


template<typename T, typename K>
bool checkByName(const T &obj, const K name){
    return obj.get_name() == name;
}


template<typename T, typename K>
void findByFilter(const std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj, Filter<T, K> func, const K param){
    for (const auto &pair: obj){
        if (func(pair.second, param)){
            selected_obj.emplace(pair.first);
        }
    }
}

template<typename T>
void findByName(const std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj){
    std:: cout << "input name: ";
    std::string name;
    INPUT_LINE(std::cin, name);

    findByFilter(obj, selected_obj, checkByName, name);
}


bool checkByIsWorking(const Pipe &pipe, const bool is_working);


void findByIsWorking(const std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes);


template<typename T>
void selectAll(const std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj){
    for (const auto &pair: obj){
        selected_obj.emplace(pair.first);
    }
}
