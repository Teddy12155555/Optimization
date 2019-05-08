#include "Method.h"
double F(std::map<std::string, double>Var, std::string Equation);
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
double dX();
std::string Powell(std::map < std::string, std::vector<double>>v,std::string e) {
	std::string returnValue;
	//
	//
	for (auto i = v.begin(); i != v.end(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout <<" "<< i->second[j];
		}
		std::cout << std::endl;
	}
	std::cout << e << std::endl;
	return returnValue; 
}
std::string Newton(std::map < std::string, std::vector<double>>v, std::string e) {
	std::string returnValue;
	//
	//
	return returnValue; 
}
std::string Steep_Descent(std::map < std::string, std::vector<double>>v, std::string e) {
	std::string returnValue; 
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
double STRtoD(std::string str)
{
	double num;
	std::stringstream ss;
	ss << str;
	ss >> num;
	ss.str("");
	ss.clear();
	return num;
}