#include"Math.h"
vector<double> operator *(const vector<vector<double>>& m1, const vector<double>& v) {
	vector<double> re(v.size(), 0);
	for (int i = 0; i < v.size(); i++) 
		for (int j = 0; j < m1[i].size(); j++) 
			re[i] += m1[i][j] * v[j];
	return re;
}
vector<double> operator *(const vector<double>& v,const vector<vector<double>>& m1) {
	vector<double> re(v.size(), 0);
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < m1[i].size(); j++)
			re[i] += m1[i][j] * v[j];
	return re;
}
double operator *(const vector<double>& v1, const vector<double>& v2) {
	double re = 0;
	for (int i = 0; i < v1.size(); i++)
		re += v1[i] * v2[i];
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
vector<double> operator - (const vector<double>& v) {
	vector<double> re(v.size());
	for (int i = 0; i < re.size(); ++i)
		re[i] = -v[i];
	return re;
}
vector<double> operator *(const double d, const vector<double>& v) {
	vector<double> re(v.size());
	for (int i = 0; i < re.size(); ++i)
		re[i] = d * v[i];
	return re;
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
		vector<double> h(1,1e-4);
		double dxx = (F(var + h + h, Equation) - 2 * F(var, Equation) + F(var - h - h, Equation)) / (4 * h[0] * h[0] );
		return vector<vector<double>> (1, vector<double>(1, dxx));;
	}
	else {
		vector<double> hx(2,0), hy(2,0);

		hx[0] = hy[1] = 1e-4;
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
double lambda(vector<double>& var, std::string Equation) {
	vector<vector<double>> A = Hessian(var, Equation);
	vector<double> h =  -gradient(var, Equation) ;
	return (h * h) / ((A * h)*h);
}
double alpha(vector<double>& var, vector<double>& s, std::string Equation) {
	vector<vector<double>> A = Hessian(var, Equation);
	vector<double> h = -gradient(var, Equation);
	return (h * h) / ((A * s)*s);
}
ostream& operator <<(ostream& os, const vector<double>& v) {
	os << "[ ";
	for (int i = 0; i < v.size(); i++) {
		if (i)
			os << ", " << v[i];
		else
			os << v[i];
	}
	os << " ]";
	return os;
}
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
		return sin(value );
	case 1:
		return cos(value );
	case 2:
		return tan(value );
	case 3:
		return 1 / (tan(value ));
	case 4:
		return 1 / (cos(value ));
	case 5:
		return 1 / (sin(value ));
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
	//
	for (int i = 0; i < Var.size(); i++)
	{
		while (Equation.find(alterVar[i]) != std::string::npos)
		{
			auto pos = Equation.find(alterVar[i]);
			Equation.erase(pos, alterVar[i].length());
			Equation.insert(pos, std::to_string(Var[i]));
		}
	}
#ifdef DEBUG
	cout << Equation << endl;
#endif
	for (int i = 1;  i < Equation.size()-1; i++)
	{
		if (Equation[i] == '-' && isdigit(Equation[i - 1]) == 0)
			Equation[i] = '@';
		else
			continue;
	}
	if (Equation[0] == '-')
		Equation[0] = '@';
#ifdef DEBUG
	cout << Equation << endl;
	std::cout << Equation << std::endl;
#endif // DEBUG

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
#ifdef DEBUG
	std::cout << Equation << std::endl;
#endif
	if (flag)
	{
		//Trigonometric
		for (int i = 0; i < 6; i++)
		{
			while (Equation.find(Trigonometric[i]) != std::string::npos)
			{
				auto pos = Equation.find(Trigonometric[i]);
				Equation.erase(pos, 4);
				Equation.insert(pos, Trtemp[i]);
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
	//std::cout << Equation << std::endl;
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
		case '@':
			str_flag = true;
			temp += "-";
			break;
		default:
			str_flag = true;
			temp += Equation[i];
			break;
		}
	}
	int j = 0;
#ifdef DEBUG
	for (int i = 0; i < post.size(); i++)
	{
		if (post[i] == DBL_MAX)
			std::cout << "  " << operators[j++];
		else
			std::cout << " " << post[i];
	}
	std::cout << std::endl;
#endif
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
				result[result.size() - 1] = TriFuction(operators[opIndex - 1] - 'a', result[result.size() - 1]);
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
double STRtoD(std::string str)
{
	double num;
	std::stringstream ss;
	int couut = 0;
	for (int i = 0; i < str.length(); i++)
		if (!(isdigit(str[i])))
			couut++;
	int temp = 1;
	if (couut > 1)
	{
		
		int index = 0;
		while (isdigit(str[index]) == 0)
		{
			if (str[index] == '-')
				temp *= -1;
			else
				temp *= 1;
			index++;
		}
		str.erase(0, index);
	}
	ss << str;
	ss >> num;
	ss.str("");
	ss.clear();
	num *= temp;
	return num;
}
double vlen(const vector<double>& v) {
	double re = 0;
	for (auto i : v) 
		re += i*i;
	return sqrt(re);
}