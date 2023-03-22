#include <iostream>
#include <cmath>
#include <chrono>
#include "function header.h"
#include <conio.h>
#include <stdio.h>
#include <thread>

#define space 32

double RoundMil_f(double& time) {	//Round numbers to the nearest thousandth
	time = time * 1000;
	time = std::round(time);
	time = time / 1000;
	return time;
}

static bool isoff = false;

void timerout() {
	double onscreentime = 0;
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	start = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::ratio<1, 1>> duration;
	while (!isoff) {
		system("cls");
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		double time = duration.count();
		secondstodisplay(RoundMil_f(time));
		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
	isoff = false;
}

void timer_f(int layer_number) {
	double time = 0;
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<double, std::ratio<1, 1>> duration;
	start = std::chrono::high_resolution_clock::now();
	int ch = 0;
	std::thread ostimer(timerout);
	ch = _getch();
	end = std::chrono::high_resolution_clock::now();
	isoff = true;
	ostimer.join();
	duration = end - start;
	time = duration.count();
	set_time_f(RoundMil_f(time));
}