#pragma once
#include <iostream>


#define INPUT_LINE(in, str) in.ignore(1000, '\n'); \
                            getline(in>>std::ws, str);


void save_obj(const std::unordered_map<int, Pipe> &pipes, const std::unordered_map<int, CompressorStation> &c_ss);

void load_obj(std::unordered_map<int, Pipe> &pipes, std::unordered_map<int, CompressorStation> &c_ss);

int valid_int(const std::string message, const int min_value, const int max_value);

void see_all_objects(const std::unordered_map<int, Pipe> &pipes, const std::unordered_map<int, CompressorStation> &c_ss);
