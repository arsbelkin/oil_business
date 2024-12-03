#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <typeinfo>
#include <string>
#include <vector>


#define INPUT_LINE(in, str) in.ignore(1000, '\n'); \
                            getline(in>>std::ws, str); \
                            std::cerr << str << std::endl;


template<typename T, typename K>
using Func = bool(*)(const T& value, const K& range);


template<typename T, typename K>
bool IsInRange(const T& value, const K& range){
    return (range[0] <= value)&&(value <= range[1]);
}


template<typename T, typename K>
bool ZeroRange(const T& value, const K& objs){
    return IsExistingObj(value, objs) || (value == 0);
}


template<typename T, typename K>
bool IsExistingObj(const T& id, const K& objs){
    return objs.contains(id);
}


template <typename T, typename K>
T GetCorrectNumber(const std::string message, const K& range, Func<T, K> f){
    T value;

    while ((std::cin >> value).fail() 
            || std::cin.peek() != '\n'
            || !f(value, range))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << message;
    }
    std::cerr << value << std::endl;
    return value;
}

template<typename T>
void erase_obj(T &objs, const int id){
    if (objs.contains(id)){
        objs.erase(id);
    } else {
        std::cout << "There is not object with id " << id << std::endl;
    }
}


template<typename T>
void print_selected(const std::unordered_map<int, T> &obj, const std::unordered_set<int> &selected_obj){
    if (selected_obj.size() == 0) std::cout << "No selected!" << std::endl;
    
    for (const int &id: selected_obj){
        std::cout << obj.find(id)->second << std::endl; 
    }
}


template<typename T>
int add_obj(std::unordered_map<int, T> &objs){
    T obj;
    objs.emplace(obj.get_id(), obj);

    return obj.get_id();
}

template<typename T>
int get_maxKey(const std::unordered_map<int, T> &objs){
    int id=-1;
    for (auto &[k,v]: objs){
        if (k > id) id = k;
    }
    return id;
}
