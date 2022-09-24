#include <iostream>
using namespace std;

bool check7(int a[], int n){
    //Base case:
    if(n==0){
        return false;
    }

    //Recursive Case:
    if(a[0] == 7){
        return true;
    }
    return check7(a+1,n-1);
}

int main(){
    int a[] = {1,2,7,5,7,8};
    int n = sizeof(a)/sizeof(int);
    if(check7(a,n)){
        cout<<"7 is present"<<endl;
    }
    else{
        cout<<"7 is not present"<<endl;
    }
    return 0;
}