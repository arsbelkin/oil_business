#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>


#define PRINT_WORKLOAD(elem) elem workload * 100 << "%"


class CompressorStation{
private:
    static int current_csID;

    int id;

    std::string name;
    int number_of_workshops;
    int workshops_in_work;
    float workload;

    std::vector<std::unordered_set<int>> links = {{}, {}};
    
public:
    CompressorStation();
    CompressorStation(std::ifstream &file);

    static int get_currentId();
    int get_id() const;
    std::string get_name() const;
    float get_workload() const;

    std::vector<std::unordered_set<int>> get_links() const;
    bool InUsing() const;
    void set_links(std::ifstream &file, const int& pos);
    bool addLink(const int& pos, const int& id);
    bool delLink(const int& pos, const int& id);

    static void clear_currentID();
    static void set_currentID(const std::unordered_map<int, CompressorStation>& data);

    void calc_workload();
    void edit_workshop_status(int choice);
    void save(std::ofstream &file) const;

    friend std::ostream& operator << (std::ostream &os, const CompressorStation &compressor_station);
};
