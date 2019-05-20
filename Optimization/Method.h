#pragma once
#include"Math.h"
#define error 1e-8
double minGolden(double min, double max, vector<double>s, vector<double>Var, std::string Equation);
std::stringstream Powell(std::map < std::string, std::vector<double> >v, std::string e);
std::stringstream Newton(std::map < std::string, std::vector<double>>v, std::string e);
std::stringstream Steep_Descent(std::map < std::string, std::vector<double>>v, std::string e);
std::stringstream Quasi_Newton(std::map < std::string, std::vector<double>>v, std::string e);
std::stringstream Conjugate_Gradient(std::map < std::string, std::vector<double>>v, std::string e);

bool inInterval(std::map < std::string, std::vector<double>>&v, vector<double>& ve);