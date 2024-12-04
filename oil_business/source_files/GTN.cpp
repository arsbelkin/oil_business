#include <iostream>
#include "../header_files/GTN.h"
#include "../header_files/filter.h"
#include "../header_files/Kan_by_Volkov.h"
#include <fstream>

using namespace std;


bool GTNetwork::create_graph(){
    int counter = 0;
    this->graph.clear();

    for (const auto& [id, cs]: this->c_ss){
        auto neighbours_pipes = cs.get_links()[1]; // выходящие трубы
        if (neighbours_pipes.size()){
            for (const auto& pipe_id: neighbours_pipes) 
                this->graph[id].emplace(this->pipes.at(pipe_id).get_links()[1]);
        } else if (cs.InUsing()) {
            this->graph[id] = {};
        }
        ++counter;
    }
    return bool(counter);
}


void GTNetwork::print_graph() const{
    cout << "graph:" << endl;
    for (const auto& pair: this->graph){
        cout << pair.first << ":";
        for (const auto& v: pair.second){
            cout << " " << v;
        }
        cout << endl;
    }
}


bool GTNetwork::add_node(){
    if (c_ss.size() < 2) 
        return false;

    // откуда выходит труба
    cout << "output id: ";
    int output_id = GetCorrectNumber<int, std::unordered_map<int, CompressorStation>>("output id: ", this->c_ss, IsExistingObj);

    // куда заходит труба
    cout << "input id: ";
    int input_id = GetCorrectNumber<int, std::unordered_map<int, CompressorStation>>("input id: ", this->c_ss, IsExistingObj);

    cout << "pipe's diameter: ";
    int diameter = GetCorrectNumber<int, std::unordered_set<int>>("pipe's diameter: ", {500, 700, 1000, 1400}, IsExistingObj);
    int pipe_id = findByDiameter(diameter);

    this->c_ss.at(output_id).addLink(1, pipe_id);
    this->pipes.at(pipe_id).set_links(output_id, input_id);
    this->c_ss.at(input_id).addLink(0, pipe_id);

    return true;
}


bool GTNetwork::make_TS(){
    this->order = Kan_by_Volkov(this->graph);

    cout << "TS: ";
    if (this->order.size()) {
        for (const auto& v: this->order) 
            cout << v << " ";
    } else {
        cout << "graph has cycle or TS is empty set!" << endl;
    }
    
    cout << endl;

    return 1;
}


bool GTNetwork::eraseObjFromGraph(Pipe& pipe){
    this->c_ss.at(pipe.get_links()[0]).delLink(1, pipe.get_id());
    this->c_ss.at(pipe.get_links()[1]).delLink(0, pipe.get_id());
    pipe.set_links(0, 0);
    
    return 1;
}


bool GTNetwork::eraseObjFromGraph(CompressorStation& cs){
    for (auto& neig: cs.get_links()){
        for (auto& pipe: neig){
            this->eraseObjFromGraph(this->pipes.at(pipe));
        }
    }
    
    return 1;
}


bool GTNetwork::clear_graph(){
    for (auto& [id, _]: this->graph){
        this->eraseObjFromGraph(this->c_ss.at(id));
    }
    return 1;
}


bool GTNetwork::save() const{
    string path_to_file;
    int counter = 0;

    cout << "file name: ";
    INPUT_LINE(cin, path_to_file);

    ofstream file("static/" + path_to_file);

    if (file.is_open()){
        if (this->pipes.empty()) {
            cout << "No pipes" << endl;
        } else {
            for (auto& [_, pipe]: this->pipes){
                pipe.save(file);
                ++counter;
            }
        }

        if (this->c_ss.empty()) {
            cout << "No compressor stations" << endl;
        } else {
            for (auto& cs: this->c_ss){
                cs.second.save(file);
                ++counter;
            }
        }

        file.close();

        cout << counter << " objects was saved!" << endl;
        return 1;
    } else {
        cout << "Error opening file!" << endl;
        return 0;
    }
}

bool GTNetwork::load(){
    string path_to_file="-1";
    int counter = 0;
    
    cout << "file name: ";
    INPUT_LINE(cin, path_to_file)
    ifstream file("static/" + path_to_file);

    if (file.is_open()){
        this->pipes.clear();
        this->selected_pipes.clear();
        
        this->c_ss.clear();
        this->selected_css.clear();

        string line;

        while (file >> line){
            if (line=="Pipe"){
                this->load_obj(file, this->pipes);
                ++counter;
            }

            if (line=="CS"){
                this->load_obj(file, this->c_ss);
                ++counter;
            }
        }
    
        file.close();        
        Pipe::set_currentID(this->pipes);
        CompressorStation::set_currentID(this->c_ss);

    } else {
        cout << "Error opening file!" << endl;
        return 0;
    }

    cout << counter << " objects was added!" << endl;
    return 1;
}


std::ostream& operator << (std::ostream &os, const GTNetwork &gtn){
    if (gtn.pipes.empty()) {
        cout << "No pipes" << endl;
    } else {
        for (auto& pipe: gtn.pipes){
            os << pipe.second << endl;
        }
    }

    if (gtn.c_ss.empty()) {
        cout << "No compressor stations" << endl;
    } else {
        for (auto& cs: gtn.c_ss){
            cout << cs.second << endl;
        }
    }

    return os;
}


bool GTNetwork::change_selectedPipes_workStatus(){
    int counter = 0;
    for (const int &id: this->selected_pipes){
        this->pipes.find(id)->second.edit_work_status();
        ++counter;
    }
    cout << counter << " pipes were changed!" << endl;
    return 1;
}

bool GTNetwork::change_selectedCS_workload(){
    cout << "Stop(1) or Start(2) the workshop: ";
    int counter = 0;
    int choice = GetCorrectNumber<int, std::vector<int>>("Stop(1) or Start(2) the workshop: ", {1, 2}, IsInRange);

    for (const int &id: this->selected_css){
        this->c_ss.find(id)->second.edit_workshop_status(choice);
        ++counter;
    }
    cout << counter << " workshops was changed!" << endl;
    return 1;
}


bool GTNetwork::delPipeFromGraph(){
    int id;
    
    while (true){
        std::cout << "input id(0 for exit): ";
        id = GetCorrectNumber<int, std::unordered_map<int, Pipe>>("input correct id: ", this->pipes, ZeroRange);

        if (id == 0) break;

        if (this->pipes.at(id).InUsing()) 
            this->eraseObjFromGraph(this->pipes.at(id));
    }

    return 1;
}

bool GTNetwork::delCSFromGraph(){
    int id;
    
    while (true){
        std::cout << "input id(0 for exit): ";
        id = GetCorrectNumber<int, std::unordered_map<int, CompressorStation>>("input correct id: ", this->c_ss, ZeroRange);

        if (id == 0) break;

        if (this->c_ss.at(id).InUsing()) 
            this->eraseObjFromGraph(this->c_ss.at(id));
    }

    return 1;
}


int GTNetwork::add_Pipe(){
    Pipe pipe;
    this->pipes.emplace(pipe.get_id(), pipe);

    return pipe.get_id();
}

int GTNetwork::add_CS(){
    CompressorStation CS;
    this->c_ss.emplace(CS.get_id(), CS);

    return CS.get_id();
}


void GTNetwork::print_selectedPipes() const{
    if (this->selected_pipes.size() == 0)
        std::cout << "No selected pipes!" << std::endl;
    
    for (const int &id: this->selected_pipes){
        std::cout << this->pipes.find(id)->second << std::endl; 
    }
}


void GTNetwork::print_selectedCS() const{
    if (this->selected_css.size() == 0)
        std::cout << "No selected CS!" << std::endl;
    
    for (const int &id: this->selected_css){
        std::cout << this->c_ss.find(id)->second << std::endl; 
    }
}

bool GTNetwork::set_selectedPipes_byID(const bool &choice){
    if (!choice)
        this->selected_pipes = this->selectByID(this->pipes);
    else
        this->selected_pipes = this->selectByID(this->selected_pipes);
    
    return 1;
}

bool GTNetwork::set_selectedCS_byID(const bool &choice){
    if (!choice)
        this->selected_css = this->selectByID(this->c_ss);
    else
        this->selected_css = this->selectByID(this->selected_css);

    return 1;
}


bool GTNetwork::clear_selected(const bool &choice){
    if (!choice)
        this->selected_pipes.clear();
    else
        this->selected_css.clear();
    
    return 1;
}


bool GTNetwork::findPipesbyName(){
    std:: cout << "input name: ";
    std::string name;
    INPUT_LINE(std::cin, name);

    findByFilter(this->pipes, this->selected_pipes, &GTNetwork::checkByName, name);
    return 1;
}


bool GTNetwork::findCSbyName(){
    std:: cout << "input name: ";
    std::string name;
    INPUT_LINE(std::cin, name);

    findByFilter(this->c_ss, this->selected_css, &GTNetwork::checkByName, name);
    return 1;
}


bool GTNetwork::selectAllPipes(){
    for (const auto &pair: this->pipes){
        this->selected_pipes.emplace(pair.first);
    }
    return 1;
}

bool GTNetwork::selectAllCS(){
    for (const auto &pair: this->c_ss){
        this->selected_css.emplace(pair.first);
    }
    return 1;
}


bool GTNetwork::del_selectedPipes(){
    int counter = 0;
    for (auto it = this->selected_pipes.begin(); it != this->selected_pipes.end();){
        if (!this->pipes.at(*it).InUsing()){
            erase_obj(this->pipes, *it);
            it = this->selected_pipes.erase(it);
            ++counter;
        } else {
            std::cout << "Pipe " << *it << " used in graph" << std::endl;
            ++it;
        }
    }
    std::cout << counter << " pipes was erased!" << std::endl;
    return 1;
}


bool GTNetwork::del_selectedCS(){
    int counter = 0;
    for (auto it = this->selected_css.begin(); it != this->selected_css.end();){
        if (!this->c_ss.at(*it).InUsing()){
            erase_obj(this->c_ss, *it);
            it = this->selected_css.erase(it);
            ++counter;
        } else {
            std::cout << "CS " << *it << " used in graph" << std::endl;
            ++it;
        }
    }
    std::cout << counter << " CS was erased!" << std::endl;
    return 1;
}


int GTNetwork::getDistance(const int& id_1, const int& id_2){
    int min_length = 10001;
    auto neighbours_pipes = this->c_ss.at(id_1).get_links()[1]; // выходящие трубы
    for (const auto& pipeID: neighbours_pipes){
        const auto& pipe = this->pipes.at(pipeID);
        if (pipe.get_links()[1] == id_2)
            if (pipe.get_length() < min_length)
                min_length = pipe.get_length();
    }

    if (min_length == 10001)
        return this->INF;
    else
        return min_length;
}

bool GTNetwork::find_min_dist(){
    if (!this->graph.size()){
        return 0;
    }

     // старт
    cout << "output id: ";
    int start_id = GetCorrectNumber<int, std::unordered_map<int, std::unordered_set<int>>>("output id: ", this->graph, IsExistingObj);

    // конец
    cout << "input id: ";
    int stop_id = GetCorrectNumber<int, std::unordered_map<int, std::unordered_set<int>>>("input id: ", this->graph, IsExistingObj);

    this->min_path = this->metodDeikstra(start_id, stop_id);

    cout << "min path: ";
    if (this->min_path.size()) {
        for (const auto& v: this->min_path) 
            cout << v << " ";
    } else {
        cout << "cant find min path!" << endl;
    }
    
    cout << endl;

    return 1;
}
