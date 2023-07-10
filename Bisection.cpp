#include<iostream>
#include<cmath>//Bissection Method
using namespace std;
double intervalChecker(int *coeff,double a,int deg)
{
	double po,temp=deg,final=0;
	for (int i = 0; i < deg+1; i++)
	{
		po = pow(a, temp);
		po = coeff[i] * po;
		final += po;
		temp--;
	}
	return final;
}
void display(int* coeff_arr, int deg)
{
	int temp;
	cout << endl << "             <--------------------------------------Equation--------------------------------->"<<endl;
	temp = deg;
	cout << "                                          ";
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
	int * coeff_arr,accu;
	int deg;
	double a,b,fun1,fun2,avg, temp1,iter;
	cout << "Enter Highest Degree of x:";
	cin >> deg;
	int temp = deg;
	coeff_arr = new int[deg + 1];
	for (int i = 0; i < deg+1; i++)
	{
		cout << "Enter Coefficient of x^"<<temp<<":";
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
		fun1=intervalChecker(coeff_arr, a, deg);
		fun2= intervalChecker(coeff_arr, b, deg);
		cout << "Interval value: [" << a << "," << b << "]" << endl;
		cout << "f(a):" << fun1 << endl;
		cout << "f(b):" << fun2 << endl;
	} while (fun1 < 0 && fun2 < 0 || fun1>0 && fun2>0);
	cout << "Enter Accuracy value in terms of 10^:";
	cin >> accu;
	iter = b - a;
	iter = (accu - log10(iter)) / log10(2);
	iter = iter + 1;
	iter = iter * -1;

	for (int i = 1; i <iter; i++)
	{
		avg = (a + b) / 2;
		temp1 = intervalChecker(coeff_arr, avg, deg);
		if (temp1*fun1<0)
		{
			if (avg < a)
			{
				b = a;
				a = avg;
				cout << "-----------------------------------------------------------------------------------" << endl;
				cout << "Interval value: [" << a << "," << b << "]"<<endl;
			}
			else
			{
				b = avg;
				cout << "-----------------------------------------------------------------------------------" << endl;
				cout << "Interval value: [" << a << "," << b << "]" << endl;
			}
		}
		else
		{
			if (avg < b)
			{
				a = avg;
				cout << "-----------------------------------------------------------------------------------" << endl;
				cout << "Interval value: [" << a << "," << b << "]" << endl;
			}
			else
			{
				b = avg;
				cout << "-----------------------------------------------------------------------------------" << endl;
				cout << "Interval value: [" << a << "," << b << "]" << endl;
			}
		}
		cout << "Function value =" << temp1 << endl;
	}
	return 0;
}