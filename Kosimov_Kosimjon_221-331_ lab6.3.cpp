#include <iostream>
#include <set>
#include <string>
using namespace std;
void print(set <string> str1){
     for (auto i: str1){
        cout<< i<<", ";
        }
    }
int main()
{
    set <string> strsum;
    string str;
   
    while (true){ 
    cout<< "vvedite akkaunt (dlya prosmotra akkaunt vvedite 'vixoda')  : ";
    getline (cin, str);
    if(str=="vixod"){
        print(strsum);
        return 0;
        }
    else if (strsum.find(str)!=strsum.end()){
        cout << "takoy element sushesvuet"<<endl;
        }
    else{
        strsum.insert(str);
        }
    }
   
}
