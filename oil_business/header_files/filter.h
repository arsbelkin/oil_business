#pragma once
#include <pipe.h>
#include <compressor_station.h>
#include <utils.h>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>


template<typename T, typename K>
using Filter = bool(*)(const T &obj, const K& param);

template<typename T>
std::unordered_set<int> selectByID(const T &set){
    std::unordered_set<int> subset;
    int id;
    
    while (true){
        std::cout << "input id(0 for exit): ";
        id = GetCorrectNumber<int>("input correct id: ", {0, 1000}, IsInRange);

        if (id == 0) return subset;

        if (set.contains(id)) subset.emplace(id);
    }
}


template<typename T, typename K>
bool checkByName(const T &obj, const K& name){
    return obj.get_name().find(name) != std::string::npos;
}


template<typename T, typename K>
void findByFilter(const std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj, Filter<T, K> func, const K& param){
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


bool checkByIsWorking(const Pipe &pipe, const bool& is_working);


void findByIsWorking(const std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes);


bool checkByDiameter(const Pipe &pipe, const int &diameter);


template<typename T>
void selectAll(const std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj){
    for (const auto &pair: obj){
        selected_obj.emplace(pair.first);
    }
}


template<typename T>
void delete_selectedObj(std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj){
    int counter = 0;
    for (auto it = selected_obj.begin(); it != selected_obj.end();){
        erase_obj(obj, *it);
        it = selected_obj.erase(it);
        ++counter;
    }
    std::cout << counter << " objects was erased!" << std::endl;
}


bool checkByUnusedWorkshops(const CompressorStation &compressor_station, const float& unused_workshops);

void findByUnusedWorkshops(const std::unordered_map<int, CompressorStation> &c_ss, std::unordered_set<int> &selected_css);
