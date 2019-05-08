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
std::string Powell() { 
	std::string returnValue;
	//
	//
	return returnValue; 
}
std::string Newton() { 
	std::string returnValue;
	//
	//
	return returnValue; 
}
std::string Steep_Descent() { 
	std::string returnValue; 
	//
	//
	return returnValue; 
}
std::string Quasi_Newton() { 
	std::string returnValue;
	//
	//
	return returnValue; 
}
std::string Conjugate_Gradient() {
	std::string returnValue; 
	//
	//
	return returnValue; 
}