struct CompressorStation{
    // компрессорная станция
    std::string name;
    int number_of_workshops;
    int workshops_in_work;
    float efficiency;
};

bool is_created(const CompressorStation &compressor_station);

std::ostream& operator << (std::ostream &os, const CompressorStation &compressor_station);

void add_compressorStation(CompressorStation &compressor_station);
