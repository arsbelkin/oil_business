#include <iostream>
#include "../header_files/compressor_station.h"
#include "../header_files/pipe.h"
#include "../header_files/CS_func.h"
#include "../header_files/utils.h"
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;


void change_selectedCS_workload(std::unordered_map<int, CompressorStation> &c_ss, const std::unordered_set<int> &selected_css){
    cout << "Stop(1) or Start(2) the workshop: ";
    int counter = 0;
    int choice = GetCorrectNumber<int>("Stop(1) or Start(2) the workshop: ", {1, 2}, IsInRange);

    for (const int &id: selected_css){
        c_ss.find(id)->second.edit_workshop_status(choice);
        ++counter;
    }
    cout << counter << " workshops was changed!" << endl;
}
