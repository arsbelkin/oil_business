#include <iostream>
#include "../header_files/menu.h"
#include "../header_files/utils.h"
#include "../header_files/filter.h"
#include "../header_files/logger.h"
#include "../header_files/GTN.h"
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <format>

using namespace std;
using namespace chrono;


// pipe menu
void print_pipes_menu(){
    cout << endl;
    cout << endl;
    cout << "-----Menu pipe-----\n";
    cout << "0 - back\n";
    cout << "1 - add pipe\n";
    cout << "2 - select pipes\n";
    cout << "--------------\n";
}

void pipes_menu(GTNetwork& gtn){
    while (true){
        print_pipes_menu();

        int choice = GetCorrectNumber<int, std::vector<int>>("input number: ", {0, 2}, IsInRange);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gtn.add_Pipe();
            break;
        case 2:
            select_pipes_menu(gtn);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_select_pipes_menu(){
    cout << endl;
    cout << endl;
    cout << "-----Menu select pipe-----\n";
    cout << "0 - back\n";
    cout << "1 - see selected pipes\n";
    cout << "2 - edit selected pipes\n";
    cout << "3 - select from filter\n";
    cout << "4 - choose ids from selected\n";
    cout << "5 - remove from selected\n";
    cout << "--------------\n";
}

void select_pipes_menu(GTNetwork& gtn){
    while (true){
        print_select_pipes_menu();

        int choice = GetCorrectNumber<int, std::vector<int>>("input number: ", {0, 5}, IsInRange);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gtn.print_selectedPipes();
            break;
        case 2:
            edit_pipes_menu(gtn);
            break;
        case 3:
            filter_pipe_menu(gtn);
            break;
        case 4:
            gtn.set_selectedPipes_byID(1);
            break;
        case 5:
            gtn.clear_selected(0);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_filter_pipe(){
    cout << endl;
    cout << endl;
    cout << "-----Menu filter pipe-----\n";
    cout << "*new selections are added to the old ones*\n";
    cout << "0 - back\n";
    cout << "1 - select all pipes\n";
    cout << "2 - select by id\n";
    cout << "3 - select by name\n";
    cout << "4 - select by work status\n";
    cout << "--------------\n";
}

void filter_pipe_menu(GTNetwork& gtn){
    while (true){
        print_filter_pipe();

        int choice = GetCorrectNumber<int, std::vector<int>>("input number: ", {0, 4}, IsInRange);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gtn.selectAllPipes();
            break;
        case 2:
            gtn.set_selectedPipes_byID(0);
            break;
        case 3:
            gtn.findPipesbyName();
            break;
        case 4:
            gtn.findPipesByIsWorking();
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_edit_pipe_menu(){
    cout << endl;
    cout << endl;
    cout << "-----Menu edit pipe-----\n";
    cout << "0 - back\n";
    cout << "1 - change work status for selected pipes\n";
    cout << "2 - delete selected pipes\n";
    cout << "--------------\n";
}

void edit_pipes_menu(GTNetwork& gtn)
{
    while (true){
        print_edit_pipe_menu();

        int choice = GetCorrectNumber<int, std::vector<int>>("input number: ", {0, 2}, IsInRange);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gtn.change_selectedPipes_workStatus();
            break;
        case 2:
            gtn.del_selectedPipes();
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}


// CS menu
void print_CS_menu(){
    cout << endl;
    cout << endl;
    cout << "-----Menu C Station-----\n";
    cout << "0 - back\n";
    cout << "1 - add C Station\n";
    cout << "2 - select C Station\n";
    cout << "--------------\n";
}

void CS_menu(GTNetwork& gtn){
    while (true){
        print_CS_menu();

        int choice = GetCorrectNumber<int, std::vector<int>>("input number: ", {0, 2}, IsInRange);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gtn.add_CS();
            break;
        case 2:
            select_CS_menu(gtn);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_select_CS_menu(){
    cout << endl;
    cout << endl;
    cout << "-----Menu select C Station-----\n";
    cout << "0 - back\n";
    cout << "1 - see selected CS\n";
    cout << "2 - edit selected CS\n";
    cout << "3 - select from filter\n";
    cout << "4 - choose ids from selected\n";
    cout << "5 - remove from selected\n";
    cout << "--------------\n";
}

void select_CS_menu(GTNetwork& gtn){
    while (true){
        print_select_CS_menu();

        int choice = GetCorrectNumber<int, std::vector<int>>("input number: ", {0, 5}, IsInRange);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gtn.print_selectedCS();
            break;
        case 2:
            edit_CS_menu(gtn);
            break;
        case 3:
            filter_CS_menu(gtn);
            break;
        case 4:
            gtn.set_selectedCS_byID(1);
            break;
        case 5:
            gtn.clear_selected(1);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_filter_CS(){
    cout << endl;
    cout << endl;
    cout << "-----Menu filter CS-----\n";
    cout << "*new selections are added to the old ones*\n";
    cout << "0 - back\n";
    cout << "1 - select all CS\n";
    cout << "2 - select by id\n";
    cout << "3 - select by name\n";
    cout << "4 - select by unused workshops\n";
    cout << "--------------\n";
}

void filter_CS_menu(GTNetwork& gtn){
    while (true){
        print_filter_CS();

        int choice = GetCorrectNumber<int, std::vector<int>>("input number: ", {0, 4}, IsInRange);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gtn.selectAllCS();
            break;
        case 2:
            gtn.set_selectedCS_byID(0);
            break;
        case 3:
            gtn.findCSbyName();
            break;
        case 4:
            gtn.findByUnusedWorkshops();
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_edit_CS_menu(){
    cout << endl;
    cout << endl;
    cout << "-----Menu edit CS-----\n";
    cout << "0 - back\n";
    cout << "1 - change number of active workshops\n";
    cout << "2 - delete selected CS\n";
    cout << "--------------\n";
}

void edit_CS_menu(GTNetwork& gtn)
{
    while (true){
        print_edit_CS_menu();

        int choice = GetCorrectNumber<int, std::vector<int>>("input number: ", {0, 2}, IsInRange);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gtn.change_selectedCS_workload();
            break;
        case 2:
            gtn.del_selectedCS();
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}


// GTN menu
void print_GTN_menu(){
    cout << endl;
    cout << endl;
    cout << "-----Menu GTN-----\n";
    cout << "0 - back\n";
    cout << "1 - print graph\n";
    cout << "2 - make TS\n";
    cout << "3 - create graph\n";
    cout << "4 - edit GTN\n";
    cout << "--------------\n";
}

void GTN_menu(GTNetwork& gtn){
    while (true){
        print_GTN_menu();

        int choice = GetCorrectNumber<int, std::vector<int>>("input number: ", {0, 4}, IsInRange);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gtn.print_graph();
            break;
        case 2:
            gtn.make_TS();
            break;
        case 3:
            gtn.create_graph();
            break;
        case 4:
            edit_GTN_menu(gtn);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_edit_GTN_menu(){
    cout << endl;
    cout << endl;
    cout << "-----Menu edit GTN-----\n";
    cout << "0 - back\n";
    cout << "1 - add node\n";
    cout << "2 - delete pipes\n";
    cout << "3 - delete CSs\n";
    cout << "4 - clear graph\n";
    cout << "--------------\n";
}

void edit_GTN_menu(GTNetwork& gtn){
    while (true){
        print_edit_GTN_menu();

        int choice = GetCorrectNumber<int, std::vector<int>>("input number: ", {0, 4}, IsInRange);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gtn.add_node();
            break;
        case 2:
            gtn.delPipeFromGraph();
            break;
        case 3:
            gtn.delCSFromGraph();
            break;
        case 4:
            gtn.clear_graph();
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}


// main menu
void print_main_menu(){
    cout << endl;
    cout << endl;
    cout << "-----Menu-----\n";
    cout << "0 - exit\n";
    cout << "1 - pipes actions\n";
    cout << "2 - compressor stations actions\n";
    cout << "3 - GTN actions\n";
    cout << "4 - see all objects\n";
    cout << "5 - save in file\n";
    cout << "6 - load from file\n";
    cout << "--------------\n";
};

void main_menu(){
    Logger logger("log_" + std::string(std::format("{:%d_%m_%Y_%H_%M}", system_clock::now())) + ".txt");
    
    GTNetwork gtn;

    while (true){
        print_main_menu();

        int choice = GetCorrectNumber<int, std::vector<int>>("input number: ", {0, 6}, IsInRange);

        switch (choice)
        {
        case 0:
            cout << endl;
            cout << "Goodbye!\n";
            return;
        case 1:
            pipes_menu(gtn);
            break;
        case 2:
            CS_menu(gtn);
            break;
        case 3:
            GTN_menu(gtn);
            break;
        case 4:
            cout << gtn;
            break;
        case 5:
            gtn.save();
            break;
        case 6:
            gtn.load();
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
};
