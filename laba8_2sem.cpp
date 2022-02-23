#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double Fun(double x)
{
	return 0.1 * x * x * x + x * x - 10 * sin(x);
}

double PNL(double x, pair<double, double>* fTable, int m)
{
	double y = 0;
	if (x > fTable[0].first && x < fTable[m-1].first)
	{
		int i = 2;
		while (x > fTable[i].first) i++;
		y = fTable[i - 1].second + (x - fTable[i - 1].first) * (fTable[i].second - fTable[i - 1].second) / (fTable[i].first - fTable[i - 1].first);
	}
	else { return NULL; }
	return y;
}

void main()
{
	setlocale(LC_ALL, "rus");
	int n, m;
	double a, b;
	cout << "Использовать значения по умаолчанию? 1 - Да \t 2- Нет" << endl;
	short x;
	cin >> x;
	if (x == 1) {
		a = -4; b = 2; m = 11; n = 2;
	}
	else {
		cout << "a=";
		cin >> a;
		cout << "b=";
		cin >> b;
		cout << "n=";
		cin >> n;
		cout << "m=";
		cin >> m;
	}

	double h1 = (b - a) / (m - 1);
	double h2 = (b - a) / (n - 1);
	

	pair<double, double>* FunTab = new pair<double, double>[20];

	int i = 0;
	for (i = 1; i <= m; i++) {
		double x = a + (i - 1) * (b - a) / (m - 1);
		double y = Fun(x);
		
		cout << "x = " << x << "      F(x) = " << y << "\n";
	}

	cout << "\n\n";


	for (int j = 0; j < 20; j++) {
		double x = a + (j - 1) * (b - a) / 20;
		double y = Fun(x);
		FunTab[j] = { x, y };
	}

	for (int j = 0; j <=20; j++) {
		double t = PNL(FunTab[j].first, FunTab, m);
		double delta = fabs(FunTab[j].second - PNL(FunTab[j].first, FunTab, m));
		if (PNL(FunTab[j].first, FunTab, m) != 0) {
			cout << "x = " << FunTab[j].first << "   Y = " << FunTab[j].second << "     FunApr(x) = " << t << "      Delta = " << delta << endl;
		}
	}




}