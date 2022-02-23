#include <iostream>
#include <stack>

using namespace std;

template <typename S>
struct Stack {
    S number;
    Stack* next;

    Stack() {
        next = NULL;
        number = NULL;
    }
};

template <typename S>
Stack<S>* Push(Stack<S>* stack, S c) {
    Stack<S>* st = new Stack<S>();
    st->number = c;
    st->next = stack;
    return st;
}

template <class T>
void DeleteAll(T** stack) {
    T* st;
    while (*stack != NULL) {
        st = *stack;
        *stack = (*stack)->next;
        delete st;
    }
}

template<class T>
void ShowStack(T* stack) {
    while (stack->next != NULL) {
        cout << stack->number;
        stack = stack->next;
    }
}

template <typename S>
bool ProccessOperation(Stack<S>*& stack, char operation) {
    S right = stack->number; PopBack(stack);
    S left = stack->number; PopBack(stack);

    switch (operation) {
    case '+': stack = Push(stack, left + right); break;
    case '-': stack = Push(stack, left - right); break;
    case '*': stack = Push(stack, left * right); break;
    case '/':
        if (right == 0)
            return true;
        stack = Push(stack, left / right);
        break;
    }

    return false;
}

template <typename S>
void PopBack(Stack<S>*& stack) {
    Stack<S>* st = stack;
    stack = stack->next;
    delete st;
}

template <typename S>
bool IsEmpty(Stack<S>* stack) {
    return stack->next == NULL;
}


bool IsOperation(char c) {
    return c == '+' || c == '-' || c == '/' || c == '*';
}

short Priority(char c) {
    return c == '+' || c == '-' ? 1 : c == '*' || c == '/' ? 2 : -1;
}

bool IsDigit(char c) {
    return c >= '0' && c <= '9';
}

double GetNumberFromString(string s) {
    int answer = 0, stringSize = s.size();

    for (int i = 0; i < stringSize; i++)
        answer = answer * 10 + (s[i] - '0');

    return answer;
}

bool BracketSequence(char* C, int sizeC) {
    Stack<char>* stack = new Stack<char>();

    for (int i = 0; i < sizeC; ++i) {
        if (C[i] == ')') {
            if (stack->number != '(')
                return false;
            PopBack(stack);
        }
        else if (C[i] == '(') {
            stack = Push(stack, C[i]);
        }
    }

    return stack->number == NULL;
}

bool ValidCharacters(char c) {
    return IsOperation(c) || IsDigit(c) || c == '(' || c == ')' || c == '.';
}

bool CheckSymbols(char* C, int sizeC) {
    if (IsOperation(C[0]))
    {
        return false;
    }

    for (int i = 1; i < sizeC; ++i)
    {
        if ((IsOperation(C[i]) && IsOperation(C[i - 1])) ||
            !ValidCharacters(C[i]) ||
            (C[i] == ')' && (!IsDigit(C[i - 1]) && C[i - 1] != '(')) ||
            (C[i] == '(' && (!IsOperation(C[i - 1]))) ||
            (IsDigit(C[i]) && C[i - 1] == ')'))
        {
            return false;
        }
    }

    return true;
}

int main() {
   // short Ent = 1;
    setlocale(LC_ALL, "Russian");

    Stack<double>* stackDouble = new Stack<double>();
    Stack<char>* stackChar = new Stack<char>();

    double answer = 0;
    
    cout << "Использовано выражение по варианту\n";
    int sizeC;
   /* cin >> Ent
        if (Ent == 1) {*/
            char C[256] = { "(9.1+0.6*2.4)/(3.7-8.5)\0" };
           // sizeC = strlen(C);
      /*  }
        else {
            char C[256] = {};
            cout << "Введите выражение\n" << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(C, 255, '\n');
            sizeC = strlen(C);
        }
        */
        
            sizeC = strlen(C);
    if (!BracketSequence(C, sizeC))
    {
        cout << "Неправильная скобочная последовательность";
        return 0;
    }

    if (!CheckSymbols(C, sizeC))
    {
        cout << "Есть проблема с операциями или числами";
        return 0;
    }

    for (int i = 0; i < sizeC; ++i)
    {
        if (C[i] != ' ')
        {
            if (C[i] == '(')
            {
                stackChar = Push(stackChar, '(');
            }
            else if (C[i] == ')')
            {
                while (stackChar->number != '(')
                {
                    if (ProccessOperation(stackDouble, stackChar->number)) {
                        cout << "Ошибка внесения элемента в стек. Деление на 0 недопустимо";
                        return 0;
                    }
                    PopBack(stackChar);
                }
                PopBack(stackChar);
            }
            else if (IsOperation(C[i]))
            {
                char c = C[i];
                while (!IsEmpty(stackChar) && Priority(stackChar->number) >= Priority(c))
                {
                    if (ProccessOperation(stackDouble, stackChar->number)) {
                        cout << "Ошибка внесения элемента в стек. Деление на 0 недопустимо";
                        return 0;
                    }
                    PopBack(stackChar);
                }
                stackChar = Push(stackChar, c);
            }
            else
            {
                double number = 0;

                while (i < sizeC && IsDigit(C[i]))
                    number = number * 10 + (C[i++] - '0');

                if (C[i] == '.')
                {
                    i++;
                    double x = 10;
                    while (i < sizeC && IsDigit(C[i]))
                    {
                        number += (C[i++] - '0') / x;
                        x *= 10;
                    }
                }

                i--;

                stackDouble = Push(stackDouble, number);
            }
        }
    }

    while (!IsEmpty(stackChar))
    {
        if (ProccessOperation(stackDouble, stackChar->number)) {
            cout << "Низя на ноль делить";
            return 0;
        }
        PopBack(stackChar);
    }

    cout << stackDouble->number;
}