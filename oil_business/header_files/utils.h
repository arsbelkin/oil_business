#pragma once


void save_obj(std::unordered_map<int, Pipe> &pipes, std::unordered_map<int, CompressorStation> &c_ss);

void load_obj(Pipe &pipe, CompressorStation &compressor_station);

int valid_int(std::string message, int min_value, int max_value);

void see_all_objects(const std::unordered_map<int, Pipe> &pipes, const std::unordered_map<int, CompressorStation> &c_ss);
