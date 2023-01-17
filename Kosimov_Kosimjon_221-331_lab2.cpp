#include <iostream>
using namespace std;
int fac(int a ){
    int f=1;
    while(1<=a){
        f*=a;
        a--;
        }
    return f;
}
void z1 ()
{   cout <<"zadacha #1"<< endl;
    int a;
    cout << "vvedite chislo:  "; cin>>a;
    for (int i=0; i<=a; i++){
         for (int j=0;j<=i ; j++){
            cout <<j;
        }
        cout<<endl;
    }
}
void z2()
{   
    int n , k=0;
    cin>>n;
    while(k<=n){
        double c; //djelatelno vvodite do 10
        c=(fac(n))/(fac(k)*fac((n-k)));
        k++;
        cout << c << endl;
        
        }
}
void z3(){
    double chi, bn=0 ;
    int scho = 0 ;
    while (true){
        cin >> chi ;
        if (chi == 0){
            break;
            }
        else{    
        bn+=chi;
        scho++;
        }
    }
    cout << bn/scho<< endl;
    
}
int main (){
    int c;
    while (true) {
        cout << "viberite zadachu ot 1-3 i lyubuyu tcifru dlya vixoda"<< endl;
        cin >> c; 
        switch (c)
        {
        case 1:
            z1();
            break;
        case 2:
            z2();
            break;
        case 3:
            z3();
            break;
        
        default:
            cout <<"Good bye!"<<endl;
            return 0;
        } 
        

    }



}
