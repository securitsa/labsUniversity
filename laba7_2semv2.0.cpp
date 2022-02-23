#include <iostream>
#include <string>
#include <ctime>


using namespace std;

int const PRIME_SIZE = 10; // Использовано просто число;

short ChooseCategory();
string ShowCategory(short);
string ShowStage(bool);





class Repair // Класс, который содержит немного информации о staff.
{ 
public:
    Repair* next; // При возникновении коллизии элементы будут помещены в односвязный список.
    string data;  //Дата (ключ)
    string model; //Модель 
    short type;   //Группа изделий 1-Телевизоры 2-Телефоны 3-Ноутбуки 4-Компы 5-Аксесуары 6-Быт техника 7-Другоe
    bool state;   //Состояние 1-Ready 0-NeReady

    Repair()
    {
        this->next = NULL;
    }

    Repair(string data, string model, short type, bool state)
    {
        this->data = data;
        this->model = model;
        this->type = type;
        this->state = state;
        this->next = NULL;
    }

    ~Repair()
    {
        //cout << "Delete " << this->name << endl;
        if (this->next != NULL)
        {
            delete this->next;
        }
    }
};


//.........................................................................................................................


class HashTable // Хеш-таблица, представленная в виде массива элементов (которые в свою очередь представляют список).
{
    Repair* table[PRIME_SIZE];

    // Самая простоя хеш-функция. Считает сумму ASCII кодов, делит на константу и
    // получает остаток от деления.
    static int hash(string str)
    {
        int hashsum;

        hashsum = (str[0] + str[3]) % PRIME_SIZE;

        return hashsum;
    }

public:

    HashTable()
    {
        for (int i = 0; i < PRIME_SIZE; i++)
        {
            table[i] = NULL;
        }
    }

    ~HashTable()
    {
        //cout << "Delete table\n";
        for (int i = 0; i < PRIME_SIZE; i++)
        {
            delete table[i];
        }
    }

    // Вставляет элемент в таблицу
    void push(string data, string model, short type, bool state)
    {
        int hashNumber = hash(data);

        Repair* product = new Repair(data, model, type, state);
        Repair* place = table[hashNumber];

        if (place == NULL)
        {
            table[hashNumber] = product;
            return;
        }

        while (place->next != NULL)
        {
            place = place->next;
        }
        place->next = product;
     
      

    }


    // Получает элемент из таблицы по его дате;
    void FindByData()
    {
        string data;
        system("cls");
        cout << "Введите дату: ";
        cin >> data;
        system("cls");

        int hashNumber = hash(data);
        Repair* result = table[hashNumber];
        if (!result)
        {
            cout << "Заказ не найден" << endl;
        }

        while (result->data != data)
        {
            if (!result->next)
            {
                cout << "Заказ не найден" << endl;
            }

            result = result->next;

        }

            cout << "\nДата приёма заказа: " << result->data[0] << result->data[1] << "." << result->data[2] << result->data[3] << endl;
            cout << "Получен " << ShowCategory(result->type) << " модели " << result->model << endl;
            cout << "Статус заказа: " << ShowStage(result->state) << "\n\n";
        
    }


    void FindByName() {
        string name;
        cout << "Введите модель товара подлежащего ремонту: ";
        cin >> name;
        system("cls");

        Repair* result = table[0];
        
        for (int i = 0; i < 10; i++)
        {
            result = table[i];

            if (result && result->model == name ) {
                
                cout << "\nДата приёма заказа: " << result->data[0] << result->data[1] << "." << result->data[2] << result->data[3] << endl;
                cout << "Получен " << ShowCategory(result->type) << " модели " << result->model << endl;
                cout << "Статус заказа: " << ShowStage(result->state) << "\n\n";
            }

            while (1) {
                if (result && result->next != NULL && result->model == name) {

                    result = result->next;
                    cout << "\nДата приёма заказа: " << result->data[0] << result->data[1] << "." << result->data[2] << result->data[3] << endl;
                    cout << "Получен " << ShowCategory(result->type) << " модели " << result->model << endl;
                    cout << "Статус заказа: " << ShowStage(result->state) << "\n\n";
                }
                else {
                    break;
                }
            }
        }

    }


    void FindByType() {
        system("cls");
        short SType = ChooseCategory();
        system("cls");

        Repair* result = table[0];

        for (int i = 0; i < 10; i++)
        {
            result = table[i];

            if (result && result->type == SType) {

                cout << "\nДата приёма заказа: " << result->data[0] << result->data[1] << "." << result->data[2] << result->data[3] << endl;
                cout << "Получен " << ShowCategory(result->type) << " модели " << result->model << endl;
                cout << "Статус заказа: " << ShowStage(result->state) << "\n\n";
            }

            while (1) {
                if (result && result->next != NULL && result->type == SType) {

                    result = result->next;
                    cout << "\nДата приёма заказа: " << result->data[0] << result->data[1] << "." << result->data[2] << result->data[3] << endl;
                    cout << "Получен " << ShowCategory(result->type) << " модели " << result->model << endl;
                    cout << "Статус заказа: " << ShowStage(result->state) << "\n\n";
                }
                else {
                    break;
                }
            }
        }

    }

    void ShowReadySets() {

        system("cls");
        short s = 0;
        Repair* result = table[0];

        for (int i = 0; i < 10; i++)
        {
            result = table[i];

            if (result && result->state == 1) {

                cout << "\nДата приёма заказа: " << result->data[0] << result->data[1] << "." << result->data[2] << result->data[3] << endl;
                cout << "Получен " << ShowCategory(result->type) << " модели " << result->model << endl;
                cout << "Статус заказа: " << ShowStage(result->state) << "\n\n";
                s++;
            }
            

            while (1) {
                if (result && result->next != NULL && result->state == 1) {

                    result = result->next;
                    cout << "\nДата приёма заказа: " << result->data[0] << result->data[1] << "." << result->data[2] << result->data[3] << endl;
                    cout << "Получен " << ShowCategory(result->type) << " модели " << result->model << endl;
                    cout << "Статус заказа: " << ShowStage(result->state) << "\n\n";
                    s++;
                }
                else {
                    if (s == 0) { cout << "Не найдено готовых заказов(" << endl; } break;
                }
            }
        }

    }


    void EditState() {
        string Sdata;  
        string Smodel;
        short Stype;
        Repair* result = table[0];
        bool t = false;

        system("cls");
        cout << "Введите дату заказа: ";
        cin >> Sdata;
        system("cls");
        Stype = ChooseCategory();
        system("cls");
        cout << "Введите модель: ";
        cin >> Smodel;

        for (int i = 0; i < 10; i++)
        {

            result = table[i];
            if (result && result->data == Sdata && result->model == Smodel && result->type == Stype) {
                if (result->state == 1) {
                    result->state = 0; cout << "Состоянеие изменено!" << endl; ShowStage(result->state);
                }
                else { result->state = 1; cout << "Состоянеие изменено!" << endl; ShowStage(result->state); }
                t = true;
            }
        }
        if (!t) { cout << "Позиция не найдена!" << endl; }
    }


    void ShowByHash(int hashNumber) {

        Repair* result = table[hashNumber];
        
        if (result) {
            cout << "\nДата приёма заказа: " << result->data[0] << result->data[1] << "." << result->data[2] << result->data[3] << endl;
            cout << "Получен " << ShowCategory(result->type) << " модели " << result->model << endl;
            cout << "Статус заказа: " << ShowStage(result->state) << "\n\n";
            
        }

        while (1) {
            if (result && result->next != NULL) {

                result = result->next;
                cout << "\nДата приёма заказа: " << result->data[0] << result->data[1] << "." << result->data[2] << result->data[3] << endl;
                cout << "Получен " << ShowCategory(result->type) << " модели " << result->model << endl;
                cout << "Статус заказа: " << ShowStage(result->state) << "\n\n";
                
            }


            else { break; }


            
        }
       
    }
       
};

void UIMenu(HashTable&);
void CreateMenu(HashTable&);
void ShowAllProduct(HashTable&);



void Find(HashTable& newTable) {
    system("cls");
    cout << "1)Поск по дате\n2)Поиск по имени\n3)Поиск по модели\n";
    short x;
    cin >> x;
    switch (x) {
    case 1: newTable.FindByData(); UIMenu(newTable); break;
    case 2: newTable.FindByName(); UIMenu(newTable); break;
    case 3: newTable.FindByType(); UIMenu(newTable); break;
    }

}


void ShowAllProducts(HashTable& newTable) {

    for (int i = 0; i <= 9; i++)
    {
        newTable.ShowByHash(i);
    }
    UIMenu(newTable);
}


void UIMenu(HashTable& newTable) {
    cout << "\n1)Добавить заказ\n2)Показать все заказы\n3)Поиск товара\n4)Показать товары готовые к выдаче\n5)Изменить мтепень готовности" << endl;
    short a;
    cin >> a;
    switch (a) {
    case 1: CreateMenu(newTable);
    case 2: ShowAllProducts(newTable);
    case 3: Find(newTable);     
    case 4: newTable.ShowReadySets(); UIMenu(newTable);
    case 5: newTable.EditState(); UIMenu(newTable);
    }
}

    
 
string ShowStage(bool stage) {
    if (stage) {
        return "Готово к получению!";
    }

    else {
        return "В стадии ремонта";
    }
}


bool randomBool()
{
    return 0 + (rand() % (1 - 0 + 1)) == 1;
}


void CreateMenu(HashTable& newTable) {
string data, model;
short type;
bool state;
system("cls");
cout << "Введите дату приёма продукта:";
cin >> data;
data.erase(2, 1);
system("cls");
cout << "Выберете категорию:";
type = ChooseCategory();
system("cls");
cout << "Введите модель товара:";
cin >> model;
system("cls");
state = randomBool();

newTable.push(data, model, type, state);

UIMenu(newTable);

}
 

string ShowCategory(short numcat) {

    switch (numcat) {

    case 1: return "Телевизор"; break;

    case 2: return "Телефон"; break;

    case 3: return "Ноутбук"; break;

    case 4: return "Компьютер"; break;

    case 5: return "Аксессуар"; break;

    case 6: return "Прибор бытовой техники"; break;

    default: return "Другой прибор"; break;

    }

}


short ChooseCategory() {
    cout << "\n1-Телевизоры \n2-Телефоны \n3-Ноутбуки \n4-Компьютеры \n5-Аксесуары \n6-Быт техника \n7-Другоe\n";
    short x;
    cin >> x;
    return x;
}





int main()
{
    setlocale(LC_ALL, "Russian");
    
   
    HashTable newTable;
    UIMenu(newTable);
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);
 

    return 0;
}