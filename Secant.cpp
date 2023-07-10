//#include<iostream>
//#include<cmath>//Secant Method
//using namespace std;
//struct function
//{
//	double fun1, fun2;
//};
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
//
//function intervalChecker(double a, double b, int* coeff_arr, int deg)
//{
//	function f;
//	double fun1, fun2;
//	do {
//		a = a + 0.1;
//		b = b - 0.1;
//		fun1 = calculate_fx(coeff_arr, a, deg);
//		fun2 = calculate_fx(coeff_arr, b, deg);
//	} while (fun1 < 0 && fun2 < 0 || fun1>0 && fun2>0);
//	f.fun1 = a;
//	f.fun2 = b;
//	return f;
//}
//
//int main()
//{
//	int* coeff_arr;
//	int deg;
//	double a, b, fun1, fun2,iter;
//	double x, temp1, temp2;
//	function f;
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
//	f = intervalChecker(a, b, coeff_arr, deg);//picking x0 and x1
//	for (int i = 0; i < 15; i++)
//	{
//		temp1 = calculate_fx(coeff_arr, f.fun2, deg);
//		temp2 = calculate_fx(coeff_arr, f.fun1, deg);
//		x = (f.fun1 * temp1) - (f.fun2 * temp2);
//		temp1 = temp1 - temp2;
//		x = x / temp1;
//		cout << "x[" << i+2 << "]=" << x << endl;
//		f.fun1 = f.fun2;
//		f.fun2 = x;
//	}
//}