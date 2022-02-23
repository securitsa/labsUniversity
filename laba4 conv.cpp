#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

typedef double (*TFunY)(double);
typedef double (*TFunS)(double, int, int);
typedef double (*TFunSum)(double, double);

int a, b, h;
int n, k, P;

double cci(const char* text) {           //проверка корректного ввода
	double d;
	cout << text;
	while (!(cin >> d) || cin.get() != '\n') {
		cin.clear();
		cout << "return" << endl;
		while (cin.get() != '\n');
	}
	return d;
}


void Out(int a, int b, int h, int k, int n, TFunY Y, TFunS S, TFunSum Sum)
{
	for (int i = a; i <= b; i += h)
	{
		cout << "x = " << (double)i / 10 << "   Y = " << Y((double)i / 10) << "   S = " << S((double)i / 10, k, n) << "   Sum = " << Sum(Y((double)i / 10), S((double)i / 10, k, n)) << endl;
	}
}

double Sum(double Y, double S)
{
	return abs(Y - S);
}

double Sx(double x, int k, int n)
{
	for (int i = k; i <= n; i++)
		return pow(-1, i + 1) * (pow(x, 2 * i + 1) / (4 * i * i - 1));
}

double Yx(double x)
{
	return (((1 + x * x) / 2) * atan(x)) - (x / 2);
}
void main()
{
	a = cci("Input a:\n");
	b = cci("Input b:\n");
	h = cci("Input h:\n");
	n = cci("Input n:\n");
	cout << "Output:\n";
	cout << (double)a / 10 << ' ' << (double)b / 10 << ' ' << (double)h / 10 << ' ' << n << endl;
	Out(a, b, h, k, n, Yx, Sx, Sum);
}