#pragma once
#include <iostream>
#include<math.h>
#include<map>
#include<vector>
#include <sstream>
#include<stack>
#include<limits>
#define D 1e-8
#define Pi 3.14159265359
//double phi = (sqrt(5) + 1) / 2;
double F(std::vector<double>Var,std::string Equation);
double TriFuction(int index,double value);
double minGolden(double min, double max);
double dX();
std::string Powell(std::map < std::string, std::vector<double> >v, std::string e);
std::string Newton(std::map < std::string, std::vector<double>>v, std::string e);
std::string Steep_Descent(std::map < std::string, std::vector<double>>v, std::string e);
std::string Quasi_Newton(std::map < std::string, std::vector<double>>v, std::string e);
std::string Conjugate_Gradient(std::map < std::string, std::vector<double>>v, std::string e);
std::string Postfix();
double STRtoD(std::string);
int priority(char op);