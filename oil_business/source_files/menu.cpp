#include <iostream>
#include "../header_files/pipe.h"
#include "../header_files/compressor_station.h"
#include "../header_files/menu.h"
#include "../header_files/utils.h"
#include <unordered_map>

using namespace std;


void print_main_menu(){
    cout << "-----Menu-----\n";
    cout << "0 - exit\n";
    cout << "1 - add pipe\n";
    cout << "2 - add compressor station\n";
    cout << "3 - see all objects\n";
    cout << "4 - edit pipe\n";
    cout << "5 - edit compressor station\n";
    cout << "6 - save in file\n";
    cout << "7 - load from file\n";
    cout << "--------------\n";
};


void main_menu(){
    // Pipe pipe = {"", -1, -1, 0};
    // CompressorStation compressor_station = {"", -1, -1, -1};

    unordered_map<int, Pipe> pipes;
    unordered_map<int, CompressorStation> c_ss;


    while (true){
        print_main_menu();

        int choice = valid_int("input number: ", 0, 7);

        switch (choice)
        {
        case 0:
            cout << "Goodbye!\n";
            return;
        case 1:
            add_pipe(pipes);
            break;
        case 2:
            add_compressorStation(c_ss);
            break;
        case 3:
            see_all_objects(pipes, c_ss);
            break;
        case 4:
            //edit_work_status(pipe);
            break;
        case 5:
            //edit_workshop_status(compressor_station);
            break;
        case 6:
            save_obj(pipes, c_ss);
            break;
        case 7:
            //load_obj(pipe, compressor_station);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
};
