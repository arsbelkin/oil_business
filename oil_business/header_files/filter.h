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


// template<typename T>
// void selectByID(const T &obj, std::unordered_set<int> &selected_obj){
//     std::string line;
//     int id;

//     std::cout << "input ids: ";
//     INPUT_LINE(std::cin, line);

//     std::istringstream iss(line);

//     while (true){
//         if ((iss >> id) && (obj.contains(id))) {
//             selected_obj.emplace(id);
//         } else {
//             if (iss.eof()) break;

//             iss.clear();
//             iss >> line;
//         }
//     }
// }

template<typename T>
std::unordered_set<int> selectByID(const T &set){
    std::unordered_set<int> subset;

    std::string line;
    int id;

    std::cout << "input ids: ";
    INPUT_LINE(std::cin, line);

    std::istringstream iss(line);

    while (true){
        if ((iss >> id) && (set.contains(id))) {
            subset.emplace(id);
        } else {
            if (iss.eof()) break;
            iss.clear();
        }
    }

    return subset;
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

// std::unordered_set<int> SelectSubSet(const std::unordered_set<int>& set);

// template<typename T, typename K>
// void findSub(const std::unordered_map<int, T> &objs, const std::unordered_set<int> &selected_obj, std::unordered_set<int> &sub_obj, Filter<T, K> func, const K param){
//     for (const int &id: selected_obj){
//         if (func(objs.find(id).second, param)){
//             sub_obj.emplace(objs.find(id).first);
//         }
//     }
// }


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


bool checkByUnusedWorkshops(const CompressorStation &compressor_station, const float unused_workshops);

void findByUnusedWorkshops(const std::unordered_map<int, CompressorStation> &c_ss, std::unordered_set<int> &selected_css);
