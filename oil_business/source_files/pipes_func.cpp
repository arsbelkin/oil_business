#include <iostream>
#include "../header_files/pipe.h"
#include "../header_files/pipes_func.h"
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;


void load(std::ifstream &file, unordered_map<int, Pipe> &pipes){
    Pipe pipe(file);
    pipes.emplace(pipe.get_id(), pipe);
}


void add_pipe(unordered_map<int, Pipe> &pipes){
    Pipe pipe;
    pipes.emplace(pipe.get_id(), pipe);
}


void erase_pipe(unordered_map<int, Pipe> &pipes, const int id){
    if (pipes.count(id)){
        pipes.erase(id);
        cout << "Pipe " << id << " erased!" << endl;
    } else {
        cout << "There is not pipe with this id!" << endl;
    }
}


void change_selectedPipes_workStatus(std::unordered_map<int, Pipe> &pipes, const std::unordered_set<int> &selected_pipes){
    for (const int &id: selected_pipes){
        pipes.find(id)->second.edit_work_status();
    }
}
