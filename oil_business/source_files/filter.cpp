#include <iostream>
#include "../header_files/filter.h"

using namespace std;


bool GTNetwork::checkByIsWorking(const Pipe &pipe, const bool& is_working){
    return pipe.get_IsWorking() == is_working;
}


bool GTNetwork::findPipesByIsWorking(){
    cout << "working status(0 - no / 1 - yes): ";
    bool work_status = GetCorrectNumber<int, std::vector<int>>("working status(0 - no / 1 - yes): ", {0, 1}, IsInRange);

    this->findByFilter<Pipe, bool>(pipes, selected_pipes, &GTNetwork::checkByIsWorking, work_status);
    return 1;
}


bool GTNetwork::checkByUnusedWorkshops(const CompressorStation &compressor_station, const float& unused_workshops){
    return (100 - compressor_station.get_workload() * 100) > unused_workshops;
}


bool GTNetwork::findByUnusedWorkshops(){
    cout << "percent of unused workshops: ";
    float unused_wokshops = GetCorrectNumber<float, std::vector<float>>("percent of unused workshops: ", {0, 1000000}, IsInRange);

    this->findByFilter<CompressorStation, float>(c_ss, selected_css, &GTNetwork::checkByUnusedWorkshops, unused_wokshops);
    return 1;
}


bool GTNetwork::checkByDiameter(const Pipe &pipe, const int &diameter){
    return pipe.get_diameter() == diameter;
}


bool GTNetwork::checkByLenght(const Pipe &pipe, const int &length){
    if (length == this->INF){
        return 1;
    }
    return pipe.get_length() == length;
}


int GTNetwork::findByDiameter(const int &diameter, const int& length){
    for (const auto& [id, pipe]: this->pipes){
        if (!pipe.InUsing() && this->checkByDiameter(pipe, diameter) && this->checkByLenght(pipe, length))
            return pipe.get_id();
    }
    
    Pipe pipe(diameter, length);
    this->pipes.emplace(pipe.get_id(), pipe);

    return pipe.get_id();
}
