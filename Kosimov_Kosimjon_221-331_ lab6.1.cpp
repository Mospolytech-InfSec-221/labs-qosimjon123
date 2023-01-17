#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() 
{
    stack<char> st;
    string line;
    cout<< "text: ";
    getline(cin,line);
    for (char i : line){
        if (i=='(' or i=='[' or i=='{'){
            st.push(i);
            }
        if (i==')'){
            if (st.top()=='('){
                st.pop();
                }
            else{
                cout<<"skobki vvedeni nepravilno";
                return false;
                }
                
            }
        if (i==']'){
            if (st.top()=='['){
                st.pop();
                }
            else{
                  cout<<"skobki vvedeni nepravilno";
                return false;
                }
                
            }
        if (i=='}'){
            if (st.top()=='{'){
                st.pop();
                }
             else{
                cout<<"skobki vvedeni nepravilno";
                return false;
                }
                 
            }
    }
    if (st.empty()){
        cout<< "Yes";
        }
    else{
        cout<< "No";
        }
    
}
