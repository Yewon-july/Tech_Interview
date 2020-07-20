#include <iostream>
using namespace std;

int main() {
    int arr[] = {8, 5, 6, 2, 4};
    int i, j, key;
    for(i=1; i<5; i++){
        key = arr[i];
        for(j=i-1; j>=0 && arr[j]>key; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
        for(j=0; j<5; j++)
            cout << arr[j] << ' ';
        cout << '\n';
    }
    return 0;
}
