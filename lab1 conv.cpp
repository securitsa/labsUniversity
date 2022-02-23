#include<iostream> //подключение библиотеки ввода вывода данных
#include<math.h> // подключение библиотеки математических функций


using namespace std;

int main() {
bool t;
//string modul1;
double x=0, y=0, z=0, n=0, i=0, k=0, j=0;
cout<<"You want to enter the recommended data? x = 3.981e-2, y = -1.625e3, z = 0.512      P.S 1-Yes, 0-No"<<endl;

cin>>t;

if (t==1){               //Выбор
    x= 0.03981;
    y= -1625;            //Значение рек. пременных
    z= 0.512;
    i=pow(2,(-x));
    k=sqrt(x+sqrt(sqrt(abs(y))));       //Мат. действия
    j=pow(exp(x-(1./sin(z))),1./3);
    n=i*k*j;
    cout<<"Total "<<n<<endl;
    exit(0);
}
cout<<"Enter x:"<<endl;
cin>>x;    //ввод данных
if (cin.fail()) //проверка на коррект. ввод данных
    {

        cout<<"ERROR. Re-enter"<<endl; //сообщение об ошибке
        exit(0);
    }
cout<<"Your Enter:"<<x<<endl;
cout<<"Enter y:"<<endl;
cin>>y;
if (cin.fail(), abs(x)<=sqrt(sqrt(abs(y))), x<=0, sqrt(sqrt(abs(y)))>=0)
    {
        cout<<"ERROR. Re-enter"<<endl;
       exit(0);
    }
cout<<"Your Enter:"<<y<<endl;
cout<<"Enter z:"<<endl;
cin>>z;
if (cin.fail(), z==0 )
    {
        cout<<"ERROR. Re-enter"<<endl;
       exit(0);
    }
    cout<<"Your Enter:"<<z<<endl;
    i=pow(2,(-x));
    k=sqrt(x+sqrt(sqrt(abs(y))));       //Мат. действия
    j=pow(exp(x-(1./sin(z))),1./3);
    n=i*k*j;
    cout<<"Total "<<n<<endl; // вывод итогового значения
}


