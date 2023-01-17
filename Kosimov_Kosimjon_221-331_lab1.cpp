#include <iostream>
#include <bitset>
using namespace std;
int main(){
    cout << "Kosimov Kosimjon:   221-331" << endl;
    cout << "ZADACHA #2" << endl;
    int min_int, max_int;
    unsigned int max_unsignedint, min_insignedint;
    short shrt_min, shrt_max;
    unsigned short ushrt_min, ushrt_max;
    long min_long, max_long;
    long long lmin_long, lmax_long; 
    char min_char, max_char;
    bool min_bool, max_bool;
    min_int = -2147483648;  
    max_int = 2147483647; 
    max_unsignedint = 4294967295;
    min_insignedint = -4294967294;


    shrt_min = -32768;
    shrt_max = 32767;
    ushrt_min= 65535;
    ushrt_max=65535 ;
    min_long= -2147483648;
    max_long=2147483647;
    lmin_long= -9223372036854775808;
    lmax_long=9223372036854775807;
    min_char =-128;
    max_char = 127;
    min_bool = false;
    max_bool = true;
    cout << " min int = -2147483648,  max int= 2147483647, size of int = "  << sizeof(min_int, max_int)<<endl;
    cout << " max_unsignedint = 4294967295, min_insignedint = -4294967294, size of int = "  << sizeof(max_unsignedint, min_insignedint)<< endl;
    cout << " shrt_min = -32768, shrt_max = 32767, size of = "  << sizeof(shrt_min, shrt_max)<<endl;
    cout << " ushrt_min= 65535, ushrt_max=65535, sizeof = "  << sizeof(ushrt_min, ushrt_max)<< endl;
    cout << " min_long= -2147483648, max_long=2147483647, sizeof = "  << sizeof(min_long, max_long)<< endl;
    cout << " lmin_long= -9223372036854775808, lmax_long=9223372036854775807, sizeof = "  << sizeof(lmin_long, lmax_long)<< endl;
    cout << "  min_char =-128, max_char = 127, sizeof  = "  << sizeof(min_char, max_char)<< endl;
    cout << "  min_bool = false, max_bool = true, sizeof = "  << sizeof(min_bool, max_bool)<< endl;
    
    cout << "ZADACHA #3" << endl;
    int num;
    cout << "vvedite chislo "; cin >> num;
    cout << "v binarnom vide " << bitset<16>(num)<< endl;
    cout << "v 16-richnom vide " << hex<<num<< endl;
    if (num >=0 )
        cout <<"bool 1"<< endl;
    else cout <<"bool 0"<< endl;
    cout << "double "<<double(num) <<endl; 
    cout << "char " << char(num)<< endl;
    
    cout << "ZADACHA #4" << endl;
    int a,b;
    cout << "a = "; cin>>a; 
    cout << "b = "; cin>>b;
    cout << a << " * x = "<< b <<endl;
    cout << "x = "<<a<<" / "<<b<<endl;
    cout <<"x = "<<double(b)/double(a)<<endl;
    cout << "Otvet = "<<double(b)/double(a)<<endl; 
    
    cout << "ZADACHA #5" << endl;
    int c,d;
    cout << "nachalo koordinati = "; cin>> c;
    cout << "konets koordinati = "; cin>> d;
    cout << "seredina koordinati = " << double((c+d))/2<< endl; 
      
}