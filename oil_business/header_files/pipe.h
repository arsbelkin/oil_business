#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>


class Pipe{
private:
    static int current_pipeID;

    int id;

    std::string name;
    int length;
    int diameter;
    bool is_working;

    std::vector<int> links = {0, 0};

public:
    Pipe();
    Pipe(const int diameter);
    Pipe(std::ifstream &file);

    static int get_currentId();
    int get_id() const;
    std::string get_name() const;
    bool get_IsWorking() const;
    int get_diameter() const;

    bool InUsing() const;
    std::vector<int> get_links() const;
    bool set_links(const int& out, const int& in);

    static void clear_currentID();
    static void set_currentID(const std::unordered_map<int, Pipe>& data);
    
    std::string work_to_string() const;
    void edit_work_status();

    friend std::ostream& operator << (std::ostream &os, const Pipe &pipe);
    void save(std::ofstream &file) const;
};
