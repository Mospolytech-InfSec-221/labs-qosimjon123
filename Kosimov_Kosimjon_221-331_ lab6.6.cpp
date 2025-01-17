#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;


int main()
{
    map <string,string> group;
    list <string> data;
    string line;

    cout << "Student: ";
    getline(cin, line);// add first student
    while (line != ".") {
        if (group.find(line.substr(0, line.find(' '))) != group.end()) { // if there is a student so continue
           
            auto num = ++find(data.begin(), data.end(), group[line.substr(0, line.find(' '))]);// we chek the list if there is no "." we add the next student
            data.insert(num, line);
            
            group[line.substr(0, line.find(' '))] = line;  // we read the string and change the last line in order of the groups num
        }
        else { 
            
            data.push_back(line);// we add student to the end of the list
            group.insert(pair<string, string>(line.substr(0, line.find(' ')), line));
        }

        cout << "Student: "; // add the next student
        getline(cin, line);
    }

    // print out our list
    
    for (auto i = data.begin(); i != data.end(); i++) { // read from the beginig to the end of the list
        cout << *i << '\n'; // print out all elements
    }
}
