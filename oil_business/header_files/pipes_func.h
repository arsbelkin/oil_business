#pragma once
#include <pipe.h>
#include <unordered_map>
#include <unordered_set>


void change_selectedPipes_workStatus(std::unordered_map<int, Pipe> &pipes, const std::unordered_set<int> &selected_pipes);
