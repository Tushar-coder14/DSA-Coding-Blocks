#include <iostream>
using namespace std;


int power(int x , int n){
    if(n==0){
    return 1;
    }

    int pow = x*power(x,n-1);
    return pow;
}
int main(){
    int ans = power(2,3);
    cout<<ans<<endl;
    }
