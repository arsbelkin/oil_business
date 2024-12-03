#pragma once
#include <GTN.h>


// main menu
void print_main_menu();
void main_menu();


// pipe menu
void print_pipes_menu();
void pipes_menu(GTNetwork& gtn);

void print_select_pipes_menu();
void select_pipes_menu(GTNetwork& gtn);

void print_filter_pipe();
void filter_pipe_menu(GTNetwork& gtn);

void print_edit_pipe_menu();
void edit_pipes_menu(GTNetwork& gtn);


// CS menu
void print_CS_menu();
void CS_menu(GTNetwork& gtn);

void print_select_CS_menu();
void select_CS_menu(GTNetwork& gtn);

void print_filter_CS();
void filter_CS_menu(GTNetwork& gtn);

void print_edit_CS_menu();
void edit_CS_menu(GTNetwork& gtn);


// GTN menu
void print_GTN_menu();
void GTN_menu(GTNetwork& gtn);

void print_edit_GTN_menu();
void edit_GTN_menu(GTNetwork& gtn);
