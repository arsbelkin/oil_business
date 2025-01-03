#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
#include "GTN.h"


template<typename T>
bool GTNetwork::bfs(T s, T t, std::vector<T>& parent, std::unordered_map<T, std::unordered_map<T, int>> &capacity) {
    std::unordered_set<T> visited;
    std::queue<T> q;
    q.push(s);
    visited.insert(s);

    while (!q.empty()) {
        auto& u = q.front();
        q.pop();

        for (auto& v : this->graph.at(u)) {
            if (visited.find(v) == visited.end() && capacity[u][v] > 0) {
                visited.insert(v);
                parent[v] = u;
                if (v == t) {
                    return true;
                }
                q.push(v);
            }
        }
    }
    return false;
}


template<typename T>
int GTNetwork::edmondsKarp(const T& source, const T& sink) { 

    std::unordered_map<T, std::unordered_map<T, int>> capacity;

    for (const auto& pair : graph) {
        for (auto& v : pair.second) {
            capacity[pair.first][v] = this->getCapacity(pair.first, v);
        }
    }

    std::vector<T> parent(this->graph.size());
    int maxFlow = 0;

    while (this->bfs(source, sink, parent, capacity)) {
        int pathFlow = this->INF;
        for (auto v = sink; v != source; v = parent[v]) {
            auto u = parent[v];
            pathFlow = std::min(pathFlow, capacity[u][v]);
        }

        for (auto v = sink; v != source; v = parent[v]) {
            auto u = parent[v];
            capacity[u][v] -= pathFlow;
            capacity[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }


    this->maxFlow_path = this->getMAXFlowPath(source, sink, parent);
    return maxFlow;
}


template<typename T>
std::vector<T> GTNetwork::getMAXFlowPath(const T& source, const T& sink, std::vector<T> &parent) {
    std::vector<T> path;
    for (auto v = sink; v != source; v = parent[v]) {
        path.push_back(v);
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}
