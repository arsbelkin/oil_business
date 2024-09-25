#include <iostream>
#include "../header_files/pipe.h"
#include "../header_files/compressor_station.h"
#include "../header_files/menu.h"

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
    cout << "7 - upload from file\n";
    cout << "--------------\n";
};


void see_all_objects(const Pipe &pipe, const CompressorStation &compressor_station){
    cout << pipe;
    cout << compressor_station;
}


void save_menu(const Pipe &pipe, const CompressorStation &compressor_station){
    int choice;
    cout << "1 - save pipe or 2 - save CS: ";
    cin >> choice;

    if (choice == 1){
        save(pipe);
    } else {
        save(compressor_station);
    }
}


void main_menu(){
    Pipe pipe = {"", -1, -1, 0};
    CompressorStation compressor_station = {"", -1, -1, -1};

    while (true){
        print_main_menu();


        int choice;
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Goodbye!\n";
            return;
        case 1:
            add_pipe(pipe);
            break;
        case 2:
            add_compressorStation(compressor_station);
            break;
        case 3:
            see_all_objects(pipe, compressor_station);
            break;
        case 4:
            edit_work_status(pipe);
            break;
        case 5:
            edit_workshop_status(compressor_station);
            break;
        case 6:
            save_menu(pipe, compressor_station);
            break;
        case 7:
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
};
