#include <iostream>

using namespace std;



struct Stack {
    double root;
    Stack* next;

    Stack() {
        next = NULL;
    }
};

void UIMenu(Stack* stack);
bool IsEmpty(Stack* stack);

Stack* Push(Stack* stack, double c) {
    Stack* st = new Stack();
    st->root = c;
    st->next = stack;
    return st;
}


void ShowStack(Stack* stack) {
    Stack* st = stack;
    while (st->next != NULL) {
        cout << st->root << " ";
        st = st->next;
    }
}


double Show(Stack* stack, int k) {
    Stack* st = stack;
    for (int i = 0; i < k; i++)
    {
        st = st->next;
    } 
    if (!IsEmpty(stack)) { return st->root; }
    else {return 0;}
}


double Top(Stack* stack) {

    Stack* st = stack;

    if (st->next == NULL) {
        return 0;
    }
 
    else {
        return st->root;
    }

}


void DeleteAll(Stack** stack) {
    Stack* st;
    while (*stack != NULL) {
        st = *stack;
        *stack = (*stack)->next;
        delete st;
    }
}


double f(double x) {

    return  x * x - 10 * pow(sin(x), 2) + 2;
}

bool IsEmpty(Stack* stack) {

    Stack* st = stack;
    if (st->next == NULL) { return true; }
    else { return false; }
    
}


void CheckEmpty(Stack* stack) {

    if (IsEmpty(stack)) { cout << "\nДля начала нужно подсчитать корни!\n"; UIMenu(stack); }

}


void SpreadSheet(Stack* stack) {
    double a = 0, b = 0;

    cout << "Введите пределы подсчета. \nA = ";
    cin >> a;
    cout << "\nB = ";
    cin >> b;

    if (a > b) { double par; par = a; a = b; b = par; }
    cout << "\t\tТаблица значений\n";
    cout << "\tX\t\t\t\tF(X)\n";
    for ( a ; a <= b; a++)
    {
        cout <<"\t" << a << "\t\t\t\t" << f(a) << "\n";
    }
    cout << "\n\n\n";

    UIMenu(stack);
}


void findRoot(Stack** stack, double a, double b, double epsilon) {
    double answer = 0, d_l = a, d_r = b;
    
    while (fabs(d_r - d_l) > epsilon) {

        d_l = d_r - (d_r - d_l) * f(d_r) / (f(d_r) - f(d_l));

        d_r = d_l - (d_l - d_r) * f(d_l) / (f(d_l) - f(d_r));

        answer = d_r;


    }

    *stack = Push(*stack, answer);

    d_l = Top(*stack) + 1.5;
    d_r = d_r + 3;

    if (d_l <= d_r && d_r <= 4 ) { findRoot(stack, d_l, d_r, epsilon); } 
    else { UIMenu(*stack); }
    
}


void TableRoot(Stack* stack) {
    Stack* st = stack;
    int i = 0;

    CheckEmpty(stack);

    cout << "\tX\t\t\t\tF(X)\n";

    while (st->next != NULL) {
        
        st = st->next;
        cout << "\t" << Show(stack, i) << "\t\t\t" << f(Show(stack, i)) << "\n\n\n";
        i++;

    }
    UIMenu(stack);
}


void MaxDelta(Stack* stack) {

    CheckEmpty(stack);

    cout << "Введите точку\n";
    int m;
    cin >> m;

    while (IsEmpty(stack) == false) {
        int i = 0;
        if (fabs(m - Show(stack, i)) < fabs(m - Show(stack, i + 1))) {
            cout << "X = " << Show(stack, i) << "\n";
            UIMenu(stack);
        }
        i++;
    }

   
}
   
void ShowRootInString(Stack* stack) {

    int i = 1;
    while (!IsEmpty(stack)) {
        
        cout << "X(" << i << ") = " << Show(stack, i - 1) << "\n";
        i++;
    }
    UIMenu(stack);
}


void SearchRoot(Stack* stack) {
    if (!IsEmpty(stack)) { DeleteAll(&stack); }
    double epsilon = 10E-4;
    double a = 0, b = 0, answer = 0;

    cout << "Использовано рекомендуемое выражение. \n\n";
    cout << "1) Использовать рекомендуемые пределы. \n2) Использовать свои пределы \n\n";
    short a2;
    cin >> a2;

    switch (a2) {

    case 1: a = -4, b = 4; break;

    case 2:
        cout << "Введите пределы. \nA = ";
        cin >> a;
        cout << "B = ";
        cin >> b;
        if (a > b) { double par; par = a; a = b; b = par; }
        break;
    }

    findRoot(&stack, a, b, epsilon);
    cout << endl;
    UIMenu(stack);
}


void UIMenu(Stack* stack) {
   
    cout << "\n1)Подсчитать корни уравнения \n2)Показать талицу значений функции \n3)Показать таблицу корней \n4)Показать корень с максимальным приближением\n5)Показать корни \n6)Завершить работу\n\n";
    short a3;
    cin >> a3;


    switch (a3) {

         case 1: SearchRoot(stack);

         case 2: SpreadSheet(stack);
    
         case 3: TableRoot(stack);
     
         case 4: MaxDelta(stack);

         case 5: ShowRootInString(stack);

         case 6: DeleteAll(&stack);

    }

}


int main()
{
    setlocale(LC_ALL, "Russian");
    Stack* stack = new Stack();
    UIMenu(stack);
}