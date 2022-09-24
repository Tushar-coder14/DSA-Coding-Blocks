#include<iostream>
using namespace std;

//1> Is Array Sorted (By addressing)
bool isSorted(int a[],int n){
    //base case
    if(n==0 || n==1){
        return true;
    }

    //Recursive Case
    // bool kyaChotaSortedHai = isSorted(a+1,n-1);
    // if(kyaChotaSortedHai == true and a[0]<=a[1]){
    //     return true;
    // }
    // else{
    //     return false;
    // }

    //OR
    bool kyaChotaSortedHai = isSorted(a,n-1);
    if(kyaChotaSortedHai == true and a[n-2]<=a[n-1]){
        return true;
    }
    return false;
}

// int main(){
//     int a[]= {1,4,5,8,9};
//     int n= sizeof(a)/sizeof(int);

//     if(isSorted(a,n)) {
//         cout<<"Sorted Hai"<<endl;
//     }
//     else{
//         cout<<"Sorted nhi hai"<<endl;
//     }
//     return 0;
// }


//2> Is Array Sorted (By iterator)
bool isSorted2(int *a,int n,int i){
    //base case
    if(i==n-1 || i==n){
        return true;
    }

//Recursive Case
    bool kyaChotaSortedHai = isSorted2(a,n,i+1);
    if(kyaChotaSortedHai == true and a[i]<=a[i+1]){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int a[]= {1,4,5,8,9};
    int n= sizeof(a)/sizeof(int);

    if(isSorted2(a,n,0)) {
        cout<<"Sorted Hai"<<endl;
    }
    else{
        cout<<"Sorted nhi hai"<<endl;
    }
    return 0;
}
