#pragma once
#include <pipe.h>
#include <unordered_map>


void load(std::ifstream &file, std::unordered_map<int, Pipe> &pipes);
void add_pipe(std::unordered_map<int, Pipe> &pipes);

void erase_pipe(std::unordered_map<int, Pipe> &pipes, int id);

//void selectByID(std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes);
