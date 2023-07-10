#include<iostream>
#include<cmath>//Newton_Raphson
using namespace std;

double intervalChecker_der(int* coeff, double a, int deg)//to find value in derivative
{
	double po, temp = deg, final = 0;
	for (int i = 0; i < deg; i++)
	{
		po = pow(a, temp);
		po = coeff[i] * po;
		final += po;
		temp--;
	}
	return final;
}

double intervalChecker(int* coeff, double a, int deg)//to find value in actual function
{
	double po, temp = deg, final = 0;
	for (int i = 0; i < deg + 1; i++)
	{
		po = pow(a, temp);
		po = coeff[i] * po;
		final += po;
		temp--;
	}
	return final;
}

void display(int* coeff_arr, int deg)//displaying equation
{
	cout << endl << "             <--------------------------------------Equation--------------------------------->" << endl << endl;
	cout << "                                          ";
	int temp = deg;
	for (int i = 0; i < deg + 1; i++)
	{
		cout << "(" << coeff_arr[i] << ")" << "x^" << temp;
		if (i < deg)
		{
			cout << "+";
		}
		temp--;
	}
}

int main()
{
	int* coeff_arr, accu;
	int deg;
	double a, b, fun1, fun2, avg, temp1, deri, iter;
	cout << "Enter Highest Degree of x:";
	cin >> deg;
	int temp = deg;
	coeff_arr = new int[deg + 1];
	for (int i = 0; i < deg + 1; i++)
	{
		cout << "Enter Coefficient of x^" << temp << ":";
		cin >> coeff_arr[i];
		temp--;
	}
	system("cls");
	display(coeff_arr, deg);
	cout << endl;
	do {
		cout << "Enter Interval value a:";
		cin >> a;
		cout << "Enter Interval value b:";
		cin >> b;
		fun1 = intervalChecker(coeff_arr, a, deg);
		fun2 = intervalChecker(coeff_arr, b, deg);
		cout << "Interval value: [" << a << "," << b << "]" << endl;
		cout << "f(a):" << fun1 << endl;
		cout << "f(b):" << fun2 << endl;
	} while (fun1 < 0 && fun2 < 0 || fun1>0 && fun2>0);
	double x_not = (a + b) / 2;
	temp = deg;
	int* temp_arr = new int[deg + 1];//calculating derivative
	for (int i = 0; i < deg + 1; i++)
	{
		temp_arr[i] = coeff_arr[i];
	}
	for (int i = 0; i < deg + 1; i++)
	{
		temp_arr[i] = temp_arr[i] * temp;//derivative stored in temp_arr
		temp--;
	}
	cout << "[x0]:" << x_not << endl;//value of x_not
	for (int i = 0; i < 15; i++)
	{
		deri = intervalChecker_der(temp_arr, x_not, deg - 1);
		temp1 = intervalChecker(coeff_arr, x_not, deg);
		temp1 = temp1 / deri;
		temp1 = x_not - temp1;
		x_not = temp1;
		cout << "[x" << i + 1 << "]:" << temp1 << endl;
	}
	return 0;
}