#pragma once
std::string scramble_f(int layer_number);
void data_manager_f(int casenum, int layer_number, int layer_number_new);
std::string get_scramble_f();
void set_time_f(double time);
double get_time();
void timer_f(int layer_number);	
void log(std::string log);
void typeswtch_f(int swtch);
void sessionswtch_f(int swtch);
void screen_f(int keypressed);
double truncate_f(double time);
double get_average_total_f();
double get_average_f(unsigned int averagenumber);
int currentsessionsize_f();
void deletesolve_f();
void plustwo_f();