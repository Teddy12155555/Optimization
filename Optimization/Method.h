#pragma once
#include <iostream>
#include<math.h>
#include<map>
#include<vector>
#define D 1e-8
//double phi = (sqrt(5) + 1) / 2;
double F(std::map<std::string,double>Var,std::string Equation);
double minGolden(double min, double max);
double dX();
std::string Powell();
std::string Newton();
std::string Steep_Descent();
std::string Quasi_Newton();
std::string Conjugate_Gradient();
std::string Postfix();