#include <iostream>
#include <fstream>
#include<Windows.h> 



using namespace std;

struct Student
{
	char surname[30], numberOfGroup[30], born[30];
	double mat, phis, chem, inf, srball;
};

Student databaseStudents[30];
short sizeArrayStudents;
ofstream fout("output.txt", ios_base::out);
ifstream fin("input.txt", ios_base::in);


bool ShowStudentById();
bool CheckStudent(short n);
bool CharacterComprasion(char a[], char b[]);

void CoutStudent(Student student); //вывод студентов
void CoutStudentFail(Student student); //вывод студентов в файл
void ChangeSurname(short x); //изменение фамилии
void ChangeNumberOfGroup(short x); //изменение номера группы
void ChangePoints(short x); //изменение оценок убрать
void ChangeBurn(short x);//изменение года рождения
void CountSrBall(short x); //подсчет среднего балла
void DeleteStudentById(short n); //процесс удалить студента по ид
void CreateStudent(); //добавление студента
void ShowStudents(); //показ студентов
void ShowAllStudents(); //показ всез студентов
void ShowAllStudentInFail(); //вывод всех студентов в файл
void Edit(); //функция изменения
void Solve(); //лабаин
void Delete(); //удаление
void Sort(); //сортировка
void QSortBySurname(short b, short e);//процесс сортировки по фамилии
void QSortBySrBall(short b, short e); //процесс сортировки по имени


void UIMenu() {
	while (true) {
		cout << "1) Создание\n2) Просмотр\n3) Изменить\n4) Удалить студента\n5) Сортировать\n6) Минимальный средний балл\n7) Сохранить в файл\n";
		short n;
		cin >> n;

		swiёtch (n) {
		case 1: CreateStudent(); break;
		case 2: ShowStudents(); break;
		case 3: Edit(); break;
		case 4: Delete(); break;
		case 5: Sort(); break;
		case 6: Solve(); break;
		case 7: ShowAllStudentInFail(); break;
		default:
			cout << "Введите число в диапазоне 1-7!\n";
		}
	}
}

void CreateStudent() {
	cout << "\n\nВведите фамилию, номер группы, оценки по физике, оценки по математике, оценки по информатике, оценки по химии, год рождения\n";

	cin >> databaseStudents[sizeArrayStudents].surname >> databaseStudents[sizeArrayStudents].numberOfGroup >>
		databaseStudents[sizeArrayStudents].phis >> databaseStudents[sizeArrayStudents].mat >> databaseStudents[sizeArrayStudents].inf >> databaseStudents[sizeArrayStudents].chem >> databaseStudents[sizeArrayStudents].born;

	CountSrBall(sizeArrayStudents);

	sizeArrayStudents++;

	cout << "Студент успешно создан!\n\n";
}

void ShowStudents() {
	bool t = true;
	while (t) {

		cout << "\n\n1) Показать всех студентов\n2) Показать студентa с номером i\n";
		short n;
		cin >> n;

		switch (n) {
		case 1:
			ShowAllStudents();
			t = false;
			break;
		case 2:
			if (ShowStudentById())
				t = false;
			break;
		default:
			cout << "Введите 1 или 2\n";
		}
	}
	cout << endl << endl;
}

bool ShowStudentById() {
	short n;
	cout << "Введите номер студента: ";
	cin >> n;

	if (!CheckStudent(n))
		return false;

	CoutStudent(databaseStudents[n - 1]);

	return true;
}

void ShowAllStudents() {
	for (int i = 0; i < sizeArrayStudents; i++)
		CoutStudent(databaseStudents[i]);
}

void ShowAllStudentInFail() {
	for (int i = 0; i < sizeArrayStudents; i++)
		CoutStudentFail(databaseStudents[i]);
}

void CoutStudentFail(Student student) {
	fout << endl << endl << "Фамилия: " << student.surname << endl << "Группа: " << student.numberOfGroup << endl << "Математика: " << student.mat << endl << "Физика: " << student.phis << endl << "Информатика: " << student.inf << endl << "Химия: " << student.chem << endl << "Год рождения: " << student.born << endl << endl;
}

void Edit() {
	short n;
	cout << "Введите номер студента: ";
	cin >> n;

	if (!CheckStudent(n)) {
		return;
	}

	bool t = true;
	while (true) {
		cout << "Выберите поле, которое хотите изменить:\n1) Фамилию\n2) Номер группы\n3) Оценки\n4) Год рождения" << endl;
		cin >> n;

		switch (n) {
		case 1: ChangeSurname(n - 1); t = false; break;
		case 2: ChangeNumberOfGroup(n - 1); t = false; break;
		case 3: ChangePoints(n - 1); t = false; break;
		case 4: ChangeBurn(n - 1); t = false; break;
		default:
			cout << "Выберите 1-4!\n";
		}
	}
}

void CoutStudent(Student student) {
	cout << endl << endl << "Фамилия: " << student.surname << endl << "Группа: " << student.numberOfGroup << endl << "Математика: " << student.mat << endl << "Физика: " << student.phis << endl << "Информатика: " << student.inf << endl << "Химия: " << student.chem << endl << "Год рождения: " << student.born << endl << endl;
}

bool CheckStudent(short n) {
	if (n > sizeArrayStudents || n < 1) {
		cout << "Студента с таким номером не существует!!\n\n";
		return false;
	}
	return true;
}

void Solve() {
	double c;
	cout << "Введите минимальный средний балл: ";
	cin >> c;

	for (int i = 0; i < sizeArrayStudents; i++) {
		Student student = databaseStudents[i];
		if (student.srball >= c) {
			CoutStudent(student);
			fout << "Студенты чей средний балл выше " << c << endl;
			CoutStudentFail(student);
			
		}
	}
}

void ChangeSurname(short x) {
	cout << "Введите изменения:";
	cin >> databaseStudents[x].surname;
	cout << "Изменения сохранены!" << endl;
	UIMenu();
}

void ChangeNumberOfGroup(short x) {
	cout << "Введите изменения: ";
	cin >> databaseStudents[x].numberOfGroup;
	cout << "Изменения сохранены!" << endl;
	UIMenu();
}

void ChangeBurn(short x) {
	cout << "Введите изменения: ";
	cin >> databaseStudents[x].born;
	cout << "Изменения сохранены!" << endl;
	UIMenu();
}

void ChangePoints(short x) {
	cout << "Введите изменения: ";
	cin >> databaseStudents[x].mat >> databaseStudents[x].phis >> databaseStudents[x].inf >> databaseStudents[x].chem;
	CountSrBall(x);
	cout << "Изменения сохранены!" << endl;
	UIMenu();
}

void CountSrBall(short x) {
	databaseStudents[x].srball = (databaseStudents[x].mat + databaseStudents[x].phis + databaseStudents[x].inf + databaseStudents[x].chem) / 4;
}

void Delete() {
	short n;
	cout << "Введите номер студента; ";
	cin >> n;

	if (!CheckStudent(n)) {
		return;
	}

	DeleteStudentById(n);
}

void DeleteStudentById(short n) {
	sizeArrayStudents--;
	for (int i = n - 1; i < sizeArrayStudents; i++) {
		databaseStudents[i] = databaseStudents[i + 1];
	}
}

void Sort() {
	short n, m;
	cout << "Выберите по какому критерию вы хотите сортировать:\n1)Фамилии\n2)Среднему баллу\n";
	cin >> n;
	cout << "1) Возрастанию\n2) Убыванию\n\n";
	cin >> m;

	bool t = true;
	while (t == true) {
		switch (n) {
		case 1: QSortBySurname(0, sizeArrayStudents - 1); t = false; break;
		case 2: QSortBySrBall(0, sizeArrayStudents); t = false; break;
		default:
			cout << "Такого варианта нет!\n";
		}
	}

	if (m == 2) {
		m = sizeArrayStudents / 2;
		for (short i = 0; i < m; i++) {
			Student student = databaseStudents[i];
			int x = sizeArrayStudents - i - 1;
			databaseStudents[i] = databaseStudents[x];
			databaseStudents[x] = student;
		}
	}
}

void QSortBySurname(short b, short e) {
	short left = b, right = e;
	char piv[30];
	Student student = databaseStudents[(left + right) / 2];
	for (int i = 0; i < 30; i++)
		piv[i] = student.surname[i];

	while (left <= right)
	{
		while (CharacterComprasion(databaseStudents[left].surname, piv))
			left++;
		while (!CharacterComprasion(databaseStudents[right].surname, piv))
			right--;
		if (left <= right)
			swap(databaseStudents[left++], databaseStudents[right--]);
	}
	if (b < right)
		QSortBySurname(b, right);
	if (e > left)
		QSortBySurname(left, e);
}

bool CharacterComprasion(char a[], char b[]) {
	for (int i = 0; i < 30; i++)
		if (a[i] < b[i])
			return true;
	return false;
}

void QSortBySrBall(short b, short e) {
	short left = b, right = e;
	double piv = databaseStudents[(left + right) / 2].srball;

	while (left <= right)
	{
		while (databaseStudents[left].srball < piv)
			left++;
		while (databaseStudents[right].srball > piv)
			right--;
		if (left <= right)
			swap(databaseStudents[left++], databaseStudents[right--]);
	}
	if (b < right)
		QSortBySrBall(b, right);
	if (e > left)
		QSortBySrBall(left, e);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	UIMenu();
	

}