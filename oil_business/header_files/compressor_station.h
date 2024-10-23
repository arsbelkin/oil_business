#pragma once


// struct CompressorStation{
//     // компрессорная станция
//     std::string name;
//     int number_of_workshops;
//     int workshops_in_work;
//     float workload;
// }; +

// bool is_created(const CompressorStation &compressor_station); +

// std::ostream& operator << (std::ostream &os, const CompressorStation &compressor_station); +

// void calc_workload(CompressorStation &compressor_station); +

// void add_compressorStation(CompressorStation &compressor_station);

// void edit_workshop_status(CompressorStation &compressor_station); +

// void save(std::ofstream &file, const CompressorStation &compressor_station); +

// void load(std::ifstream &file, CompressorStation &compressor_station);


class CompressorStation{
private:
    static int current_csID;
    int id;
public:
    // компрессорная станция
    std::string name;
    int number_of_workshops;
    int workshops_in_work;
    float workload;

    CompressorStation();

    bool is_created() const;
    void calc_workload();
    void edit_workshop_status();
    void save(std::ofstream &file) const;
    int get_id() const;

    friend std::ostream& operator << (std::ostream &os, const CompressorStation &compressor_station);
};


void add_compressorStation(std::unordered_map<int, CompressorStation> &c_ss);
