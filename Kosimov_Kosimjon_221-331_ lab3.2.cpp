#include <iostream>

using namespace std;

    void nach(int *&tarr,int &tsize ){
        
        cout <<"zadayte razmer massivu = ";
        cin >> tsize;
        tarr = new int[tsize];
        for (int i = 0; i <= tsize-1; i++ ){
            cout << "arr [" << i <<"]";
            cin >> tarr[i];
        } 
    
    }
    void vivod(int arr[], int size){
        for (int j = 0; j <= size-1; j++){
            cout << arr[j]<<", ";
            
        }
        cout << endl;
    }
    
    void puz(int arr[],int size){
        int temp; 
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    

                }
            }
        
        }
    
 }
    void puz1(int arr[],int size){
         puz(arr,size);
        if (arr[size-1]==arr[size-2]){
             int temp; 
            for (int i = 0; i < size - 1; i++) {
		    for (int j = 0; j < size - i - 1; j++) {
		        if (arr[j] < arr[j + 1]) {
		            
		            temp = arr[j];
		            arr[j] = arr[j + 1];
		            arr[j + 1] = temp;
		     
             
             }
            }
        }
        }
    }
        
        
         
    int sum_of_digits_of_number (int num)
    {
        
        int res = 0;
        while (num>0){
        res+=(num/10)%10 ;
        num=num/100;
        
        }
       
        
        
    
        
        return res;
        
    }
    
    void sum_of_digits(int arr[],int size)
  {
    
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sum_of_digits_of_number(arr[j]) > sum_of_digits_of_number(arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
  
  }
int main(){
   
    int* arr=nullptr;
    int size=0;
    while (true){
    int vib;
    cout << "viberite menu dlya vi[oda lyubuyu sifru = ";
    cin >> vib;
    
    switch (vib)
    {
    case 1:
        nach(arr,size);
        break;
    case 2:
        vivod(arr,size);
        break;
    case 3:
        puz1(arr, size) ;
        break;
    case 4:
        sum_of_digits( arr, size);
        break;
    
    default:
        return 0;
    }
    }
}
