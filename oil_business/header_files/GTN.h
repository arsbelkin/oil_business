#pragma once
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "pipe.h"
#include "compressor_station.h"
#include "utils.h"

class GTNetwork{
private:
    template<typename T, typename K>
    using Filter = bool(GTNetwork::*)(const T &obj, const K& param);

    const int INF = std::numeric_limits<int>::max();

    std::unordered_map<int, Pipe> pipes;
    std::unordered_set<int> selected_pipes;

    std::unordered_map<int, CompressorStation> c_ss;
    std::unordered_set<int> selected_css;
    
    std::unordered_map<int, std::unordered_set<int>> graph;
    std::vector<int> order;
    std::vector<int> min_path;

    bool eraseObjFromGraph(Pipe& pipe);
    bool eraseObjFromGraph(CompressorStation& cs);

    template<typename T>
    void erase_obj(T &objs, const int id);

    template<typename T>
    bool load_obj(std::ifstream &file, std::unordered_map<int, T> &objs);

    template<typename T, typename K>
    bool checkByName(const T &obj, const K& name);
    bool checkByIsWorking(const Pipe &pipe, const bool& is_working);
    bool checkByUnusedWorkshops(const CompressorStation &compressor_station, const float& unused_workshops);
    bool checkByDiameter(const Pipe &pipe, const int &diameter);

    template<typename T, typename K>
    bool findByFilter(const std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj, Filter<T, K> func, const K& param);
    int findByDiameter(const int &diameter);

    template<typename T>
    std::vector<T> metodDeikstra(T StartNode, T EndNode);
public:
    void print_graph() const;
    bool clear_graph();

    bool create_graph();
    bool add_node();

    bool delPipeFromGraph();
    bool delCSFromGraph();

    bool make_TS();
    int getDistance(const int& id_1, const int& id_2);
    bool find_min_dist();

    template<typename T>
    std::unordered_set<int> selectByID(const T &set);
    bool clear_selected(const bool &choice);
    
    bool findPipesByIsWorking();
    bool findByUnusedWorkshops();

    int add_Pipe();
    void print_selectedPipes() const;
    bool set_selectedPipes_byID(const bool &choice);
    bool change_selectedPipes_workStatus();
    bool findPipesbyName();
    bool selectAllPipes();
    bool del_selectedPipes();

    int add_CS();
    void print_selectedCS() const;
    bool set_selectedCS_byID(const bool &choice);
    bool change_selectedCS_workload();
    bool findCSbyName();
    bool selectAllCS();
    bool del_selectedCS();

    bool save() const;
    bool load();

    friend std::ostream& operator << (std::ostream &os, const GTNetwork &gtn);
};


template<typename T>
bool GTNetwork::load_obj(std::ifstream &file, std::unordered_map<int, T> &objs){
    T obj(file);
    objs.emplace(obj.get_id(), obj);
    return 1;
}

template<typename T>
void GTNetwork::erase_obj(T &objs, const int id){
    if (objs.contains(id)){
        objs.erase(id);
    } else {
        std::cout << "There is not object with id " << id << std::endl;
    }
}





template<typename T>
std::vector<T> GTNetwork::metodDeikstra(T StartNode, T EndNode) {
	std::unordered_map<T, int> dist;
	std::unordered_map<T, T> prev;
	std::unordered_set<T> visited;


    for (const auto& pair : this->graph) {
        dist[pair.first] = INF;
    }
    dist[StartNode] = 0;

    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int, T>>> pq;
    pq.push({0, StartNode});

	while (!pq.empty()) {
		T u = pq.top().second;
		pq.pop();

		if (u == EndNode) { break; }

		visited.insert(u);

        for (const auto& v : this->graph.at(u)) {
            if (visited.find(v) == visited.end()) {
                int weight = this->getDistance(u, v);
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.push({dist[v], v});
                }
            }
		}
	}

    std::vector<T> path;
    T current_node = EndNode;
    while (current_node != StartNode) {
        path.push_back(current_node); 
        if (prev.find(current_node) != prev.end()) {
            current_node = prev[current_node];
        } else {
            return std::vector<T>();
        }
    }
	
    path.push_back(StartNode);
    reverse(path.begin(), path.end());
    return path;
}
