#pragma once
#include <iostream>
#include<math.h>
#include<stack>
#include<limits>
#include<vector>
#include<map>
#include<string>
#include <sstream>
#define D 1e-8
#define Pi 3.14159265359
using std::vector;
using std::ostream;
using std::map;
using std::string;
using std::cout;
using std::endl;
//矩陣*向量
vector<double> operator *(const vector<vector<double>>& m1, const vector<double>& v);
//向量*矩陣
vector<double> operator *(const vector<double>& v, const vector<vector<double>>& m1);
// 向量+-*
double operator *(const vector<double>& v1, const vector<double>& v2);
vector<double> operator + (const vector<double>& v1, const vector<double>& v2);
vector<double> operator - (const vector<double>& v1, const vector<double>& v2);
//向量scalar
vector<double> operator *(const double d, const vector<double>& v2);
//輸出
ostream& operator <<(ostream& os, const vector<double>& v);

// 負向量
vector<double> operator - (const vector<double>& v);
//梯度(微分)
vector<double> gradient(vector<double>& var, std::string Equation);
//黑塞矩陣
vector<vector<double>> Hessian(const vector<double>& var, const string& Equation);
//lambda
double lambda(vector<double>& var, std::string Equation);

//函式處理
double F(std::vector<double>Var, std::string Equation);
double TriFuction(int index, double value);
double STRtoD(std::string);
int priority(char op);
//向量長度
double vlen(const vector<double>& v);