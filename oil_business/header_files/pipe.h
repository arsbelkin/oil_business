#pragma once


class Pipe{
private:
    static int current_pipeID;

    int id;

    std::string name;
    int length;
    int diameter;
    bool is_working;

public:
    Pipe();
    Pipe(std::ifstream &file);

    int get_id() const;
    
    std::string work_to_string() const;
    void edit_work_status();

    friend std::ostream& operator << (std::ostream &os, const Pipe &pipe);
    void save(std::ofstream &file) const;
};


void load(std::ifstream &file, std::unordered_map<int, Pipe> &pipes);
void add_pipe(std::unordered_map<int, Pipe> &pipes);
