#include <iostream>
using namespace std;

int main(){
    int a[] = {7,4,10,8,3,1};
    int n = sizeof(a) / sizeof(int);

    for(int i = 0; i<n ; i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min = j;
            }       
        }
        // swap(a[min],a[i]);
        // OR 
        int temp  = a[min];
        a[min] = a[i];
        a[i] = temp;
    }


    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}