#pragma once
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include "GTN.h"


template<typename T>
std::unordered_set<int> GTNetwork::selectByID(const T &set){
    std::unordered_set<int> subset;
    int id;
    
    while (true){
        std::cout << "input id(0 for exit): ";
        id = GetCorrectNumber<int, std::vector<int>>("input correct id: ", {0, 1000}, IsInRange);

        if (id == 0) return subset;

        if (set.contains(id)) subset.emplace(id);
    }
}


template<typename T, typename K>
bool GTNetwork::checkByName(const T &obj, const K& name){
    return obj.get_name().find(name) != std::string::npos;
}


template<typename T, typename K>
bool GTNetwork::findByFilter(const std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj, Filter<T, K> func, const K& param){
    for (const auto &pair: obj){
        if ((this->*func)(pair.second, param)){
            selected_obj.emplace(pair.first);
        }
    }
    return 1;
}
