#include <iostream>
using namespace std;

int main() {
    int arr[] = {9, 6, 7, 3, 5};
    
    for(int i=0; i<4; i++){
        int small = i;
        for(int j=i+1; j<5; j++){
            if(arr[j]<arr[small]){
                small = j;
            }
        }
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
        for(int j=0; j<5; j++)
            cout << arr[j] << ' ';
        cout << '\n';
    }
    
    return 0;
}
