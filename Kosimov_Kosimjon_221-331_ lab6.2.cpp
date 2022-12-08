#include <iostream>
#include <deque>
#include <string>
using namespace std;
void print (deque<char> res){
    for (char i: res){
        cout<< i<<" ";
        }
}

int main()
{
    deque <char> st;
    string str;
    cout<< "vvedite stroku:   ";
    getline(cin,str);
    for (char i : str){
        if (i!=' '){
            st.push_back(i);
            }
        }
    while(!st.empty()){
        if (st.size()==1){
            st.pop_front();
            break;
            }
        else if (st.front() == st.back()){
            st.pop_front();
            st.pop_back();
            }
        else {
            cout<< "ne polindrom"<<endl;
            return 0;
            }
        
        }
    cout << "polindrom";
}
