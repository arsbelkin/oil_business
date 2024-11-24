#include <iostream>
#include "../header_files/pipe.h"
#include <fstream>
#include "../header_files/compressor_station.h"
#include "../header_files/utils.h"
#include <string>

using namespace std;


int Pipe::current_pipeID = 0;


Pipe::Pipe(){
    cout << "-----add pipe-----\n";

    this->id = ++Pipe::current_pipeID;
    cout << "id: " << this->id << endl;

    cout << "name: ";
    INPUT_LINE(cin, this->name);

    cout << "lenght: ";
    this->length = GetCorrectNumber<int, std::vector<int>>("lenght: ", {1, 10000}, IsInRange);

    cout << "diameter: ";
    this->diameter = GetCorrectNumber<int, std::unordered_set<int>>("diameter: ", {500, 700, 1000, 1400}, IsExistingObj);

    cout << "is_working(0 - no / 1 - yes): ";
    this->is_working = GetCorrectNumber<int, std::vector<int>>("is_working(0 - no / 1 - yes): ", {0, 1}, IsInRange);

    cout << "Pipe is created!\n";

    cout << "------------------\n";
}


Pipe::Pipe(const int diameter){
        cout << "-----add pipe-----\n";

    this->id = ++Pipe::current_pipeID;
    cout << "id: " << this->id << endl;

    cout << "name: ";
    INPUT_LINE(cin, this->name);

    cout << "lenght: ";
    this->length = GetCorrectNumber<int, std::vector<int>>("lenght: ", {1, 10000}, IsInRange);

    this->diameter = diameter;
    cout << "diameter: " << diameter << endl;

    cout << "is_working(0 - no / 1 - yes): ";
    this->is_working = GetCorrectNumber<int, std::vector<int>>("is_working(0 - no / 1 - yes): ", {0, 1}, IsInRange);

    cout << "Pipe is created!\n";

    cout << "------------------\n";
}


Pipe::Pipe(std::ifstream &file){
    file >> this->id;
    file.ignore(10000, '\n');
    getline(file>>std::ws, this->name);
    file >> this->length;
    file >> this->diameter;
    file >> this->is_working;
    file >> this->links[0];
    file >> this->links[1];
}

int Pipe::get_currentId(){
    return Pipe::current_pipeID;
}


int Pipe::get_id() const{
    return this->id;
}


std::string Pipe::get_name() const{
    return this->name;
}


bool Pipe::get_IsWorking() const{
    return this->is_working;
}


int Pipe::get_diameter() const{
    return this->diameter;
}


bool Pipe::InUsing() const{
    return (this->links[0]) || (this->links[1]);
}

std::vector<int> Pipe::get_links() const{
    return this->links;
}


bool Pipe::set_links(const int& out, const int& in){
    this->links = {out, in};
    return 1;
}


void Pipe::clear_currentID(){
    Pipe::current_pipeID=1;
}


void Pipe::set_currentID(const unordered_map<int, Pipe>& data) {
    Pipe::current_pipeID=get_maxKey(data);
}


string Pipe::work_to_string() const{
    return this->is_working ? "yes" : "no";
}


void Pipe::edit_work_status(){
    this->is_working = !this->is_working;
}


ostream& operator << (ostream &os, const Pipe &pipe){
    os << "-----Pipe " << pipe.get_id() << "-----" << endl
        << "id: " << pipe.get_id() << endl
        << "name: " << pipe.name << endl
        << "lenght: " << pipe.length << endl
        << "diameter: " << pipe.diameter << endl
        << "is working: " << pipe.work_to_string() << endl
        << "links{" << endl
        << "   " << "out: "
        << pipe.links[0] << " " << endl
        << "   " << "in: "
        << pipe.links[1] << " "
        << endl << "}" << endl
        << "--------------" << endl;

    return os;
}


void Pipe::save(ofstream &file) const{
    file << "Pipe" << endl;
    file << this->id << endl;
    file << this->name << endl;
    file << this->length << endl;
    file << this->diameter << endl;
    file << this->is_working << endl;
    file << this->links[0] << endl;
    file << this->links[1] << endl;
}
