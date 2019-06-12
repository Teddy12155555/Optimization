#include "Method.h"
#define phi 1.6180339988
#define limit 100

template<class T>
string operator +(const char *a, T b) {
	return string(a) + std::to_string(b);
}

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
std::stringstream Powell(std::map < std::string, std::vector<double>>v,std::string e) {
	std::stringstream ss;
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
	int j = 1; 
	//initial done
	//ss<< F(v0, e) << "!!!!!!!!!!!!!!!!!!!\n";
	do 
	{
		ss << "j = " << j << endl;
		int lit = 0;
		//ss<< j << endl;
		v1 = v0;
		int i = 1;
		if (d == 1)
		{
			ss<< "X1:		" << v0 << endl;
			 double Xdown = (boundary[0] - v0[0]) / s[0][0], Xup = (boundary[1] - v0[0]) / s[0][0];
			 double a1 = minGolden(Xdown, Xup, s[0], v0, e);
			 ss<< "alpha:		" << a1 << endl;
			 ss<< "X2:		"<< s[0] << endl;
			 v0 = v0 + a1 * s[0];
			 ss<< "X3:		" << v0 << endl;
			 s[0][0] = a1;
			 ss<< "S2:		" << s[0] << endl;
		}
		else
		{
			
			ss<< "i = "<<1 << endl;
			ss << "X1:" << v0 << endl;
			double sp = 0;
			if (s[0][0] != 0)sp = s[0][0]; else sp = s[0][1];
			double Xdown = (boundary[0] - v0[0]) / sp, Xup = (boundary[1] - v0[0]) / sp;
			double a1 = minGolden(Xdown,Xup,s[0],v0,e);
			v0 = v0 + a1 * s[0]; ///////1 
			ss << "X2:" << v0 <<endl;
			//i++;
			ss<< "i = " << 2 << endl;
			if (s[1][1] != 0)sp = s[1][1]; else sp = s[1][0];
			double Ydown = (boundary[2] - v0[1]) / s[1][1], Yup = (boundary[3] - v0[1]) / s[1][1];
			double a2 = minGolden(Ydown, Yup, s[1],v0,e);
			v0 = v0 + a2 * s[1]; ///////2
			ss << "X3:" << v0 << endl;
			/*i++;
			ss << "i = " << i + 1 << endl;*/
			s[2] = a1 * s[0] + a2 * s[1];
			if (s[2][0] != 0)sp = s[2][0]; else sp = s[2][1];
			Xdown = (boundary[0] - v0[0]) / s[2][0], Xup = (boundary[1] - v0[0]) / s[2][0];
			if (s[2][1] != 0)sp = s[2][1]; else sp = s[2][0];
			Ydown = (boundary[2] - v0[1]) / s[2][1], Yup = (boundary[3] - v0[1]) / s[2][1];
			Xdown > Ydown ? Xdown = Xdown : Xdown = Ydown; Xup < Yup ? Xup = Xup : Xup = Yup;
			double a3 = minGolden(Xdown,Xup,s[2],v0,e);
			ss << "alpha : " << a3 << endl;
			v0 = v0 + a3 * s[2]; ////////3
			s[0] = s[1]; s[1] = s[2];
			ss << "S3 : " << s[1] << endl;
			ss << "X4:" << v0 << endl << endl;
			
		}
		j++;
		if (lit > limit)break;
		bool tt = inInterval(v, v0);
	} while (abs(F(v0,e)-F(v1,e)) > error);
	ss<< "x : " << v0 << endl;
	ss << "min : " << F(v0, e) << endl;
	return ss; 
}
std::stringstream Newton(std::map < std::string, std::vector<double>>v, std::string e) {
	std::stringstream ss;
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
			ss << debug << "	times\n";
			double z;
			bool brek = false;
			std::vector<double> gradTemp = gradient(v0, e);
			std::vector<std::vector<double>> HessianTemp = Hessian2(gradTemp, e);
			std::vector<std::vector<double>>HessianIv = HessianTemp;
			for (int i = 0; i < HessianTemp.size(); i++) {
				for (int j = 0; j < HessianTemp[i].size(); j++)
					if (HessianTemp[i][j] == DBL_MAX) { brek = true; break; }
				if (brek) break;
			}if (brek) break;
			ss << "Hessian: ";
			for (int i = 0; i < HessianTemp.size(); i++)
				ss << HessianTemp[i] << endl;
			HessianIv = Inverse(HessianTemp);
			ss << "Hessian inverse: ";
			for (int i = 0; i < HessianIv.size(); i++)
				ss << HessianIv[i] << endl;
			v1 = mult(HessianIv, gradTemp);
			v1 = -1 * v1;
			if (v1 != v1) {
				ss.str("");
				ss.clear();
				ss << "error" << endl;
				return ss;
			}
			while ((z = F(v0 + v1, e)) != z)
			{
				for (int i = 0; i < v0.size(); i++)
					v1[i] *= 0.9;
			}
			v1 = v0 + v1;
			/////////fucking fix
			while (F(v1,e) > F(v0,e))
			{
				if (HessianTemp.size() == 1)HessianTemp[0][0] += 1;
				else
				{
					HessianTemp[0][0] += 1; HessianTemp[1][1] += 1;
				}
				HessianIv = Inverse(HessianTemp);
				v1 = mult(HessianIv, gradTemp);
				v1 = -1 * v1;
				if (v1 != v1) {
					ss.str("");
					ss.clear();
					ss << "error" << endl;
					return ss;
				}
				while ((z = F(v0 + v1, e)) != z)
				{
					for (int i = 0; i < v0.size(); i++)
						v1[i] *= 0.9;
				}
				v1 = v0 + v1;
			}
			/////////
			ss << "x: \n";
			ss << v1 << endl;
			debug++;
			lit++;
			if (lit > limit)break;

		} while ((abs(F(v0, e) - F(v1, e)) > error));
		ss<< "min : " << F(v1, e) << endl;
	return ss; 
}
std::stringstream Steep_Descent(std::map < std::string, std::vector<double>>v, std::string e) {
	double L = 0, z;
	vector<double> h;
	int i = 0;
	vector<double> v0, v1, vin;
	bool intervalFlag = true;
	std::stringstream ss;

	if (v["y"].size() == 0)
		v1.push_back(v["x"][0]);
	else {
		v1.push_back(v["x"][0]);
		v1.push_back(v["y"][0]);
	}

	do {
		v0 = v1;
		h = -gradient(v0, e);
		if (vlen(h) < error) break;


		L = lambda(v0, e, 0);
		while ((z = F(v0 + L * h, e)) != z)  L *= 0.9; 

		int identity = 0;
		do {
			L = lambda(v0, e, identity);
			++identity;
		} while (F(v0 + L * h, e) > F(v0, e));

		v1 = v0 + L * h;
		
		intervalFlag = true;
		ss << "i:	" << i << endl;
		ss << "h:	" << h << endl;
		ss << "lamda:	" << L << endl;
		ss << "v:	" << v1 << endl;
		ss << "F(v):	"<< z << endl;
		

		if (!inInterval(v, v1))
		{
			ss << "Out of Interval ~ !" << endl;
			ss << "v:	" << v1 << endl;
			ss << "F(v):	" << F(v1, e) << endl;
		}
		ss << "-------------" << endl;

		i++;
	} while (abs(F(v0, e) - z ) > error && i < limit);

	ss << "min v:	" << v1 << endl;
	ss << "min value:	" << F(v1, e) << endl;
	//re = ss.str();

	//
	//
	return ss; 
}
std::stringstream Quasi_Newton(std::map < std::string, std::vector<double>>v, std::string e) {
	std::stringstream ss;
	std::vector<double>v0, v1;
	for (auto i = v.begin(); i != v.end(); i++) {
		v1.push_back(i->second[0]);
	}
	double z = 0;
	ss << "initial Hessian and inverse is I    ";
	int lit = 0;

	if (v1.size() == 1)
	{
		std::vector<double>I(1, 1);
		std::vector<double>d(1, 0);
		do {
			v0 = v1;
			std::vector<double>g = gradient(v0, e);
			if (g[0] == 0)break;

			d[0] = -(g[0]*I[0]);
			std::vector<double> a(1, 0);
			std::vector<std::vector<double>>Htemp = Hessian(v0, e);
			double A = -((g[0] )/(Htemp[0][0] *d[0]));
			//
			double delX = A * d[0];
			v1[0] = v0[0] + delX;
			//fix
				while ((z = gradient(v1, e)[0] )!= z)
				{
					v1[0] -= delX;
					delX *= 0.9;
					v1[0] += delX;
				}
				
			////fucking fix
				while (F(v1,e) > F(v0,e))
				{
					Htemp[0][0] += 1;
					double A = -((g[0]) / (Htemp[0][0] * d[0]));
					//
					double delX = A * d[0];
					v1[0] = v0[0] + delX;
				}
			////
			ss << "x : " << v1 << endl;
			//
			double delG = gradient(v1, e)[0] - g[0];
			I[0] = I[0] + (delX * delX)/(delX*delG) - (I[0] * g[0] * I[0] * g[0])/(g[0] * I[0] * g[0]) ;
			ss << "Hessian : " << I << endl;
			ss << endl;

			++lit;
		} while (abs(F(v0,e) - F (v1,e)) > error && lit < limit);

		ss << "min : " << F(v1, e) << endl;
		//cout << v1 << endl;
	}
	else
	{
		std::vector<std::vector<double>>I(2, vector<double>(2, 0));
		I[0][0] = 1; I[1][1] = 1;
		double z = 0;
		do {
			v0 = v1;
			std::vector<double>g = gradient(v0, e);
			if ((g[0] == 0) || (g[1] == 0))break;
			std::vector<std::vector<double>>Htemp = Hessian(v0, e);
			std::vector<double> d = mult(I, g); d[0] *= -1; d[1] *= -1;
			std::vector<double> Temp = mult(Htemp, d);
			double A = -((d[0] * g[0] + d[1] * g[1])/(Temp[0] * d[0] + Temp[1] * d[1]));
			v1 = v0 + (A * d);
			//fix
			while ((z = gradient(v1, e)[0]) != z || (z = gradient(v1, e)[0]) != z)
			{
				v1 = v1 - (A * d);
				A *= 0.9;
				v1 = v1 + (A * d);

			}
			//////fucking fix
			while (F(v1,e) > F(v0,e))
			{
				Htemp[0][0] += 1; Htemp[1][1] += 1;
				Temp = mult(Htemp, d);
				double A = -((d[0] * g[0] + d[1] * g[1]) / (Temp[0] * d[0] + Temp[1] * d[1]));
				v1 = v0 + (A * d);
			}
			//////
			ss << "x : " << v1 << endl;
			std::vector<double>delX = A * d;
			std::vector<double>delG = gradient(v1, e) - gradient(v0, e);
			std::vector<double>temp1(2, 0); temp1[0] = I[0][0] * g[0] + I[0][1] * g[1]; temp1[1] = I[1][0] * g[0] + I[1][1] * g[1];
			std::vector<vector<double>>degug = matmult((1 / (delX[0] * delG[0] + delX[1] * delG[1])), (Vecmult(delX, delX)));
			vector<vector<double>>debug2  = matmult((-1 / (temp1[0] * g[0] + temp1[1] * g[1])), (Vecmult(temp1, temp1)));
			double tttt = (-1 / (temp1[0] * g[0] + temp1[1] * g[1]));
			vector<vector<double>>tempppppppp = Vecmult(temp1, temp1);
			vector<vector<double>> ffs = matmult(tttt, tempppppppp);
			I = I + matmult((1 / (delX[0] * delG[0] + delX[1] * delG[1])), (Vecmult(delX, delX)))+ matmult((-1 / (temp1[0] * g[0] + temp1[1] * g[1])), (Vecmult(temp1, temp1)));
			//ss << "d:" << d << endl;
			ss << "Hessian : " <<endl;
			for (int i = 0; i < I.size(); i++)
			{
				ss << I[i] << endl;
			}
			ss << endl;
			++lit;
		} while ( abs(F(v0, e) - F(v1, e) > error) && lit < limit);
		ss << "min : " << F(v1, e) << endl;
		cout << v1 << endl;
		cout << F(v1, e);
	}
	return ss; 
}
std::stringstream Conjugate_Gradient(std::map < std::string, std::vector<double>>v, std::string e) {

	std::stringstream ss;
	double a = 0;
	double beta;
	double z;
	vector<double> S0, S1;
	vector<double> v0, v1, v2, vin;

	bool intervalFlag = true;

	int i = 0;
	if (v["y"].size() == 0) 
		v1.push_back(v["x"][0]);
	else {
		v1.push_back(v["x"][0]);
		v1.push_back(v["y"][0]);
	}
	do {
		S0 = S1;
		if(!i) 
			S1 = -gradient(v1, e);
		else { 
			beta = (gradient(v1, e) *  gradient(v1, e)) / (gradient(v0, e) *  gradient(v0, e));
			S1 = -gradient(v1, e) + beta * S0;
		}
		if (vlen(S1) < error) break;

		v0 = v1;
		a = alpha(v1, S1, e, 0);
		
		while ((z = F(v1 + a * S1,e)) != z) 
			a *= 0.9;

		int identity = 0;

		do {
			a = alpha(v1, S1, e, identity);
			++identity;
		} while (F(v0 + a * S1, e) > F(v0, e));


		v1 = v1 + a * S1;
		if (vlen(v1 - v0) < error) break;

		

		//print
		ss<< "i:	" << i << endl;
		if(i) ss<< "beta:	" << beta << endl;
		ss<<"Si:	" << S1 << endl;
		ss<< "alpha:	" << a << endl;
		ss<< "v:	" << v1 << endl;
		ss<< "F(v):	" << z << endl;
		

		if (!inInterval(v, v1))
		{
			ss<< "Out of Interval ~ !" << endl;
			ss<< "v:	" << v1 << endl;
			ss<< "F(v):	" << F(v1,e) << endl;
		}

		ss<< "-------------" << endl;
		i++;

		//intervalFlag = true;

	} while (abs(F(v0, e) - z) > error && i < limit);

	ss<< "min v:	" << v1 << endl;
	ss<< "min value:	" << F(v1, e) << endl;

	//
	//
	return ss; 
}
bool inInterval(std::map < std::string, std::vector<double>>&v, vector<double>& var) {
	double xmin, xmax, ymin, ymax;
	if (var.size() == 1) {
		xmin = v["x"][1], xmax = v["x"][2];
		if (var[0] > xmax) {
			var[0] = xmax;
			return false;
		}
		if (var[0] < xmin) {
			var[0] = xmin;
			return false;
		}
	}
	else {
		bool flag = true;
		xmin = v["x"][1], xmax = v["x"][2], ymin = v["y"][1], ymax = v["y"][2];
		if (var[0] > xmax) {
			flag = false;
			var[0] = xmax;
		}
			
		if (var[0] < xmin) {
			flag = false;
			var[0] = xmin;
		}
			
		if (var[1] > ymax) {
			flag = false;
			var[1] = ymax;
		}
			
		if (var[1] < ymin) {
			flag = false;
			var[1] = ymin;
		}
	}
	return true;
}