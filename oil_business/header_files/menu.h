#pragma once
#include <unordered_set>


void print_main_menu();

void main_menu();

void print_pipes_menu();

void print_select_pipes_menu();

void select_pipes_menu(std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes);

void pipes_menu(std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes);

void print_CS_menu();

void CS_menu(std::unordered_map<int, CompressorStation> &c_ss);

void print_filter_pipe();

void filter_pipe_menu(std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes);
