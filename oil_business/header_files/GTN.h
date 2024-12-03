#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
public:
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
