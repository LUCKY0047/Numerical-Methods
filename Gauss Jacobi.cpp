//#include<iostream>//Gauss Jacobi Method
//using namespace std;
//void initializer(double A[][3], double B[], int rows, int columns)
//{
//	cout << "Enter Values of A:" << endl;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			cout << "Enter a[" << i << "][" << j << "]=";
//			cin >> A[i][j];
//		}
//	}
//	cout << endl << "Enter values of B:" << endl;
//	for (int i = 0; i < rows; i++)
//	{
//		cout << "Enter b[" << i << "]=";
//		cin >> B[i];
//	}
// cout << endl;
//}
//
//bool isDiagonalDominated(double mat[][3], int n) {
//	for (int i = 0; i < n; i++) {
//		int sum = 0;
//		for (int j = 0; j < n; j++) {
//			if (i != j) {
//				sum += abs(mat[i][j]);
//			}
//		}
//		if (abs(mat[i][i]) <= sum) {
//			return false;
//		}
//	}
//	return true;
//}
//
//void rearrangeMatrix(double mat[][3], double B[], int n) {
//	for (int i = 0; i < n; i++) {
//		int maxIdx = i;
//		for (int j = i + 1; j < n; j++) {
//			if (abs(mat[j][i]) > abs(mat[maxIdx][i])) {
//				maxIdx = j;
//			}
//		}
//		if (maxIdx != i) {
//			for (int j = 0; j < n; j++) {
//				swap(mat[i][j], mat[maxIdx][j]);
//				swap(B[i], B[maxIdx]);
//			}
//		}
//	}
//}
//
//void display(double A[][3], double B[], int rows, int columns)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		cout << "|";
//		for (int j = 0; j < columns; j++)
//		{
//
//			cout << A[i][j] << " ";
//		}
//		cout << "|    |x" << i + 1 << "|    |" << B[i] << "|";
//		cout << endl;
//	}
//	cout << "------------------------------------------------------------------------------- " << endl;
//}
//
//void gauss_Jacobi(double A[][3], double B[])
//{
//	double X[3] = { 0 }, initial[3] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		X[0] = (B[0] - (A[0][1] * initial[1]) - (A[0][2] * initial[2])) / A[0][0];
//		X[1] = (B[1] - (A[1][0] * initial[0]) - (A[1][2] * initial[2])) / A[1][1];
//		X[2] = (B[2] - (A[2][0] * initial[0]) - (A[2][1] * initial[1])) / A[2][2];
//		cout << "X" << i + 1 << "=" << X[0] << endl << "Y" << i + 1 << "=" << X[1] << endl << "Z" << i + 1 << "=" << X[2] << endl;
//		cout << endl;
//		for (int i = 0; i < 3; i++)
//		{
//			initial[i] = X[i];
//		}
//	}
//}
//int main()
//{
//	int rows = 3, columns = 3;
//	double A[3][3], B[3];
//	initializer(A, B, rows, columns);
//	display(A, B, rows, columns);
//	if (isDiagonalDominated(A, rows)) {
//		cout << "The matrix is already diagonal dominated.\n";
//		gauss_Jacobi(A, B);
//	}
//	else {
//		rearrangeMatrix(A, B, rows);
//		if (isDiagonalDominated(A, rows)) {
//			cout << "The matrix has been rearranged to make it diagonal dominated:\n";
//			display(A, B, rows, columns);
//			gauss_Jacobi(A, B);
//		}
//		else {
//			cout << "The matrix cannot be rearranged to make it diagonal dominated.\n";
//		}
//	}
//	return 0;
//}