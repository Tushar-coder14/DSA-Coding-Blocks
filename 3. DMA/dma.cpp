#include <iostream>
using namespace std;

int main(){
    int *a = new int;
    *a = 10;
    cout<<*a<<endl;

    float *f = new float;
    *f = 11.23;
    cout<<*f<<endl;


    float *f1 = new float(11.23);
    cout<<*f1<<endl;

    int n;
    cin>>n;
    int *arr = new int[n];

    for(int i=0 ; i<n ; i++){
        a[i]= i+1;
    }

    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}