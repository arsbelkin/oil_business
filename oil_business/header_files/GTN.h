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
    std::vector<int> maxFlow_path;
    int maxFlow;

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
    bool checkByLenght(const Pipe &pipe, const int &length);

    template<typename T, typename K>
    bool findByFilter(const std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj, Filter<T, K> func, const K& param);
    int findByDiameter(const int &diameter, const int& length);

    template<typename T>
    std::vector<T> metodDeikstra(T StartNode, T EndNode);

    template<typename T>
    bool bfs(T s, T t, std::vector<T>& parent, std::unordered_map<T, std::unordered_map<T, int>> &capacity);
    
    template<typename T>
    int edmondsKarp(const T& source, const T& sink);

    template<typename T>
    std::vector<T> getMAXFlowPath(const T& source, const T& sink, std::vector<T> &parent);

    bool show_MinPath();
    bool show_maxFlow();
public:
    void print_graph() const;
    bool clear_graph();

    bool create_graph();
    bool add_node();

    bool delPipeFromGraph();
    bool delCSFromGraph();

    bool make_TS();
    int getDistance(const int& id_1, const int& id_2);
    int getAbsoluteDistance(const int& id_1, const int& id_2);
    bool find_min_dist();
    int getCapacity(const int& id_1, const int& id_2);
    bool count_maxFlow();

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
    std::unordered_set<int> get_IncidentPipes(const int& id_1, const int& id_2);

    bool save() const;
    bool load();

    friend std::ostream& operator << (std::ostream &os, const GTNetwork &gtn);
};
