#pragma once
#include "GTN.h"


template<typename T>
bool GTNetwork::load_obj(std::ifstream &file, std::unordered_map<int, T> &objs){
    T obj(file);
    objs.emplace(obj.get_id(), obj);
    return 1;
}

template<typename T>
void GTNetwork::erase_obj(T &objs, const int id){
    if (objs.contains(id)){
        objs.erase(id);
    } else {
        std::cout << "There is not object with id " << id << std::endl;
    }
}
