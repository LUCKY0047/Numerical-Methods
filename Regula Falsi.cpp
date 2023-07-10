//#include<iostream>
//#include<cmath>//Regula Falsi Method
//using namespace std;
//double calculate_fx(int* coeff, double a, int deg)//to find value in actual function
//{
//	double po, temp = deg, final = 0;
//	for (int i = 0; i < deg + 1; i++)
//	{
//		po = pow(a, temp);
//		po = coeff[i] * po;
//		final += po;
//		temp--;
//	}
//	return final;
//}
//
//void display(int* coeff_arr, int deg)//displaying equation
//{
//	cout << endl << "             <--------------------------------------Equation--------------------------------->" << endl << endl;
//	cout << "                                          ";
//	int temp = deg;
//	for (int i = 0; i < deg + 1; i++)
//	{
//		cout << "(" << coeff_arr[i] << ")" << "x^" << temp;
//		if (i < deg)
//		{
//			cout << "+";
//		}
//		temp--;
//	}
//}
//int main()
//{
//	int* coeff_arr;
//	int deg;
//	double a, b, fun1, fun2, iter;
//	cout << "Enter Highest Degree of x:";
//	cin >> deg;
//	int temp = deg;
//	coeff_arr = new int[deg + 1];
//	for (int i = 0; i < deg + 1; i++)
//	{
//		cout << "Enter Coefficient of x^" << temp << ":";
//		cin >> coeff_arr[i];
//		temp--;
//	}
//	system("cls");
//	display(coeff_arr, deg);
//	cout << endl;
//	do {
//		cout << "Enter Interval value a:";
//		cin >> a;
//		cout << "Enter Interval value b:";
//		cin >> b;
//		fun1 = calculate_fx(coeff_arr, a, deg);
//		fun2 = calculate_fx(coeff_arr, b, deg);
//		cout << "Interval value: [" << a << "," << b << "]" << endl;
//		cout << "f(a):" << fun1 << endl;
//		cout << "f(b):" << fun2 << endl;
//	} while (fun1 < 0 && fun2 < 0 || fun1>0 && fun2>0);
//	double x, temp1, temp2,temp3;
//	for (int i = 0; i < 15; i++)
//	{
//		temp1 = calculate_fx(coeff_arr, b, deg);
//		temp2 = calculate_fx(coeff_arr, a, deg);
//		x = (a * temp1) - (b * temp2);
//		temp1 = temp1 - temp2;
//		x = x / temp1;
//		temp3= calculate_fx(coeff_arr, x, deg);
//		cout << "x[" << i + 2 << "]=" << x << endl;
//		if ( temp3* temp2 < 0)
//		{
//			if (x < a)
//			{
//				b = a;
//				a = x;
//				cout << "-----------------------------------------------------------------------------------" << endl;
//				cout << "Interval value: [" << a << "," << b << "]" << endl;
//			}
//			else
//			{
//				b = x;
//				cout << "-----------------------------------------------------------------------------------" << endl;
//				cout << "Interval value: [" << a << "," << b << "]" << endl;
//			}
//		}
//		else
//		{
//			if (x < b)
//			{
//				a = x;
//				cout << "-----------------------------------------------------------------------------------" << endl;
//				cout << "Interval value: [" << a << "," << b << "]" << endl;
//			}
//			else
//			{
//				b = x;
//				cout << "-----------------------------------------------------------------------------------" << endl;
//				cout << "Interval value: [" << a << "," << b << "]" << endl;
//			}
//		}
//	}
//
//}