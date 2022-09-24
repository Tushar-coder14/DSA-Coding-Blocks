#include <iostream>
using namespace std;

//By Address:
int firstIndex7(int a[], int n){
    //Base Case:
    if(n==0){
        return -1;
    }

    //Recursive Case:
    if(a[0] == 7){
        return 0;
    }
    int ans = firstIndex7(a+1,n-1);
    if(ans == -1){
        return -1;
    }
    else{
        return ans+1;
    }
}

//By iterator:
int first7(int a[], int n, int i){
    //Base case:
    if(i==n){
        return -1;
    }

    //Recursive Case:
    if(a[i] == 7){
        return i;
    }
    return first7(a,n,i+1);
}

int main(){
    int a[] = {1,2,17,5,71,8};
    int n = sizeof(a)/sizeof(int);
    cout<<firstIndex7(a,n)<<endl;
    cout<<first7(a,n,0)<<endl;
    return 0;
}