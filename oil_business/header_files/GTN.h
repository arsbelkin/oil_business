#pragma once
#include <unordered_map>
#include <vector>
#include "pipe.h"
#include "compressor_station.h"


class GTNetwork{
private:
    std::unordered_map<int, std::vector<int>> graph;
public:
    bool create_graph(const std::unordered_map<int, CompressorStation>& c_ss);
    bool add_node(std::unordered_map<int, CompressorStation>& c_ss, std::unordered_map<int, Pipe>& pipes);

    void print_graph() const;
};
