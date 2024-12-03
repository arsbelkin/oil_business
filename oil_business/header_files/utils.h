#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>
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
int get_maxKey(const std::unordered_map<int, T> &objs){
    int id=-1;
    for (auto &[k,v]: objs){
        if (k > id) id = k;
    }
    return id;
}
