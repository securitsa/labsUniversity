#include <iostream>
#include <ctime>

using namespace std;

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


void FillArray(int**&  arr, int& size) //ввод массива
{
	srand(time(NULL));   //генерация рандомных по времени
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}

void ShowArray(int**& arr,  int &size)   //вывод массива
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j]<< "  ";
		}
		cout << endl;
	}
	cout << "\n" << endl;
}

void PushBack(int**& arr, int& size, int& mi, int& mj)  //смещение строки и столбца на 1 позицию
{
	int i, j;
	for (int i = mi; i < size - 1; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = arr[i + 1][j];
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = mj; j < size - 1; j++)
		{
			arr[i][j] = arr[i][j + 1];
		}
	}

	
}

void popback(int**& arr, int& size) //удаление последнего столбца и строки и внесение в новый arr
{
	size--;
	int** newArray = new int* [size];
	for (int i = 0; i < size; i++) { newArray[i] = new int[size]; }
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			newArray[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < size; i++) delete[] arr[i];				//очистка памяти исх массива
	delete[] arr;
	arr = newArray;
}
void main()
{

	int pog, size, maxarr = 0, mi = 0, mj = 0;
	while (pog = 1) {
		size = cci("Input matrix size \n");
		int** arr = new int* [size];
		for (int i = 0; i < size; i++)  arr[i] = new int[size];   //инициализация авмяти под первый массив
		FillArray(arr, size);
		ShowArray(arr, size);

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)  if (arr[i][j] > maxarr)    //поиск наибольшего
			{
				maxarr = arr[i][j];
				mi = i;
				mj = j;
			}


		cout << "Max = " << maxarr << "   a[" << mi + 1 << "][" << mj + 1 << "]" << "\n" << endl;

		PushBack(arr, size, mi, mj);

		popback(arr, size);

		ShowArray(arr, size);

		for (int i = 0; i < size; i++) delete[] arr[i];				//очистка памяти изм массива
		delete[] arr;
		cout << "Delete!" << endl;

	
	size = 0;
	cout << "Restart 1-Yes, 0-No" << endl;
	cin >> pog;
	if (pog == 0) { break; }
	}
}
