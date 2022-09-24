#include <iostream>
using namespace std;

//1. Array Sum (using Address):
// int arraySum(int a[], int n){
//     //Base case:
//     if(n==0){
//         return 0;
//     }


//     //Recursive Case:
//     return a[0] + arraySum(a+1,n-1);


// }

//2. Array Sum (using Iterator):
int arraySum(int a[], int n, int i){
    //Base case:
    if(i==n){
        return 0;
    }


    //Recursive Case:
    return a[i] + arraySum(a,n,i+1);


}

int main(){
    int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(int);
    int ans = arraySum(a,n,0);
    cout<<ans;
    return 0;
}