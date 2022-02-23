#include <iostream>
#include <math.h>
using namespace std;

double gbr (const char* text){
double d;
cout<<text;
    while (!(cin>>d)|| cin.get() != '\n'){
        cin.clear();
        cout<<"return"<<endl;
        while (cin.get() != '\n');
    }
    return d;
    }

int main()
{
    double a, b, x, k, r, s, h, y, t, m;
    int n;
    int pog;

    while (pog=1){

   a= gbr("Input a \n");
    b= gbr("Input b \n");
     h= gbr("Input h \n");
      n= gbr("Input n \n");
                for(x = a; x<=b; x+=h)
                {
                    s = 0;
                        for(k=1; k<=n; k++)
                    {
                    m=k+1;
                    r=pow(-1, m)*pow(x*x, k)/(2*k*(2*k-1));
                    s+=r;
                    }
                    y=(-1)*log(sqrt(1+x*x))+x*atan(x);
                    t = fabs(y-s);
                cout<<"x= "<<x<<' '<<"S(x)= "<<s<<' '<<"Y(x)="<<y<<' '<<"t= "<<t<<' '<<endl;

                    }
       s=0;
       r=0;
        cout<<"Restart 1-Yes, 0-No"<<endl;
                    cin>>pog;
                    if(pog==0){break;}
    }


}




