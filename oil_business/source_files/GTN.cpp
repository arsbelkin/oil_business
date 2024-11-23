#include <iostream>
#include "../header_files/GTN.h"
#include "../header_files/utils.h"
#include "../header_files/filter.h"

using namespace std;


bool GTNetwork::create_graph(const std::unordered_map<int, CompressorStation>& c_ss){
    int counter = 0;

    for (const auto& cs: c_ss){
        auto neighbours = cs.second.get_links()[1];
        if (neighbours.size()){
            for (const auto& v: neighbours) this->graph[v].push_back(v);
        } else {
            this->graph[cs.first] = {};
        }
        ++counter;
    }
    return bool(counter);
}


void GTNetwork::print_graph() const{
    cout << "graph:" << endl;
    for (const auto& pair: this->graph){
        cout << pair.first << ":";
        for (const auto& v: pair.second){
            cout << " " << v;
        }
        cout << endl;
    }
}


bool GTNetwork::add_node(std::unordered_map<int, CompressorStation>& c_ss, std::unordered_map<int, Pipe>& pipes){
    if (!c_ss.size()) return false;

    // откуда выходит труба
    cout << "output id: ";
    int output_id = GetCorrectNumber<int, std::unordered_map<int, CompressorStation>>("output id: ", c_ss, IsExistingObj);

    // куда заходит труба
    cout << "input id: ";
    int input_id = GetCorrectNumber<int, std::unordered_map<int, CompressorStation>>("input id: ", c_ss, IsExistingObj);

    cout << "pipe's diameter: ";
    int diameter = GetCorrectNumber<int, std::unordered_set<int>>("pipe's diameter: ", {500, 700, 1000, 1400}, IsExistingObj);
    int pipe_id = findByDiameter(diameter, pipes);

    

}
