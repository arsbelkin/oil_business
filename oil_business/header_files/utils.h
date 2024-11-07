#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <typeinfo>
#include <string>


#define INPUT_LINE(in, str) in.ignore(1000, '\n'); \
                            getline(in>>std::ws, str); \
                            std::cerr << str << std::endl;


#define CLEAR_SELECTED(selected) selected.clear(); \
                                std::cout << "Selected cleared!" << std::endl;


template <typename T>
T GetCorrectNumber(const std::string message, const int min_value, const int max_value){
    T value;

    while ((std::cin >> value).fail() 
            || std::cin.peek() != '\n'
            || value < min_value || value > max_value)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << message;
    }
    std::cerr << value << std::endl;
    return value;
}

void save_obj(const std::unordered_map<int, Pipe> &pipes, const std::unordered_map<int, CompressorStation> &c_ss);

void load_obj(std::unordered_map<int, Pipe> &pipes, std::unordered_map<int, CompressorStation> &c_ss, std::unordered_set<int> &selected_pipe, std::unordered_set<int> &selected_css);

void see_all_objects(const std::unordered_map<int, Pipe> &pipes, const std::unordered_map<int, CompressorStation> &c_ss);


template<typename T>
void erase_obj(std::unordered_map<int, T> &objs, const int id){
    if (objs.count(id)){
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
void load(std::ifstream &file, std::unordered_map<int, T> &objs){
    T obj(file);
    objs.emplace(obj.get_id(), obj);
}


template<typename T>
void add_obj(std::unordered_map<int, T> &objs){
    T obj;
    objs.emplace(obj.get_id(), obj);
}

template<typename T>
int get_maxKey(const std::unordered_map<int, T> &objs){
    int id=-1;
    for (auto &[k,v]: objs){
        if (k > id) id = k;
    }
    return id;
}
