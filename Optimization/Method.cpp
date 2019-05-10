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
	double L = 0;
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
		L = lambda(v0, e);
		v1 = v0 + L * h;
		cout << "i:	" << i << endl;
		cout << "h:	" << h << endl;
		cout << "lamda:	" << L << endl;
		cout << "v:	" << v1 << endl;
		cout << "F(v):	"<< F(v1, e) << endl;
		cout << "-------------" << endl;
		i++;
	} while (abs(F(v0, e) - F(v1, e)) > error);

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
	std::string returnValue; 
	//
	//
	return returnValue; 
}