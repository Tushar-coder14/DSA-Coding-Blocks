#include <iostream>
using namespace std;

int main(){
    int a[]  = {0,1,2,3,4};
    int n = sizeof(a)/sizeof(int);

//1st way:

    // int t_sum = (n*(n+1))/2;
    // int sum = 0;
    // for(int i=0 ; i<n ; i++){
    //     sum += a[i];
    // }
    // int missing = t_sum - sum;
    // cout<<missing;

//2nd way:
int ans = 0;
for(int i=0 ; i<n ; i++){
    ans ^= a[i];
}
for(int i=0 ; i<=n ; i++){
    ans ^= i;
}
cout<<ans<<endl;

    return 0;
}