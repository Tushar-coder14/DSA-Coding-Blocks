#include <iostream>
using namespace std;

int NStairCase(int n){
    //Base Case:
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    //Recursive Case
    return NStairCase(n-1) + NStairCase(n-2)  + NStairCase(n-3);
}

int NStairCase2(int n, int k = 3){
    //Base Case:
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    //Recursive Case:
    int sum = 0;
    for(int i=1 ; i<=k ; i++){
        sum += NStairCase2(n-i , k);
    }
    return sum;

}

int main(){
    
    int n,k;
    cin>>n>>k;
    cout<<NStairCase(n)<<endl;
    cout<<NStairCase2(n,k)<<endl;
    return 0;
}