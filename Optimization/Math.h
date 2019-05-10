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
//�x�}*�V�q
vector<double> operator *(const vector<vector<double>>& m1, const vector<double>& v);
//�V�q*�x�}
vector<double> operator *(const vector<double>& v, const vector<vector<double>>& m1);
// �V�q+-*
double operator *(const vector<double>& v1, const vector<double>& v2);
vector<double> operator + (const vector<double>& v1, const vector<double>& v2);
vector<double> operator - (const vector<double>& v1, const vector<double>& v2);
//�V�qscalar
vector<double> operator *(const double d, const vector<double>& v2);
//��X
ostream& operator <<(ostream& os, const vector<double>& v);

// �t�V�q
vector<double> operator - (const vector<double>& v);
//���(�L��)
vector<double> gradient(vector<double>& var, std::string Equation);
//�¶�x�}
vector<vector<double>> Hessian(const vector<double>& var, const string& Equation);
//lambda
double lambda(vector<double>& var, std::string Equation);

//�禡�B�z
double F(std::vector<double>Var, std::string Equation);
double TriFuction(int index, double value);
double STRtoD(std::string);
int priority(char op);
//�V�q����
double vlen(const vector<double>& v);