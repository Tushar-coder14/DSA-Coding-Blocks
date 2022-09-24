#include <iostream>
using namespace std;

int *createArray(int n){
    int *a = new int[n];
    for(int i=0 ; i<n ; i++){
        a[i] = i*i;
    }
    return a;
}

int main(){
    int *a = new int;
    *a = 10;
    cout<<*a<<endl;

    float *f = new float;
    *f = 11.23;
    cout<<*f<<endl;

    float *f1 = new float(11.23);
    cout<<*f1<<endl;


////////CREATE ARRAY///////////
/*
    int n;
    cin>>n;
    int *arr = new int[n];

    for(int i=0 ; i<n ; i++){
        arr[i]= i+1;
    }

    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    */

   int *arr = createArray(10);
   for(int i=0 ; i<10 ; i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;

   int *x = new int;
   *x = 20;
   cout<<*x + 20<<endl;

   delete x;
   cout<<*x<<endl;
   x = NULL;

   if(*x>0){
    cout<<"Take left"<<endl;
   }
   else{
    cout<<"Take Right"<<endl;
   }

   cout<<*x<<endl;

    return 0;
}