#pragma once
#include "compressor_station.h"
#include <unordered_map>
#include <unordered_set>


void change_selectedCS_workload(std::unordered_map<int, CompressorStation> &c_ss, const std::unordered_set<int> &selected_css);
