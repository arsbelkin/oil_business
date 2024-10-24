#pragma once


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

    void calc_workload();
    void edit_workshop_status();
    void save(std::ofstream &file) const;
    int get_id() const;

    friend std::ostream& operator << (std::ostream &os, const CompressorStation &compressor_station);
};


void load(std::ifstream &file, std::unordered_map<int, CompressorStation> &c_ss);
void add_compressorStation(std::unordered_map<int, CompressorStation> &c_ss);
