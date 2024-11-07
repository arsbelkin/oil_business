#pragma once
#include <unordered_map>


#define PRINT_WORKLOAD(elem) elem workload * 100 << "%"


class CompressorStation{
private:
    static int current_csID;

    int id;

    std::string name;
    int number_of_workshops;
    int workshops_in_work;
    float workload;
    
public:
    CompressorStation();
    CompressorStation(std::ifstream &file);

    static int get_currentId();
    int get_id() const;
    std::string get_name() const;
    float get_workload() const;

    static void clear_currentID();
    static void set_currentID(const std::unordered_map<int, CompressorStation>& data);

    void calc_workload();
    void edit_workshop_status(int choice);
    void save(std::ofstream &file) const;

    friend std::ostream& operator << (std::ostream &os, const CompressorStation &compressor_station);
};
