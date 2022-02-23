#include<iostream> //подключение библиотеки ввода вывода данных
#include<math.h> // подключение библиотеки математических функций


using namespace std;

int main() {
double d, c, z, x, m, y, e=2.7182818284;
int r;

    cout<<"Input z"<<endl;
    cin>>z;
if (cin.fail()) //проверка на коррект. ввод данных
    {

        cout<<"ERROR. Re-enter"<<endl; //сообщение об ошибке
        exit(0);
    }
    cout<<"Your enter: "<<z<<endl;
    cout<<"Enter r"<<endl;
    cin>>r;
    if (cin.fail()) //проверка на коррект. ввод данных
    {

        cout<<"ERROR. Re-enter"<<endl; //сообщение об ошибке
        exit(0);
    }
    cout<<"Your enter: "<<r<<endl;
    cout<<"Enter c"<<endl;
    cin>>c;
    if (cin.fail()) //проверка на коррект. ввод данных
    {

        cout<<"ERROR. Re-enter"<<endl; //сообщение об ошибке
        exit(0);
    }
    cout<<"Your enter: "<<c<<endl;
    if (z<=1)
    {
            x=pow(z,2)+1;
    }
    else if(z>1)
    {
        x=1/(sqrt(z-1));
        if ((z-1)<0) {cout<<"ERROR"<<endl;}
    }
    cout<<"Choose mode: 1)2x 2)x*x 3)x/3 "<<endl;
 cin>>r;
 if (cin.fail()) //проверка на коррект. ввод данных
    {

        cout<<"ERROR. Re-enter"<<endl; //сообщение об ошибке
        exit(0);
    }
    if (x+1<=0)
        {
            cout<<"ERROR"<<endl;}
switch(r)
{
    default: r=0; break;
case 1: cout<<"y = " <<d*log(abs(x))+pow(e,x)+c*pow(sin(pow(2*x, 2)-1),3)/sqrt(x);break;
case 2: cout<<"y = " <<d*log(abs(x))+pow(e,x)+c*pow(sin(pow(x*x, 2)-1),3);break;
case 3: cout<<"y = " <<d*log(abs(x))+pow(e,x)+c*pow(sin(pow(x/3, 2)-1),3);break;
}
}


