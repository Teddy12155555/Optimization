#include "Method.h"
int priority(char op) {
	switch (op) {
	case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':
		return 2;
	case '^':return 4;
	case '+': case '-': return 1;
	case '*': case '/': return 3;
	default:            return -1;
	}
}
double TriFuction(int index, double value)
{
	double var;
	switch (index)
	{
	case 0:
		return sin(value * (Pi/180));
	case 1:
		return cos(value * (Pi/180));
	case 2:
		return tan(value * (Pi / 180));
	case 3:
		return 1/ (tan(value * (Pi / 180)));
	case 4:
		return 1/(cos(value * (Pi / 180)));
	case 5:
		return 1 / (sin(value * (Pi / 180)));
	default:
		return 0;
		break;
	}
}
double F(std::vector<double>Var, std::string Equation)
{
	std::vector<std::string>alterVar{ "x","y" };
	std::vector<std::string>Trigonometric{ "sin","cos","tan","cot","sec","csc" };
	std::vector<std::string>Trtemp{ "a","b","c","d","e","f" };
	//alter var to value
	for (int i = 0; i < Var.size(); i++)
	{
		while (Equation.find(alterVar[i]) != std::string::npos)
		{
			auto pos = Equation.find(alterVar[i]);
			Equation.erase(pos, alterVar[i].length());
			Equation.insert(pos, std::to_string(Var[i]));
		}
	}
	bool flag = false;
	for (int i = 0; i < Trigonometric.size(); i++)
	{
		if (Equation.find(Trigonometric[i]) != std::string::npos)
		{
			flag = true;
			break;
		}
	}
	Equation += ")"; Equation.insert(0, "(");
	//postfix
	std::stack<char>st; 
	std::vector<double>post;
	std::vector<char>operators;
	if (flag)
	{
		//Trigonometric
		for (int i = 0; i < 6; i++)
		{
			while (Equation.find(Trigonometric[i])!=std::string::npos)
			{
				auto pos = Equation.find(Trigonometric[i]);
				Equation.erase(pos, 4);
				Equation.insert(pos,Trtemp[i]);
				for (auto j = pos; j < Equation.length(); j++)
				{
					if (Equation[j] == ')')
					{
						pos = j;
						break;
					}
				}
				Equation.erase(pos, 1);
			}
		}
	}
	bool str_flag = false;
	std::string temp;
	std::cout << Equation << std::endl;
	for (int i = 0; i < Equation.length(); i++)
	{
		char tttt = Equation[i];
		switch (Equation[i])
		{
		case '(':
			if (str_flag)
			{
				post.push_back(STRtoD(temp));
				temp.clear();
				str_flag = false;
			}
			st.push(Equation[i]);
			break;
		case '+': case '-': case '*': case '/': case '^': case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':
			if (str_flag)
			{
				post.push_back(STRtoD(temp));
				temp.clear();
				str_flag = false;
			}
			if (priority(st.top()) >= priority(Equation[i]))
			{
				while (priority(st.top()) >= priority(Equation[i]))
				{
					post.push_back(DBL_MAX);
					operators.push_back(st.top());
					st.pop();
				}
				st.push(Equation[i]);
			}
			else
				st.push(Equation[i]);
			break;
		case ')':
			if (str_flag)
			{
				post.push_back(STRtoD(temp));
				temp.clear();
				str_flag = false;
			}
			while (st.top() != '(')
			{
				post.push_back(DBL_MAX);
				operators.push_back(st.top());
				st.pop();
			}
			st.pop();
			break;
		default:
			str_flag = true;
			temp += Equation[i];
			break;
		}
	}
	int j = 0;
	for (int i = 0; i < post.size(); i++)
	{
		if (post[i] == DBL_MAX)
			std::cout << "  " << operators[j++];
		else
			std::cout << " " << post[i];
	}
	//compute value
	std::vector<double>result;
	int opIndex = 0;
	for (int i = 0; i < post.size(); i++)
	{
		if (post[i] == DBL_MAX)
		{
			switch (operators[opIndex++])
			{
			case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':
				result[result.size() - 1] = TriFuction(operators[opIndex-1]-'a',result[result.size() - 1]);
				break;
			case '+':
				result[result.size() - 2] = result[result.size() - 1] + result[result.size() - 2];
				result.pop_back();
				break;
			case '-':
				result[result.size() - 2] = result[result.size() - 2] - result[result.size() - 1];
				result.pop_back();
				break;
			case '^':
				result[result.size() - 2] = pow(result[result.size() - 2], result[result.size() - 1]);
				result.pop_back();
				break;
			case '*':
				result[result.size() - 2] = result[result.size() - 1] * result[result.size() - 2];
				result.pop_back();
				break;
			case '/':
				result[result.size() - 2] = result[result.size() - 2] / result[result.size() - 1];
				result.pop_back();
				break;
			
			default:
				break;
			}
		}
		else
		{
			result.push_back(post[i]);
		}
	}
	return result[0];
}
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