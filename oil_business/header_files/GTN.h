#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "pipe.h"
#include "compressor_station.h"


class GTNetwork{
private:
    std::unordered_map<int, std::unordered_set<int>> graph;
    std::vector<int> order;
public:
    bool create_graph(const std::unordered_map<int, CompressorStation>& c_ss, const std::unordered_map<int, Pipe>& pipes);
    bool add_node(std::unordered_map<int, CompressorStation>& c_ss, std::unordered_map<int, Pipe>& pipes);

    bool make_TS();

    void print_graph() const;
};
