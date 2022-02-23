 #include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int pog;
double cci(const char* text) {   //проверка кор ввода
    double d;
    cout << text;
    while (!(cin >> d) || cin.get() != '\n') {
        cin.clear();
        cout << "return" << endl;
        while (cin.get() != '\n');
    }
    return d;
}

void FillArray(int*& arr, int& size) //ввод массива
{
    srand(time(NULL));   //генерация рандомных по времени
    for (int i = 0; i < size; i++)
    {       
            arr[i] = rand() % 10;
    }
}

void ShowArray(int*& arr, int& size)   //вывод массива
{
    for (int i = 0; i < size; i++)
    {     
        cout << arr[i] << "\t";
    }  
    cout << endl;
}

void SearchArray(int*& arr, int& size, int& CurrMax, int& PosMax, int& sum) //поиск наиб и суммы
{
    for (int i = 0; i < size; i++)
    {

        if (arr[i] >= CurrMax) { CurrMax = arr[i];   PosMax = i; } //поиск наиб знач

    }

    if (arr[1] == CurrMax) { PosMax = 1; } //если наиб это первый эл-т массива
    cout << "Max array member = " << CurrMax << endl;
    cout << "Nomer max array member = " << PosMax + 1 << endl;

    for (int i = 0; i <= PosMax; ++i)
    {

        if (arr[i] >= 0) { sum += arr[i]; } //поиск суммы
    }
    cout << "SUMM including maximum element = " << sum << "\n" << "SUMM not including the maximum element = " << sum-CurrMax<<endl;
}
int main() {
    while (pog = 1) {

        {
            int size, CurrMax = 0, PosMax = 0, sum = 0;

            size = cci("Input array size  \n"); //ввод размера
            int* arr = new int[size]; // инициализация памяти
           
            FillArray(arr, size); //ф-я ввода
            ShowArray(arr, size);//вывода
            SearchArray(arr, size, CurrMax, PosMax, sum);//поиска
            delete[] arr;            //очистка памяти массива
            size = 0;
            sum = 0;
            CurrMax = 0;
            PosMax = 0;

            cout << "Restart 1-Yes, 0-No" << endl; //повтор программы
            cin >> pog;
            if (pog == 0) { break; }


        }
    }
}

