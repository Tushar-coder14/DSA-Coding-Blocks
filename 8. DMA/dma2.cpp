#include <iostream>
using namespace std;

int *createArray(int n){
    int *a = new int[n];
    for(int i = 0; i<n; i++){
        a[i] = (i+1)*5;
    }
    return a;
}

int main(){
    int n;
    cin>>n;
    int *arr = createArray(n);

    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    delete [] arr;
    arr = NULL;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}