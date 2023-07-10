#include<iostream>//Factorization Method
using namespace std;
void initializer(int A[][3], int B[], int rows, int columns)
{
	cout << "Enter Values of A:" << endl;
	for (int i = 0; i <rows ; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "Enter a[" << i << "][" << j << "]=";
			cin >> A[i][j];
		}
	}
	cout << endl<<"Enter values of B:"<<endl;
	for (int i = 0; i < rows; i++)
	{
		cout << "Enter b[" << i << "]=";
		cin >> B[i];
	}
}
void display(int A[][3], int B[], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		cout << "|";
		for (int j = 0; j < columns; j++)
		{
			
			cout << A[i][j]<<" ";
		}
		cout << "|    |x" << i + 1 << "|    |" << B[i] <<"|";
		cout << endl;
	}
	cout <<  "------------------------------------------------------------------------------- "<<endl;
}

void displayLU(float L[][3], float U[][3], int rows, int columns)
{
	cout << "L Matrix:"<<endl;
	for (int i = 0; i < rows; i++)
	{
		cout << "|";
		for (int j = 0; j < columns; j++)
		{
			if (i == j)
			{
				L[i][j] = 1;
			}
			cout << L[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}
	cout << "------------------------------------------------------------------------------- "<<endl;
	cout << "U Matrix:"<<endl;
	for (int i = 0; i < rows; i++)
	{
		cout << "|";
		for (int j = 0; j < columns; j++)
		{
			cout << U[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}
}
void display_arr(float X[],int  rows)
{
	cout << endl;
	for (int i = 0; i <rows; i++)
	{
		cout <<"|" << X[i] <<"|" << endl;
	}
}
int main()
{
	int rows=3, columns=3;
	int  A[3][3], B[3];
	float L[3][3] = { 0 }, U[3][3] = { 0 },Y[3], X[3];
	initializer(A,B,rows,columns);
	display(A, B, rows, columns);
	//calculating L and U
	U[0][0] = A[0][0];
	U[0][1] = A[0][1];
	U[0][2] = A[0][2];
	L[1][0] = A[1][0] / U[0][0];
	U[1][1] = A[1][1] - (L[1][0] * U[0][1]);
	U[1][2] = A[1][2] - (L[1][0] * U[0][2]);
	L[2][0] = A[2][0] / U[0][0];
	L[2][1] = (A[2][1] - (L[2][0] * U[0][1])) / U[1][1];
	U[2][2] = A[2][2] - (L[2][0] * U[0][2]) - (L[2][1] * U[1][2]);
	displayLU(L, U, rows, columns);
	//calculating Y
	Y[0] = B[0];
	Y[1] = B[1] - (L[1][0] * Y[0]);
	Y[2] = B[2] - (L[2][0] * Y[0]) - (L[2][1] * Y[1]);
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Y Matrix:";
	display_arr(Y, rows);
	//calculating x
	X[2] = Y[2] / U[2][2];
	X[1] = (Y[1] - (U[1][2] * X[2])) / U[1][1];
	X[0] = (Y[0] - (U[0][1] * X[1]) - (U[0][2] * X[2])) / U[0][0];
	cout <<"-------------------------------------------------------------------------------- " << endl;
	cout << "X Matrix:";
	display_arr(X, rows);
	return 0;
}