#include <iostream>
#include "../header_files/filter.h"
#include "../header_files/utils.h"

using namespace std;


bool checkByIsWorking(const Pipe &pipe, const bool is_working){
    return pipe.get_IsWorking() == is_working;
}


void findByIsWorking(const std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes){
    cout << "working status(0 - no / 1 - yes): ";
    int work_status = GetCorrectNumber<int>("working status(0 - no / 1 - yes): ", 0, 1);

    findByFilter<Pipe, bool>(pipes, selected_pipes, checkByIsWorking, work_status);
}


bool checkByUnusedWorkshops(const CompressorStation &compressor_station, const float unused_workshops){
    return (100 - compressor_station.get_workload() * 100) > unused_workshops;
}


void findByUnusedWorkshops(const std::unordered_map<int, CompressorStation> &c_ss, std::unordered_set<int> &selected_css){
    cout << "percent of unused workshops: ";
    float unused_wokshops = GetCorrectNumber<float>("percent of unused workshops: ", 0, 1000000);

    findByFilter<CompressorStation, float>(c_ss, selected_css, checkByUnusedWorkshops, unused_wokshops);
}


// std::unordered_set<int> SelectSubSet(const std::unordered_set<int>& set){
//     std::unordered_set<int> subset;
//     selectByID(set, subset);
//     return subset;
// }
