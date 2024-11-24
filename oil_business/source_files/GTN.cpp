#include <iostream>
#include "../header_files/GTN.h"
#include "../header_files/filter.h"
#include "../header_files/Kan_by_Volkov.h"

using namespace std;


bool GTNetwork::create_graph(const std::unordered_map<int, CompressorStation>& c_ss, const std::unordered_map<int, Pipe>& pipes){
    int counter = 0;

    for (const auto& [id, cs]: c_ss){
        auto neighbours_pipes = cs.get_links()[1]; // выходящие трубы
        if (neighbours_pipes.size()){
            for (const auto& pipe_id: neighbours_pipes) this->graph[id].emplace(pipes.at(pipe_id).get_links()[1]);
        } else if (cs.InUsing()) {
            this->graph[id] = {};
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

    c_ss.at(output_id).addLink(1, pipe_id);
    pipes.at(pipe_id).set_links(output_id, input_id);
    c_ss.at(input_id).addLink(0, pipe_id);

    return true;
}


bool GTNetwork::make_TS(){
    this->order = Kan_by_Volkov(this->graph);

    cout << "TS: ";
    for (const auto& v: this->order) cout << v << " ";
    cout << endl;

    return 1;
}


bool GTNetwork::eraseObjFromGraph(Pipe& pipe, std::unordered_map<int, CompressorStation>& c_ss, std::unordered_map<int, Pipe>& pipes){
    c_ss.at(pipe.get_links()[0]).delLink(1, pipe.get_id());
    c_ss.at(pipe.get_links()[1]).delLink(0, pipe.get_id());
    pipe.set_links(0, 0);
    
    return 1;
}


bool GTNetwork::eraseObjFromGraph(CompressorStation& cs, std::unordered_map<int, Pipe>& pipes, std::unordered_map<int, CompressorStation>& c_ss){
    for (auto& neig: cs.get_links()){
        for (auto& pipe: neig){
            this->eraseObjFromGraph(pipes.at(pipe), c_ss, pipes);
        }
    }
    
    return 1;
}


bool GTNetwork::clear_graph(std::unordered_map<int, Pipe>& pipes, std::unordered_map<int, CompressorStation>& c_ss){
    for (auto& [id, _]: this->graph){
        this->eraseObjFromGraph(c_ss.at(id), pipes, c_ss);
    }
    return 1;
}
