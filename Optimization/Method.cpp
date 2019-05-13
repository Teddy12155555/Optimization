#include "Method.h"

double minGolden(double min, double max)
{
	//double up = min + (max - min) / phi;
	//double dowm = max - (max - min) / phi;

	/*while (fabs(up - dowm) > C)
	{
		if (F(dowm) < F(up))
			max = up;
		else
			min = dowm;

		up = min + (max - min) / phi;
		dowm = max - (max - min) / phi;
	}*/

	return (max + min) / 2;
}
std::string Powell(std::map < std::string, std::vector<double>>v,std::string e) {
	std::string returnValue;
	//
	//
	
	/*for (auto i = v.begin(); i != v.end(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout <<" "<< i->second[j];
		}
		std::cout << std::endl;
	}
	std::cout << e << std::endl;*/
	std::vector<double>t{v["x"][0],v["y"][0]};
	double a = F(t, e);
	std::cout << a << "!!!!!!!!!!!!!!!!\n";
	return returnValue; 
}
std::string Newton(std::map < std::string, std::vector<double>>v, std::string e) {
	std::string returnValue;
	//
	//
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