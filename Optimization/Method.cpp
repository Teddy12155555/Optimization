#include "Method.h"
#define phi 1.6180339988
#define limit 1000
double minGolden(double min, double max, vector<double>s, vector<double>Var, std::string Equation)
{
	int lit = 0;
	double up = min + (max - min) / phi;
	double down = max - (max - min) / phi;
	while (fabs(up - down) > error)
	{
		lit++;
		if (f(down,s,Var,Equation) < f(up,s,Var,Equation))
			max = up;
		else
			min = down;
		
		up = min + (max - min) / phi;
		down = max - (max - min) / phi;
		if (lit > limit)break;
	}

	return (max + min) / 2;
}
std::string Powell(std::map < std::string, std::vector<double>>v,std::string e) {
	std::string returnValue;
	//
	//input
	int d = v.size();
	vector<double> X;
	vector <double>v0,v1;
	vector <double>boundary;//if one [1][2] or two [1][2][1][2]
	vector<vector<double>>s;
	for (auto i = v.begin(); i != v.end(); i++) {
		v0.push_back(i->second[0]);
		for (int j = 1; j <= 2; j++)
			boundary.push_back(i->second[j]);
	}
	//initial
	// v0 is X1 
	// X = f(x)
	// S initial
	if (d == 1)
		s.push_back(vector<double>(1, 1));
	else
	{
		vector<double>temp(2, 0);
		temp[0] = 1; s.push_back(temp);
		temp[0] = 0; temp[1] = 1; s.push_back(temp);
		temp[0] = 1; s.push_back(temp);
	}
	int j = 0; 
	//initial done
	//cout << F(v0, e) << "!!!!!!!!!!!!!!!!!!!\n";
	do 
	{
		int lit = 0;
		cout << j << endl;
		v1 = v0;
		int i = 0;
		if (d == 1)
		{
			cout << v0 << endl;
			 double Xdown = (boundary[0] - v0[0]) / s[0][0], Xup = (boundary[1] - v0[0]) / s[0][0];
			 double a1 = minGolden(Xdown, Xup, s[0], v0, e);
			 cout << "alpha : " << a1 << endl;
			 cout << s[0] << endl;
			 v0 = v0 + a1 * s[0];
			 cout << v0 << endl;
			 s[0][0] = a1;
			 cout << s[0] << endl;
		}
		else
		{
			cout << i+1 << endl;
			double sp = 0;
			if (s[0][0] != 0)sp = s[0][0]; else sp = s[0][1];
			double Xdown = (boundary[0] - v0[0]) / sp, Xup = (boundary[1] - v0[0]) / sp;
			double a1 = minGolden(Xdown,Xup,s[0],v0,e);
			v0 = v0 + a1 * s[0]; ///////1 
			i++;
			cout << i+1 << endl;
			if (s[1][1] != 0)sp = s[1][1]; else sp = s[1][0];
			double Ydown = (boundary[2] - v0[1]) / s[1][1], Yup = (boundary[3] - v0[1]) / s[1][1];
			double a2 = minGolden(Ydown, Yup, s[1],v0,e);
			v0 = v0 + a2 * s[1]; ///////2
			i++;
			cout << i+1 << endl;
			s[2] = a1 * s[0] + a2 * s[1];
			if (s[2][0] != 0)sp = s[2][0]; else sp = s[2][1];
			Xdown = (boundary[0] - v0[0]) / s[2][0], Xup = (boundary[1] - v0[0]) / s[2][0];
			if (s[2][1] != 0)sp = s[2][1]; else sp = s[2][0];
			Ydown = (boundary[2] - v0[1]) / s[2][1], Yup = (boundary[3] - v0[1]) / s[2][1];
			Xdown > Ydown ? Xdown = Xdown : Xdown = Ydown; Xup < Yup ? Xup = Xup : Xup = Yup;
			double a3 = minGolden(Xdown,Xup,s[2],v0,e);
			v0 = v0 + a3 * s[2]; ////////3
			s[0] = s[1]; s[1] = s[2];
		}
		j++;
		if (lit > limit)break;
	} while (abs(F(v0,e)-F(v1,e)) > error);
	cout << v0 << endl;
	return returnValue; 
}
std::string Newton(std::map < std::string, std::vector<double>>v, std::string e) {
	std::string returnValue;
	//
	//
	std::vector<double>v0,v1;
	for (auto i = v.begin(); i != v.end(); i++) {
		v1.push_back(i->second[0]);
	}
	int debug = 0;
	int lit = 0;
		do 
		{
			v0 = v1;
			cout << debug << "	times\n";
			double z;
			bool brek = false;
			std::vector<double> gradTemp = gradient(v0, e);
			std::vector<std::vector<double>> HessianTemp = Hessian2(gradTemp, e);
			for (int i = 0; i < HessianTemp.size(); i++) {
				for (int j =0;j<HessianTemp[i].size();j++ )
					if (HessianTemp[i][j] == DBL_MAX) { brek = true; break; }
				if (brek) break;
			}if (brek) break;
			cout << "Hessian\n";
			for (int i = 0; i < HessianTemp.size(); i++)
				cout << HessianTemp[i] << endl;
			HessianTemp = Inverse(HessianTemp);
			cout << "Hessian inverse\n";
			for (int i = 0; i < HessianTemp.size(); i++)
				cout << HessianTemp[i] << endl;
			v1 = mult(HessianTemp, gradTemp);
			v1 = -1 * v1;
			while ((z = F(v0 + v1,e))!= z )
			{
				for (int i = 0; i < v0.size(); i++)
					v1[i] *= 0.9;
			}
			v1 = v0 + v1;
			cout << "x\n";
			cout << v1 << endl;
			debug++;
			lit++;
			if (lit > limit)break;
			
		} while ((abs(F(v0, e) - F(v1, e)) > error) );
		cout << "min : " << F(v1, e) << endl;
	return returnValue; 
}
std::string Steep_Descent(std::map < std::string, std::vector<double>>v, std::string e) {
	std::string returnValue = ""; 
	double L = 0, z;
	vector<double> h;
	int i = 0;
	vector<double> v0, v1;
	if (v["y"].size() == 0) v1.push_back(v["x"][0]);
	else {
		v1.push_back(v["x"][0]);
		v1.push_back(v["y"][0]);
	}

	do {
		v0 = v1;
		h = -gradient(v0, e);
		if (vlen(h)==0) break;
		L = lambda(v0, e);
		while ((z = F(v0 + L * h, e)) != z)  L *= 0.9; 
		v1 = v0 + L * h;
		cout << "i:	" << i << endl;
		cout << "h:	" << h << endl;
		cout << "lamda:	" << L << endl;
		cout << "v:	" << v1 << endl;
		cout << "F(v):	"<< z << endl;
		cout << "-------------" << endl;
		i++;
	} while (abs(F(v0, e) - z ) > error);

	//
	//
	return returnValue; 
}
std::string Quasi_Newton(std::map < std::string, std::vector<double>>v, std::string e) {
	std::string returnValue;
	//
	//
	return returnValue; 
}
std::string Conjugate_Gradient(std::map < std::string, std::vector<double>>v, std::string e) {

	std::string returnValue = "";
	double a = 0;
	double beta;
	double z;
	vector<double> S0, S1;
	vector<double> v0, v1, v2;
	int i = 0;
	if (v["y"].size() == 0) v1.push_back(v["x"][0]);
	else {
		v1.push_back(v["x"][0]);
		v1.push_back(v["y"][0]);
	}
	do {
		S0 = S1;
		if(!i) S1 = -gradient(v1, e);
		else { 
			beta = (gradient(v1, e) *  gradient(v1, e)) / (gradient(v0, e) *  gradient(v0, e));
			S1 = -gradient(v1, e) + beta * S0;
		}
		v0 = v1;
		a = alpha(v1, S1, e);
		while ((z = F(v1 + a * S1,e)) != z) a *= 0.9;
		v1 = v1 + a * S1;
		cout << "i:	" << i << endl;
		if(i) cout << "beta:	" << beta << endl;
		cout <<"Si:	" << S1 << endl;
		cout << "alpha:	" << a << endl;
		cout << "v:	" << v1 << endl;
		cout << "F(v):	" << z << endl;
		cout << "-------------" << endl;
		i++;
	} while (abs(F(v0, e) - z) > error);


	//
	//
	return returnValue; 
}