#include <iostream>
#include "../header_files/pipe.h"
#include "../header_files/pipes_func.h"
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;


void change_selectedPipes_workStatus(std::unordered_map<int, Pipe> &pipes, const std::unordered_set<int> &selected_pipes){
    int counter = 0;
    for (const int &id: selected_pipes){
        pipes.find(id)->second.edit_work_status();
        ++counter;
    }
    cout << counter << " pipes were changed!" << endl;
}
