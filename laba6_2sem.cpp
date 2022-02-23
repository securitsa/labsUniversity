#include <windows.h>
#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

double a = 0, b = 0, eps = 0;
int n = 20;
void UIMenu();

double f(double x) {

    return 0.1 * x*x*x + x*x -10*sin(x);

}


double Simphson(double a, double b, int n) {

    double h = (b - a) / n;
    double sum = f(a) + f(b);
    int k;

    for (int i = 1; i <= n-1; i++)
    {
        k = 2 + 2 * (i % 2);
        sum += k * f(a + i * h);
    }

    sum *= h / 3;

    return sum;
}


double Epsi (double a, double b, int h, double eps) {

    int i = 0;
    double diff;

    do {
        i++;
        diff = f(Simphson(a, b, h * i) - Simphson(a, b, h * (i + 1)));
    } while (diff > eps);

    return Simphson(a, b, h * (i + 1));

}


void Addiction() {

    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);
    system("cls");
    int x = 0;
    for (float i = 0; i < 3.14 * 10; i += 0.05)
  
    {
        SetPixel(hdc, x, 150 + 0.1 * f(i), RGB(255, 0, 0));
        x += 1;
    }
    LineTo(hdc, 0, 100);
    ReleaseDC(hwnd, hdc);
    cout << "Для продолжения нажмите любую клавишу." << endl;
    _getch();
    system("cls");
    UIMenu();
}


void CorrectStep() {
    cout << "\nВведите шаг интегрирования.\nStep = ";
    cin >> n;
    cout << endl;
    UIMenu();
}


void Epsilon() {

    cout << "\nВведите допустимую погрешность:\n";
    double Eps;
    cin >> Eps;
    cout << "\nAnswer = " << Epsi(a, b, n, eps) << endl;
    UIMenu();

}


void EnterData() {

    cout << "Использовать рекумендуемые пределы интегрирования?\n 1 - Да \t2 - Нет\n";
    short a2;
    cin >> a2;
    switch (a2) {
    case 1: 
        cout << "\nВведены рекомендуемые пределы интегрирования.\n";
        a = -2; b = 4;
        break;

    case 2:
        cout << "Введите пределы интегрирования.\nFrom A = ";
        cin >> a;
        cout << "\t To B = ";
        cin >> b;
        cout << "\nДанные введены!\n";
        break;
    }
    UIMenu();
}

void PayMent() {
    cout << "Answer = " << Simphson(a, b, n) << endl;
    UIMenu();
}


void UIMenu() {

    cout << "\nПараметры интегрирования:\nFrom\t" << a << "\tTo\t" << b << "\n" << "Step = " << n << "\n\n\n";
    cout << "\n1)Изменить пределы интегрирования \n2)Изменить шаг \n3)Произвести расчет \n4)Построение графика \n5)Расчет по погрешности \n6)Завершение работы\n";
    short a1;
    cin >> a1;

    switch (a1) {

    case 1: EnterData(); break;

    case 2: CorrectStep(); break;

    case 3: PayMent(); break;

    case 4: Addiction();  break;

    case 5: Epsilon(); break;

    case 6: system("pause"); 

    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    UIMenu();
}
