#pragma once
#include<vector>
#include<map>
#include<string>
using namespace std;
vector<double> operator *(const vector<vector<double>>& m1, const vector<double>& v);
vector<double> operator *(const vector<double>& v1, const vector<double>& v2);
vector<double> operator + (const vector<double>& v1, const vector<double>& v2);
vector<double> operator - (const vector<double>& v1, const vector<double>& v2);
double F(const vector<double>& var, std::string Equation);
