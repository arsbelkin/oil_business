#include <iostream>
#include "../header_files/filter.h"
#include "../header_files/utils.h"

using namespace std;


bool checkByIsWorking(const Pipe &pipe, const bool is_working){
    return pipe.get_IsWorking() == is_working;
}


void findByIsWorking(const std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes){
    cout << "working status(0 - no / 1 - yes): ";
    int work_status = valid_int("working status(0 - no / 1 - yes): ", 0, 1);

    findByFilter<Pipe, bool>(pipes, selected_pipes, checkByIsWorking, work_status);
}
