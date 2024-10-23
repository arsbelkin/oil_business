#pragma once


// struct Pipe{
//     // труба
//     std::string name;
//     int length;
//     int diameter;
//     bool is_working;
// }; +

// bool is_created(const Pipe &pipe); +

// std::string work_to_string(const Pipe &pipe); +

// void edit_work_status(Pipe &pipe); +

// std::ostream& operator << (std::ostream &os, const Pipe &pipe); +

// void add_pipe(Pipe &pipe); +

// void save(std::ofstream &file, const Pipe &pipe); +

// void load(std::ifstream &file, Pipe &pipe);


class Pipe{
private:
    int id;

public:
    static int current_pipeID;

    std::string name;
    int length;
    int diameter;
    bool is_working;

    Pipe();

    int get_id() const;

    bool is_created() const;
    std::string work_to_string() const;
    void edit_work_status();

    friend std::ostream& operator << (std::ostream &os, const Pipe &pipe);
    void save(std::ofstream &file) const;
};


void add_pipe(std::unordered_map<int, Pipe> &pipes);
