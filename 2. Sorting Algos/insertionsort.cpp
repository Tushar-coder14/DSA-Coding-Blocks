#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    int a[] = {9, 8, 7, 5, 2, 1, 2, 3 };
    int n = sizeof(a)/sizeof(int);
    for(int i = 1 ; i<n ; i++){
        int j = i - 1;
        int temp = a[i];
        int pos = i;
        while(j>=0 && temp<a[j]){
            swap(a[pos],a[j]);
            j--;
            pos--;
            // temp = a[i-1];
        }
    }
    
    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}