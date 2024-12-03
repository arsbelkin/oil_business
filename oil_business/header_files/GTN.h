#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "pipe.h"
#include "compressor_station.h"
#include "utils.h"


class GTNetwork{
private:
    template<typename T, typename K>
    using Filter = bool(GTNetwork::*)(const T &obj, const K& param);

    std::unordered_map<int, Pipe> pipes;
    std::unordered_set<int> selected_pipes;

    std::unordered_map<int, CompressorStation> c_ss;
    std::unordered_set<int> selected_css;
    
    std::unordered_map<int, std::unordered_set<int>> graph;
    std::vector<int> order;
public:
    bool eraseObjFromGraph(Pipe& pipe);
    bool eraseObjFromGraph(CompressorStation& cs);

    void print_graph() const;
    bool clear_graph();

    bool create_graph();
    bool add_node();

    bool delPipeFromGraph();
    bool delCSFromGraph();

    bool make_TS();

    template<typename T>
    std::unordered_set<int> selectByID(const T &set);
    bool clear_selected(const bool &choice);

    template<typename T, typename K>
    bool checkByName(const T &obj, const K& name);
    bool checkByIsWorking(const Pipe &pipe, const bool& is_working);
    bool checkByUnusedWorkshops(const CompressorStation &compressor_station, const float& unused_workshops);
    bool checkByDiameter(const Pipe &pipe, const int &diameter);

    template<typename T, typename K>
    bool findByFilter(const std::unordered_map<int, T> &obj, std::unordered_set<int> &selected_obj, Filter<T, K> func, const K& param);
    bool findPipesByIsWorking();
    bool findByUnusedWorkshops();
    int findByDiameter(const int &diameter);

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

    template<typename T>
    bool load_obj(std::ifstream &file, std::unordered_map<int, T> &objs);

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
