// Лаборатораная работа №1 ОАИП 2 семестр
//  Хитриков Егор 022403
//  15.02.2021


#include <iostream>  //подключение библиотек 
#include <math.h>

using namespace std;

int Recurse(int, int);   //объявление функций
int NoRecurse(int, int);

int cci(const char* text) {    //control correct input проверка корректного ввода
	int d;
	cout << text;
	while (!(cin >> d) || cin.get() != '\n') {
		cin.clear();
		cout << "return" << endl;
		while (cin.get() != '\n');
	}
	return d;
}


int NoRecurse(int n, int m) {     //нерекурсивная ф-ия
	int b;
	if (n > m) { b = n; n = m; m = b; b = 0; }
	
	while (m % n != 0) {
		if (n > m) { b = n; n = m; m = b; b = 0; }
		if (m > n) { m = m % n; }
		else { n = n % m; }
	}
	if (m % n == 0 || n % m == 0) {
	return n;
	}
}
	

int Recurse(int n, int m) {     //рекурсия
	int b;
	if (n > m) { b = n; n = m; m = b; b = 0; }
	if (m % n == 0) return n;
	else {
		m = m % n;
		return Recurse(n, m) % n;
	}
}
int main() {
	int n, m, enter;
	cout << "Enter mode:\n"<< "\n1)Recurse \n2)NoRecurse \n3)Both " << endl;
	cin >> enter;	
	m = cci("Input m: \n");
	n = cci("Input n: \n");
	switch (enter){
		case 0:
			cout << "\t Recurse = " << Recurse(n, m) << endl; 
			break;

		case 2:
			cout << "\t Recurse = " << Recurse(n, m) << "\t Simple = " << NoRecurse(n, m) << endl;
			break;

		default:
			cout << "\t Simple = " << NoRecurse(n, m) << endl;
			break;

		}
		return 0;
}

