#include <iostream>
#include <cstring>
using namespace std;

void ReadStr(char* text)
{
    cout << "vvedite stroku (konetc '.'):" << endl;
    int i = 0;
    cin >> text[i];
    while (text[i] != '.')
    {
        i++; cin >> text[i];
    }
    text[i] = '\0';
}

void NoWSread(char* text)
{
    cout << "vvedite stroku: " << endl;
    cin.ignore(255, '\n'); 
    cin.getline(text, 255); 
}

int find_substring1(const char* str_for_search_in, const char* substring, int start_position)
{
    int i = -1;
    int len1 = char_traits<char>::length(str_for_search_in);//strlen(str_for_search_in);
    int len2 = char_traits<char>::length(substring);
    for (int j = start_position; j <= len1 - len2; j++)
    {
        bool c = true;
        for (int i1 = 0; i1 < len2; i1++)
            if (str_for_search_in[i1 + j] != substring[i1]) 
            {
            	c = false;
            	break;
            }
        if ((c) && (i == -1)) 
        {
        	i = j;
        	return i;
        }
    }
    return i;
}

int* find_substring2(const char* str_for_search_in, const char* substring)
{

    int idx[255] = {-1} 
    int k = 0, i = 0;
    //for (int j = 0; j < 255; j++) idx[j] = -1;
    idx[k] = find_substring1(str_for_search_in, substring, i);
    while (idx[k]!= -1) {
    
     	i = idx[k] + 1;
     	k++;
        idx[k] = find_substring1(str_for_search_in, substring, i);
       
    }
    int* mas = new int[k];
    for (int j = 0; j < k; j++) mas[j] = idx[j];

    return mas;
}

bool Palindrom(char* str)
{
    int i = strlen(str);
    for (int j = 0; j < i - 1; j++) str[j] = tolower(str[j]);
    bool b = true;
    for (int j = 0; j < (i - 1) / 2; j++) {
        if (str[j] != str[i - j - 1])
            b = false;
    }
    return b;
}

void encrypt(char* str_for_encrypt, int key)
{
    int N = char_traits<char>::length(str_for_encrypt);
    for (int j = 0; j < N; j++) {
        if ((int(str_for_encrypt[j]) >= 65) && (int(str_for_encrypt[j]) <= 90)) {
            int c = int(str_for_encrypt[j]) + key;
            if (c > 90) c -= 26;
            str_for_encrypt[j] = char(c);
        }
        if ((int(str_for_encrypt[j]) >= 97) && (int(str_for_encrypt[j]) <= 122)) {
            int c = int(str_for_encrypt[j]) + key;
            if (c > 122) c -= 26;
            str_for_encrypt[j] = char(c);
        }
    }
}

int main()
{
    
    bool a = true;
    while (a) {
        int x;
        cout << "1.palindrom\n"
                "2.poisk podstroki\n"
                "3.shifr\n"
                "4.kavichki\n"
                "5.exit\n";
        cin >> x;
        switch (x) {
        case 1:
        {
            char _text[255];
            ReadStr(_text);
            if (Palindrom(_text)) cout << "palindrom\n";
            else cout << "not palindrom\n";
            break;
        }
        case 2:
        {
            char _str_for_search_in[255];
            NoWSread(_str_for_search_in);
            char _substring[255];
            cout << "podstroka: " << endl;
            cin.getline(_substring, 255);
            int _start_position = 0;
            cout << find_substring1(_str_for_search_in, _substring, _start_position) << endl;
            //массив при попадании из функции засоряется мусором; далее - обработка для вывода без мусора
            int* mas = find_substring2(_str_for_search_in, _substring);
            if (find_substring1(_str_for_search_in, _substring, _start_position) == -1) mas[0] = -1;
            int i = 0;
            cout << "[";
            cout << mas[i++];
            while (mas[i] > 0) cout << "," << mas[i++];
            cout << "]" << endl;
            break;
        }
        case 3:
        {
            char _str_for_encrypt[255];
            cout << "vvedite stroku  (konets '.'):" << endl;
            NoWSread(_str_for_encrypt);
            int _key;
            cout << "shaf [1-25]:" << endl;
            cin >> _key;
            encrypt(_str_for_encrypt, _key);
            cout << _str_for_encrypt << endl;
            break;
        }
        case 4:
        {
            char str[255];
            NoWSread(str);
            int isName = -1;
            int N = char_traits<char>::length(str);
            for (int i = 0; i < N; i++) {
                if (str[i] == '"') {
                    isName *= -1;
                    if (isName == -1) cout << '|';
                }
                else {
                    if (isName == 1) cout << str[i];
                }
            }
            cout << endl;
            break;
        }
        case 5:
        {
            a = false;
            break;
        }
        }
    }
}
