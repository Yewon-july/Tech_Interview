#include <iostream>
using namespace std;

int main() {
    int arr[] = {7, 4, 5, 1, 3};
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5-(i+1); j++){
            if(arr[j+1]<arr[j]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        for(int j=0; j<5; j++)
            cout << arr[j] << ' ';
        cout << '\n';
    }
    return 0;
}
