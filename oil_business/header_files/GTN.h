#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "pipe.h"
#include "compressor_station.h"
#include "utils.h"


class GTNetwork{
private:
    std::unordered_map<int, std::unordered_set<int>> graph;
    std::vector<int> order;
public:
    bool eraseObjFromGraph(Pipe& pipe, std::unordered_map<int, CompressorStation>& c_ss, std::unordered_map<int, Pipe>& pipes);
    bool eraseObjFromGraph(CompressorStation& cs, std::unordered_map<int, Pipe>& pipes, std::unordered_map<int, CompressorStation>& c_ss);

    bool clear_graph(std::unordered_map<int, Pipe>& pipes, std::unordered_map<int, CompressorStation>& c_ss);

    bool create_graph(const std::unordered_map<int, CompressorStation>& c_ss, const std::unordered_map<int, Pipe>& pipes);
    bool add_node(std::unordered_map<int, CompressorStation>& c_ss, std::unordered_map<int, Pipe>& pipes);

    template<typename T, typename K>
    bool delObj(std::unordered_map<int, T>& obj_1, std::unordered_map<int, K>& obj_2);

    bool make_TS();

    void print_graph() const;
};


template<typename T, typename K>
bool GTNetwork::delObj(std::unordered_map<int, T>& obj_1, std::unordered_map<int, K>& obj_2){
    int id;
    
    while (true){
        std::cout << "input id(0 for exit): ";
        id = GetCorrectNumber<int, std::unordered_map<int, T>>("input correct id: ", obj_1, ZeroRange);

        if (id == 0) break;

        if (obj_1.at(id).InUsing()) this->eraseObjFromGraph(obj_1.at(id), obj_2, obj_1);
    }

    return 1;
}
