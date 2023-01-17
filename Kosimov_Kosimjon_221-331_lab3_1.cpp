
#include <iostream>
using namespace std;
void bubble_sort(double *mas, int l) {
    double zam;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < (l - i - 1); j++) {
            if (mas[j] > mas[j + 1]) {
            zam = mas[j];
            mas[j] = mas[j + 1];
            mas[j + 1] = zam;
            }
        }
    }
}
void counting_sort(char* mas, int l) {
    int rm = 26;
    int coun[26] = { 0 };
    int j;
    for (int i = 0; i < l; i++) {
        j = int(mas[i] -'a');
        coun[j]++;
    }
    int i = 0;
    j = 0;
    while (j < rm) {
        if (coun[j] > 0){
        mas[i] = char(int('a') + j);
        i++;
        coun[j]--;
    }
    else {
        j++;
}
}

}

void merge(int *, int, int, int);
void merge_sort(int* arr, int low, int high)
{
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

void merge(int* arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
    }
    else {
        c[k] = arr[j];
        k++;
        j++;
    }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
    }

void task1() {
    double mas[1000];
    int l;
    double zam;

    cout << "Enter a length of massiv:";
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> mas[i];
    }
    bubble_sort(mas, l);
    for (int i = 0; i < l; i++) {
        cout << mas[i]<<" ";
    }
    cout << '\n';
}

void task2() {
    char mas[1000] = {0};
    int l;
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
    cout << "Enter a length of massiv:";
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> mas[i];
    }
    counting_sort(mas, l);
    for (int i = 0; i < l; i++) {
        cout << mas[i]<<" ";
    }
    cout << '\n';
} 

void task3() {
    int mas[1000] = {0};
    int l;

    cout << "Enter a length of massiv:";
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> mas[i];
    }
    merge_sort(mas, 0, l-1);
    for (int i = 0; i < l; i++) {
        cout << mas[i]<<" ";
    }
    cout << '\n';
}

int main() {

while (true) {
    
    cout << "Please, celect an action:" << endl;
    cout << "1.  bubble sort" << endl;
    cout << "2.  counting sort" << endl;
    cout << "3.  merge sort" << endl;
    cout << "lyuboe chislo dlya vixoda" << endl;

    int vibor;
    cin >> vibor;
    switch (vibor) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();

        break;
    default:
    cout<< "vixod"<< endl;
    return 0;
}
}

}

