#pragma once
#include <unordered_set>
#include <unordered_map>


// main menu
void print_main_menu();
void main_menu();


// pipe menu
void print_pipes_menu();
void pipes_menu(std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes);

void print_select_pipes_menu();
void select_pipes_menu(std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes);

void print_filter_pipe();
void filter_pipe_menu(std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes);

void print_edit_pipe_menu();
void edit_pipes_menu(std::unordered_map<int, Pipe> &pipes, std::unordered_set<int> &selected_pipes);


// CS menu
void print_CS_menu();
void CS_menu(std::unordered_map<int, CompressorStation> &c_ss, std::unordered_set<int> &selected_css);

void print_select_CS_menu();
void select_CS_menu(std::unordered_map<int, CompressorStation> &c_ss, std::unordered_set<int> &selected_css);

void print_filter_CS();
void filter_CS_menu(std::unordered_map<int, CompressorStation> &c_ss, std::unordered_set<int> &selected_css);

void print_edit_CS_menu();
void edit_CS_menu(std::unordered_map<int, CompressorStation> &c_ss, std::unordered_set<int> &selected_css);
