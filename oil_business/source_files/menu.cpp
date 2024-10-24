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
    cout << "1 - pipes actions\n";
    cout << "2 - compressor stations actions\n";
    cout << "3 - see all objects\n";
    cout << "4 - save in file\n";
    cout << "5 - load from file\n";
    cout << "--------------\n";
};


void print_pipes_menu(){
    cout << "-----Menu pipe-----\n";
    cout << "0 - back\n";
    cout << "1 - add pipe\n";
    cout << "2 - select pipes\n";
    cout << "--------------\n";
}


void pipes_menu(unordered_map<int, Pipe> &pipes){
    while (true){
        print_pipes_menu();

        int choice = valid_int("input number: ", 0, 2);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            add_pipe(pipes);
            break;
        case 2:
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}


void print_CS_menu(){
    cout << "-----Menu CS-----\n";
    cout << "0 - back\n";
    cout << "1 - add compressor station\n";
    cout << "2 - select compressor stations\n";
    cout << "--------------\n";
}


void CS_menu(unordered_map<int, CompressorStation> &c_ss){
    while (true){
        print_CS_menu();

        int choice = valid_int("input number: ", 0, 2);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            add_compressorStation(c_ss);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}


void main_menu(){
    unordered_map<int, Pipe> pipes;
    unordered_map<int, CompressorStation> c_ss;

    while (true){
        print_main_menu();

        int choice = valid_int("input number: ", 0, 5);

        switch (choice)
        {
        case 0:
            cout << "Goodbye!\n";
            return;
        case 1:
            pipes_menu(pipes);
            break;
        case 2:
            CS_menu(c_ss);
            break;
        case 3:
            see_all_objects(pipes, c_ss);
            break;
        case 4:
            save_obj(pipes, c_ss);
            break;
        case 5:
            load_obj(pipes, c_ss);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
};
