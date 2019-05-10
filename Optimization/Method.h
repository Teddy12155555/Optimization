#pragma once
#include"Math.h"
#define error 1e-8
double minGolden(double min, double max);
std::string Powell(std::map < std::string, std::vector<double> >v, std::string e);
std::string Newton(std::map < std::string, std::vector<double>>v, std::string e);
std::string Steep_Descent(std::map < std::string, std::vector<double>>v, std::string e);
std::string Quasi_Newton(std::map < std::string, std::vector<double>>v, std::string e);
std::string Conjugate_Gradient(std::map < std::string, std::vector<double>>v, std::string e);