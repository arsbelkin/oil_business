#pragma once
#include <pipe.h>
#include <unordered_map>
#include <unordered_set>


void load(std::ifstream &file, std::unordered_map<int, Pipe> &pipes);
void add_pipe(std::unordered_map<int, Pipe> &pipes);

void erase_pipe(std::unordered_map<int, Pipe> &pipes, const int id);

void change_selectedPipes_workStatus(std::unordered_map<int, Pipe> &pipes, const std::unordered_set<int> &selected_pipes);
