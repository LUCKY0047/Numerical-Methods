#include<iostream>//Gregory_Newton Forward Interpolation
using namespace std;
void initializer(double* &x, double*& y, int data)
{
	x = new double[data];
	y = new double[data];
	for (int i = 0; i < data; i++)
	{
		cout << "Enter Values of X:";
		cin >> x[i];
	}
	cout << endl;
	for (int i = 0; i < data; i++)
	{
		cout << "Enter Values of Y:";
		cin >> y[i];
	}
	cout << endl;
	cout << "X: ";
	for (int i = 0; i < data; i++)
	{
		cout << x[i] << "  ";
	}
	cout << endl;
	cout << "Y: ";
	for (int i = 0; i < data; i++)
	{
		cout << y[i] << "  ";
	}
	cout << endl;
}
void dif_display(double* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	cout << endl;
}
void forward_table(double*& first, double*& sec, double& thi,int data,double*y)
{
	first = new double[data - 1];
	sec = new double[data - 2];
	for (int i = 0; i < data-1; i++)
	{
		first[i] = y[i+1] - y[i];
  }
	for (int i = 0; i < data - 2; i++)
	{
		sec[i] = first[i + 1] -first[i];
	}
	thi = sec[1] - sec[0];
	cout << "1st Difference: ";
	dif_display(first, data - 1);
	cout << "2nd Difference: ";
	dif_display(sec, data - 2);
	cout << "3rd Difference: ";
	cout << thi << endl;
	cout << endl;
}
int factorial(int n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}
int main()
{
	int data_size,put =0;
	double temp = 0;
	double	*x=NULL,*y=NULL,* first, * sec, thi;
	cout << "Enter Size of Data Values:";
	cin >> data_size;
	initializer(x,y, data_size);
	int h = x[1] - x[0];
	forward_table(first, sec, thi,data_size,y);
	cout << y[0] << " + (" << first[0] << "x) + (" << first[0] * -x[0] << ") / " << h << " + (" << sec[0] << "x^2) + (" << sec[0] * (-x[1] - x[0])
		<< "x) + (" <<sec[0]* (x[1] * x[0]) << ") / " << factorial(2) * pow(h, 2) << " + (" << thi << "x^3) + (" << thi * (-x[0] - x[1] - x[2])
		<< ") x^2 + (" << thi * ((x[0] * x[1]) + (x[2] * x[1]) + (x[2] * x[0])) << ") x + (" << thi * -(x[0] * x[1] * x[2]) << ") /" << factorial(3) * pow(h, 3);
	cout << endl;
	cout << "Enter Value of X you want to find:";
	cin >> put;
	temp = y[0] + (((first[0] * put + first[0] * -x[0])) / h);
	temp += ((sec[0] * pow(put, 2)) + (sec[0] * ((-x[1] - x[0])* put)) + (sec[0]*(x[1] * x[0]))) / (factorial(2) * pow(h, 2));
	temp+= ((thi*pow(put,3)) + (thi * ((-x[0] - x[1] - x[2])* pow(put,2)))+( thi * (((x[0] * x[1]) + (x[2] * x[1]) + (x[2] * x[0]))*put)) + ((thi * -(x[0] * x[1] * x[2]))))/  (factorial(3) * pow(h, 3));
	cout <<"Value at "<<put<<" = " << temp << endl;
	cout << endl;
	   return 0;
}