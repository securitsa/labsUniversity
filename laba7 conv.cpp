#include<iostream>
#include<string>

using namespace std;

int pog=1;

void FillArray(char*& strarr)
{
	cout << "Введите строку:" << endl;
	cin.getline(strarr, 128); //ввод
	cout << endl;
}


/*void ShowArray(char*& strline, int& lenght)
{
	cout << strline << "\n" << "Lenght of string = " << lenght << endl;
}*/

void SearchArray(char*& strline, int& lenght, int& min_len, int& number, int& len, int& numword)
{
	min_len = lenght;
	number = 1;
	for (int i = 0; i < lenght; i++) {
		++len;
		if (strline[i + 1] == ' ') {
			++numword;
			if (len < min_len) {
				min_len = len - 1;
				number = numword;
			}
			len = 0;
		}
	}

	
}
int main() {setlocale(LC_ALL, "ru");
	
while (pog == 1) {

	int min_len = 0, number = 0, len = 0, numword = 0;
	int lenght;

	char* strarr = new char[128];//инициализация памяьт для массива ввода

	FillArray(strarr);

	lenght = strlen(strarr); //длина введенной строки

	char* strline = new char[lenght + 1];//инициализация памяти м-а длинной lenght

	for (int i = 0; i < lenght; i++)
	{
		strline[i] = strarr[i]; //заполение второго массива элементами с первого
	}

	strline[lenght] = '\0'; //добавление терминирующего нуля

	//ShowArray(strline, lenght);

	delete[] strarr; //удаление исходного массива

	SearchArray(strline, lenght, min_len, number, len, numword);

	cout << "Number of min word = " << number << endl;
	cout << "Lenght of min word = " << min_len << endl;

	delete[] strline;

	cout << "Restart 1-Yes, 0-No" << endl;
	cin >> pog;
	if (pog == 0) { break; }
}

}