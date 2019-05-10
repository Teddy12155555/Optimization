#include"Math.h"
vector<double> operator *(const vector<vector<double>>& m1, const vector<double>& v) {
	vector<double> re(v.size(), 0);
	for (int i = 0; i < v.size(); i++) 
		for (int j = 0; j < m1[i].size(); j++) 
			re[i] += m1[i][j] * v[i];
	return re;
}
vector<double> operator *(const vector<double>& v1, const vector<double>& v2) {
	vector<double> re(v1.size());
	for (int i = 0; i < v1.size(); i++)
		re[i] = v1[i] * v2[i];
	return re;
}
vector<double> operator + (const vector<double>& v1,const vector<double>& v2) {
	vector<double> re(v1.size());
	for (int i = 0; i < v1.size(); i++)
		re[i] = v1[i] + v2[i];
	return re;
}
vector<double> operator - (const vector<double>& v1, const vector<double>& v2) {
	vector<double> re(v1.size());
	for (int i = 0; i < v1.size(); i++)
		re[i] = v1[i] - v2[i];
	return re;
}
double F(const vector<double>& var, std::string Equation) {
	return 0;
}
vector<double> gradient(vector<double>& var, std::string Equation) {
	if (var.size() == 1) {
		vector<double> h(1, 1e-5);
		double dx = (F(var + h, Equation) - F(var - h, Equation)) / (2 * h[0]);
		return vector<double>(1, dx);
	}
	else {
		vector<double> hx(2, 0), hy(2, 0);
		hx[0] = hy[1] = 1e-5;
		double dx = (F(var + hx, Equation) - F(var - hx, Equation)) / (2 * hx[0]);
		double dy = (F(var + hy, Equation) - F(var - hy, Equation)) / (2 * hx[0]);
		vector<double> re(2);
		re[0] = dx;
		re[1] = dy;
		return re;
	}
}
vector<vector<double>> Hessian(const vector<double>& var, const string& Equation) {
	
	if (var.size() == 1) {
		vector<double> h(1,1e-5);
		double dxx = (F(var + h + h, Equation) - 2 * F(var, Equation) + F(var - h - h, Equation)) / (4 * h[0] * h[0] );
		return vector<vector<double>> (1, vector<double>(1, dxx));;
	}
	else {
		vector<double> hx(2,0), hy(2,0);
		hx[0] = hy[1] = 1e-5;
		double dxx = (F(var + hx + hx, Equation) - 2 * F(var, Equation) + F(var - hx - hx, Equation)) / (4 * hx[0] * hx[0]);
		double dyy = (F(var + hy + hy, Equation) - 2 * F(var, Equation) + F(var - hy - hy, Equation)) / (4 * hx[0] * hx[0]);
		double dxy = (F(var + hx + hy, Equation) - F(var - hx + hy, Equation) - F(var + hx - hy, Equation) + F(var - hx - hy, Equation)) / (4 * hx[0] * hx[0]);
		vector<vector<double>> re(2, vector<double>(2, 0));
		re[0][0] = dxx;
		re[0][1] = re[1][0] = dxy;
		re[1][1] = dyy;
		return re;
	}
}